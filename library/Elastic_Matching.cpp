// EM algorithm
// 最小コスト弾性マッチング問題
// O(nm)
int elastic_maching(vector<vector<int>> c) {
  int n = c.size(), m = c[0].size();
  vector<vector<int>> dp(n, vector<int>(m, INF));
  dp[0][0] = c[0][0];
  for (int i = 1; i < n; i++)
    dp[i][0] = dp[i - 1][0] + c[i][0];
  for (int j = 1; j < m; j++)
    dp[0][j] = dp[0][j - 1] + c[0][j];

  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++)
      dp[i][j] =
          c[i][j] + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));

  return dp[n - 1][m - 1];
}
