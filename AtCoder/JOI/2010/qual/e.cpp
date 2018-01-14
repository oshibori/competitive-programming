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

  int N, M;
  cin >> N >> M;
  vector<vector<vector<int>>> dp(N, vector<vector<int>>(M, vector<int>(4, 0)));
  rep(i, 2, N) dp[i][0][0b00] = 1;
  rep(i, 2, M) dp[0][i][0b11] = 1;

  dp[1][1][0b01] = 1;
  dp[1][1][0b10] = 1;

  rep(i, 1, N) rep(j, 1, M) {
    if (i == 1 and j == 1)
      continue;

    dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
    dp[i][j][1] = dp[i - 1][j][3];

    dp[i][j][2] = dp[i][j - 1][0];
    dp[i][j][3] = dp[i][j - 1][2] + dp[i][j - 1][3];
    rep(k, 0, 4) dp[i][j][k] %= (int)(1e5);

    dump(i, j, dp[i][j]);
  }

  cout << accumulate(all(dp[N - 1][M - 1]), 0ll) % (int)(1e5) << endl;

  return 0;
}
