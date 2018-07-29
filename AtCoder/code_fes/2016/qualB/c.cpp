#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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
using pii = pair<int, int>;
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

  int W, H;
  cin >> W >> H;
  vector<int> p(W);
  rep(i, 0, W) { cin >> p[i]; }
  vector<int> q(H);
  rep(i, 0, H) { cin >> q[i]; }

  vector<pair<int, int>> v;
  rep(i, 0, W) { v.push_back(pii(p[i], 0)); }
  rep(i, 0, H) { v.push_back(pii(q[i], 1)); }
  sort(all(v));
  int w = 0, h = 0;
  int ans = 0;
  rep(i, 0, v.size()) {
    dump(v[i], W + 1 - w, H + 1 - h);
    if (v[i].second) {
      ans += v[i].first * (W + 1 - w);
      h++;
    } else {
      ans += v[i].first * (H + 1 - h);
      w++;
    }
  }
  cout << ans << endl;

  return 0;
}
