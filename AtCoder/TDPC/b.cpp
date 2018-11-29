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
int A, B;
int a[1010], b[1010];
int dp[1010][1010];
/*
int dfs(int x, int y) {
  pii &ret = dp[x][y];
  if (ret.fi >= 0)
    return ret;
  ret.fi = ret.se = 0;
  pii l=dfs(x+1,y),r=dfs(x,y+1);
  if((x+y)%2==(A+B)%2){

  }
  else{

  }
}
*/
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> A >> B;
  rep(i, 0, A) { cin >> a[i]; }
  rep(i, 0, B) { cin >> b[i]; }

  rep(i, 0, 1010) rep(j, 0, 1010) dp[i][j] = 0;
  rrep(i, 0, A) {
    dp[i][B] = ((i + B) % 2 == 0 ? dp[i + 1][B] + a[i] : dp[i + 1][B]);
  }
  rrep(j, 0, B) {
    dp[A][j] = ((j + A) % 2 == 0 ? dp[A][j + 1] + b[j] : dp[A][j + 1]);
  }

  rrep(i, 0, A) {
    rrep(j, 0, B) {
      if ((i + j) % 2 == 0) {
        dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j + 1] + b[j]);
      } else {
        dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]);
      }
      dump(i, j, dp[i][j]);
    }
  }
  cout << dp[0][0] << endl;

  return 0;
}
