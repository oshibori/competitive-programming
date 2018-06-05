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
// S以下の非負整数
void keta1() {
  // i桁目
  // S未満確定か
  int dp[20][2] = {};
  string S;
  cin >> S;
  dp[0][0] = 0;
  rep(i, 0, S.size()) rep(j, 0, 2) {
    if (i == 0 and j == 1)
      continue;
    int lim = j ? 9 : S[i] - '0';
    dump(lim);
    rep(d, 0, lim + 1) {
      //すでに未満確定||未満確定
      dump(i, j, d);
      dump(dp[i + 1][j || d != lim], d + dp[i][j]);
      chmax(dp[i + 1][j || d != lim], d + dp[i][j]);
    }
  }
  dump(dp);
  int ans = max(dp[S.size()][0], dp[S.size()][1]);
  cout << ans << endl;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);
  keta1();

  return 0;
}
