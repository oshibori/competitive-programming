#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
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

  int N, D;
  cin >> N >> D;
  // vector<vector<int>> c(D, vector<int>(N));
  static int c[400][3010];
  rep(i, 0, D) rep(j, 0, N) cin >> c[i][j];
  // vector<vector<vector<int>>> dp(D,
  //                               vector<vector<int>>(N, vector<int>(3, INF)));
  static int dp[400][3010][3];
  memset(dp, 0x3f, sizeof(dp));
  int mini = INF;
  rep(i, 0, N) {
    dp[0][i][0] = c[0][i];
    chmin(mini, c[0][i]);
  }

  rep(i, 1, D) {
    int x = INF;
    rep(j, 0, N) {
      chmin(dp[i][j][0], mini + c[i][j]);
      chmin(dp[i][j][1], dp[i - 1][j][0] + c[i][j] / 10 * 9);
      chmin(dp[i][j][2],
            min({dp[i - 1][j][1], dp[i - 1][j][2]}) + c[i][j] / 10 * 7);
      chmin(x,min({dp[i][j][0],dp[i][j][1],dp[i][j][2]}));
    }
    mini = x;
  }
  int ans = INF;
  rep(i, 0, N) rep(j, 0, 3) chmin(ans, dp[D - 1][i][j]);
  cout << ans << endl;
  return 0;
}
