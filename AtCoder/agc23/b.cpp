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

bool is_good(vector<string> &v) {
  int n = v.size();
  bool f(true);
  rep(i, 0, n) rep(j, i, n) f &= (v[i][j] == v[j][i]);
  return f;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  vector<string> v(N);
  rep(i, 0, N) { cin >> v[i]; }
  int ans = 0;
  rep(i, 0, N) {
    vector<string> w(v);
    rep(x, 0, N) rep(y, 0, N) w[x][y] = v[(x + i) % N][y];
    ans += is_good(w) * N;
  }
  cout << ans << endl;

  return 0;
}
