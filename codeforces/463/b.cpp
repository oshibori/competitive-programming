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
int f(int n) {
  int ret = 1;
  while (n) {
    if (n % 10 != 0)
      ret *= n % 10;
    n /= 10;
  }
  return ret;
}
int memo[1010101];
const int N = 1010101;
int g(int n) {
  if (memo[n] != -1)
    return memo[n];
  if (n < 10) {
    return memo[n] = n;
  } else
    return memo[n] = g(f(n));
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int Q;
  cin >> Q;
  rep(i, 0, N) memo[i] = -1;
  rep(i, 1, N) g(i);
  vector<vector<int>> cnt(10, vector<int>(N));
  rep(i, 1, 10) rep(j, 1, N) cnt[i][j] = (memo[j] == i) + cnt[i][j - 1];
  loop(Q) {
    int l, r, k;
    cin >> l >> r >> k;
    cout << cnt[k][r] - cnt[k][l - 1] << endl;
  }

  return 0;
}
