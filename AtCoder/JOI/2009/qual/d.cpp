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
int M, N;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
bool inrange(int x, int y) { return 0 <= x and x < N and 0 <= y and y < M; }
int dfs(int x,int y,vector<vector<int>>&v,vector<vector<int>>&dp){
  if(!inrange(x,y)||v[x][y]==0)return 0;

  int ret=0;
  v[x][y]=0;
  rep(i,0,4){
    int X=x+dx[i],Y=y+dy[i];
    chmax(ret,dfs(X,Y,v,dp));
  }
  v[x][y]=1;
  return ret+1;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> M >> N;
  vector<vector<int>> v(N, vector<int>(M));
  vector<vector<int>> dp(N, vector<int>(M,-1));
  rep(i, 0, N) rep(j, 0, M) cin >> v[i][j];
  int ans = -1;
  rep(i, 0, N) rep(j, 0, M) {
    chmax(ans, dfs(i, j, v, dp));
  }
  cout << ans << endl;

  return 0;
}
