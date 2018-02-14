#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
typedef __int128_t Int;
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

vector<string> s;
vector<vector<int>> dp;
bool inrange(int x, int y) { return 0 <= x and x < dp.size() and 0 <= y and y < dp[0].size(); }
int dx[] = {1, 0, 1}, dy[] = {0, 1, 1};
int dfs(int x, int y) {
  int &ret = dp[x][y];
  if (ret >= 0)
    return ret;
  ret = 0;
  rep(i, 0, 3) {
    int X = x + dx[i], Y = y + dy[i];
    if (inrange(X,Y) and s[X][Y] == '.' and dfs(X, Y) == 0) {
      return ret = 1;
    }
  }
  return ret;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int H, W;
  cin >> H >> W;
  s.resize(H);
  dp.resize(H, vector<int>(W, -1));
  rep(i, 0, H) { cin >> s[i]; }
  cout<<(dfs(0,0)?"First":"Second")<<endl;

  return 0;
}
