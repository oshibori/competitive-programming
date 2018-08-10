#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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

int calc(vector<int>&x,int sum,vector<vector<int>>&p){
  map<int,int>m;
  rep(i,0,x.size())m[x[i]]++;
  x.erase(unique(all(x)),x.end());

  vector<vector<int>>dp(x.size()+1,vector<int>(sum+1,0));
  dp[0][0]=1;
  rep(i,1,dp.size())rep(j,0,dp[0].size()){
    rep(k,0,j+1){
      dp[i][j]+=(dp[i-1][k]*p[m[x[i-1]]][j-k])%MOD;
      dp[i][j]%=MOD;
    }
  }
  return dp[x.size()][sum];
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  vector<int> killA(N);
  rep(i, 0, N) { cin >> killA[i]; }
  vector<int> killB(M);
  rep(i, 0, M) { cin >> killB[i]; }
  int sumKillA = accumulate(all(killA), 0ll);
  int sumKillB = accumulate(all(killB), 0ll);

  vector<vector<int>> p(101, vector<int>(1010, 0));
  p[0][0] = 1;
  rep(i, 1, p.size()) rep(j, 0, p[0].size()) {
    p[i][j] = p[i - 1][j];
    if (j - i >= 0)
      p[i][j] += p[i][j - i];
    p[i][j]%=MOD;
  }

  cout<<calc(killA,sumKillB,p)*calc(killB,sumKillA,p)%MOD<<endl;



  return 0;
}
