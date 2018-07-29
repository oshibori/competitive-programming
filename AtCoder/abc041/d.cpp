#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
// typedef __int128_t Int;
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
  cout << fixed << setprecision(12);

  int N, M;
  cin >> N >> M;
  vector<vector<int>> g(N, vector<int>(N));
  vector<int> x(M), y(M);
  rep(i, 0, M) {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
    g[x[i]][y[i]] = 1;
  }

  vector<int>dp((1<<N));
  dp[0]=1;
  rep(bits,1,(1<<N)){

    rep(i,0,N){
      if(not((bits>>i)&1))continue;

      bool f=false;
      rep(j,0,N){
        if((bits>>j)&1){
          f|=(g[j][i]);
        }
      }

      if(not f){
        dp[bits]+=dp[bits^(1<<i)];
      }
    }
  }

  cout<<dp.back()<<endl;

  return 0;
}
