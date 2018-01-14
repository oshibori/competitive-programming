#define _GLIBCXX_DEBUG
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

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();

  int l = 0, r = min(n, m) + 1;
  while (r - l > 1) {
    int m = (l + r) / 2;
    set<string> A;
    for (int i = 0; i + m - 1 < s.size(); i++)
      A.insert(s.substr(i, m));
    bool f=false;
    for(int j=0;j+m-1<t.size();j++)
      if(A.count(t.substr(j,m))){
        f=true;
        break;
      }
    if(f)l=m;
    else r=m;
  }

  cout<<l<<endl;
  return 0;
}
