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

  int A, B;
  cin >> A >> B;
  vector<int> a(A);
  rep(i, 0, A) { cin >> a[i]; }
  vector<int> b(B);
  rep(i, 0, B) { cin >> b[i]; }

  vector<vector<int>> dp(A + 1, vector<int>(B + 1, 0));
  rep(i, 1, A + 1) {
    if (i & 1)
      dp[i][0] = dp[i - 1][0] + a[i - 1];
    else {
      dp[i][0] = dp[i - 1][0];
    }
  }
  rep(i, 1, B + 1) {
    if (i & 1)
      dp[0][i] = dp[0][i - 1] + b[i - 1];
    else
      dp[0][i] = dp[0][i - 1];
  }

  rep(i,1,A+1)rep(j,1,B+1){
    if((i+j)&1){
      chmax(dp[i][j],dp[i-1][j-1]+max(a[i-1],b[i-1]));
      chmax(dp[i][j],dp[i-1][j]+a[i-1]);
      chmax(dp[i][j],dp[i][j-1]+b[j-1]);
    }
    else {
      dp[i][j]=INF;
      chmin(dp[i][j],dp[i-1][j-1]+min(a[i-1],b[j-1]));
      chmin(dp[i][j],dp[i-1][j]);
      chmin(dp[i][j],dp[i][j-1]);
    }
  }

  cout<<dp[A][B]<<endl;

  return 0;
}
