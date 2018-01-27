#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
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

int W, H;
bool inrange(int x, int y) {
  return 0 <= x and x < H + 3 and 0 <= y and y < W + 3;
}
int dx[][6] = {{1, 1, 0, -1, 0, 1}, {1, 0, -1, -1, -1, 0}};
int dy[6] = {0, -1, -1, 0, 1, 1};
void dfs(vector<vector<int>> &v, int a, int b) {
  if (v[a][b] == 2 or v[a][b] == 1)
    return;

  v[a][b] = 2;
  rep(i, 0, 6) {
    int x = a + dy[i], y = b + dx[!(a & 1)][i];
    if (inrange(x, y))
      dfs(v, x, y);
  }
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> W >> H;
  vector<vector<int>> v(H + 3, vector<int>(W + 3));
  rep(i, 1, H + 1) rep(j, 1, W + 1) cin >> v[i][j];
  dfs(v, 0, 0);
  if(DBG){
    cout<<endl;
    rep(i,0,v.size())rep(j,0,v[0].size())cout<<v[i][j]<<(j==v[0].size()-1?'\n':' ');
    cout<<endl;
  }
  int ans = 0;
  rep(i, 1, H + 1) rep(j, 1, W + 1) {
    if (v[i][j] != 1)
      continue;
    int cnt = 0;
    rep(k, 0, 6) {
      int x = i + dy[k], y = j + dx[!(i & 1)][k];
      if (inrange(x, y) and v[x][y] == 2)
        cnt++;
    }
    ans +=  cnt;
    dump(cnt);
  }
  cout << ans << endl;

  return 0;
}
