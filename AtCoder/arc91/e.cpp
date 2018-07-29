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

  int N, A, B;
  cin >> N >> A >> B;

  if (A + B - 1 <= N and A * B >= N) {
    if (B == 1) {
      rep(i, 0, N) { cout << i + 1 << (i + 1 == N ? '\n' : ' '); }
    } else {

      vector<int> v;
      v.push_back(A);
      int r = (N - A) % (B - 1);
      int q = (N - A) / (B - 1);
      loop(r) { v.push_back(q + 1); }
      loop(B - 1 - r) { v.push_back(q); }

      int m = N;
      vector<int> ans;
      rep(i, 0, v.size()) {
        rep(j, m - v[i], m) { ans.push_back(j); }
        m -= v[i];
      }

      rep(i, 0, ans.size()) {
        cout << ans[i]+1 << (ans.size() == i + 1 ? '\n' : ' ');
      }
    }
  } else {
    cout << -1 << endl;
  }

  return 0;
}
