// 最長共通部分列
// O(|s||t|)
string lcs(string s, string t) {
  enum Direction { HORIZONTAL, VERTICAL, DIAGONAL, END };
  int n = s.size(), m = t.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  vector<vector<Direction>> backtrace(n + 1, vector<Direction>(m + 1, END));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      dp[i + 1][j + 1] =
          max(dp[i][j] + (s[i] == t[j]), max(dp[i][j + 1], dp[i + 1][j]));
      if (dp[i + 1][j + 1] == dp[i][j + 1])
        backtrace[i + 1][j + 1] = VERTICAL;
      else if (dp[i + 1][j + 1] == dp[i + 1][j])
        backtrace[i + 1][j + 1] = HORIZONTAL;
      else
        backtrace[i + 1][j + 1] = DIAGONAL;
    }
  string r;
  int i = n, j = m;
  while (backtrace[i][j] != END) {
    if (backtrace[i][j] == DIAGONAL) {
      r.push_back(s[i - 1]);
      i--, j--;
    } else if (backtrace[i][j] == HORIZONTAL)
      j--;
    else
      i--;
  }
  reverse(all(r));
  return r;
  // return dp[n][m];
}


