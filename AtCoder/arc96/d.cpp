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

  int N, C;
  cin >> N >> C;
  vector<int> x(N + 2), v(N + 2);
  rep(i, 1, N + 1) { cin >> x[i] >> v[i]; }
  int ans = 0;

  vector<int> y(x), w(v);
  rep(i, 0, N + 1) { y[i] = C - y[i]; }
  rep(i, 1, N + 1) { v[i] += v[i - 1]; }
  rrep(i, 1, N + 1) { w[i] += w[i + 1]; }

  vector<int> fx(v), fy(w);
  rep(i, 1, N + 1) { fx[i] -= x[i]; }
  rrep(i, 1, N + 1) { fy[i] -= y[i]; }

  vector<int> gx(fx), gy(fy);
  rep(i, 1, N + 1) { chmax(gx[i], gx[i - 1]); }
  rrep(i, 1, N + 1) { chmax(gy[i], gy[i + 1]); }

  rrep(i, 1, N + 2) {
    int score = fy[i] - y[i] + gx[i - 1];
    chmax(ans, score);
  }

  rep(i, 0, N + 1) {
    int score = fx[i] - x[i] + gy[i + 1];
    chmax(ans, score);
  }

  cout << ans << endl;
  return 0;
}
