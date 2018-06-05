#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
// typedef __int128_t Int;
#define DBG 1
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define loop(n) rep(loop, (0), (n))
#define all(c) begin(c), end(c)
const int INF =
    sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int H, W, D;
  cin >> H >> W >> D;
  vector<vector<int>> A(H, vector<int>(W));
  rep(i, 0, H) rep(j, 0, W) { cin >> A[i][j]; }
  int Q;
  cin >> Q;
  vector<int> L(Q), R(Q);
  rep(i, 0, Q) { cin >> L[i] >> R[i]; }
  map<int, pair<int, int>> mp;
  rep(i, 0, H) rep(j, 0, W) { mp[A[i][j]] = make_pair(i + 1, j + 1); }
  vector<int> check(H * W + 1);
  map<int, vector<int>> sum;
  int ans = 0;
  auto cal = [&](pair<int, int> &a, pair<int, int> &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
  };
  rep(d, 0, D) {
    if (check[d])
      continue;
    check[d] = 1;
    sum[d].push_back(0);

    int x = d;
    while (x + D <= H * W) {
      check[x] = 1;
      sum[d].push_back(cal(mp[x], mp[x + D]));
      x += D;
    }
  }

  for (auto &y : sum) {
    vector<int> &v(y.second);
    rep(i, 1, v.size()) v[i] += v[i - 1];
    dump(v);
  }

  rep(i, 0, Q) {
    int re = L[i] % D;
    dump(sum[re]);

    ans = sum[re][R[i] / D] - sum[re][L[i] / D];
    cout << ans << endl;
  }

  return 0;
}
