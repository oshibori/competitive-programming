#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
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

  int n, m;
  cin >> n >> m;
  dump(n,m);
  string s, t;
  cin >> s >> t;
  dump(s);dump(t);
  vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
  rep(i, 1, n + 1) dp[i][0] = i;
  rep(i, 1, m + 1) dp[0][i] = i;
  rep(i, 1, n + 1) rep(j, 1, m + 1) dp[i][j] =
      min(dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]),
          min(dp[i - 1][j], dp[i][j - 1]) + 1);
  cout << dp[n][m] << endl;

  return 0;
}
