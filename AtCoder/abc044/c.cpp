#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
//typedef __int128_t Int;
#define DBG 1
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define loop(n) rep(loop,(0),(n))
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(12);

  int N, A; cin >> N >> A;
  vector<int> x(N); rep(i, 0, N){ cin >> x[i]; }
  int C=2550;
  vector<vector<int>>dp(C,vector<int>(N+1));
  dp[0][0]=1;
  rep(i,0,N){
    rrep(j,x[i],C){
      rrep(k,1,N+1){

        dp[j][k]+=dp[j-x[i]][k-1];

      }
    }
  }
  int ans=0;
  rep(i,1,N+1){
    ans+=dp[A*i][i];
  }
  cout<<ans<<endl;

    return 0;
}
