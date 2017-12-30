// 最長共通部分列
// O(|s||t|)
int lcs(string s, string t) {
  int n = s.size(), m = t.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      dp[i + 1][j + 1] =
          max(dp[i][j] + (s[i] == t[j]), max(dp[i][j + 1], dp[i + 1][j]));
    }
  return dp[n][m];
}
