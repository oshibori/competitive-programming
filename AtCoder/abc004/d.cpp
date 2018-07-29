#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
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
vector<vector<int>> dp(2000, vector<int>(1000, -1));

int R, G, B;
int dfs(int index, int remain) {
  if (index + 1000 >= 2000)
    return INF;
  int &ret = dp[index + 1000][remain];
  if (ret != -1)
    return ret;
  if (remain == 0)
    return ret = 0;

  if (remain > G + B) {
    int x = abs(index - (-100)) + dfs(index + 1, remain - 1);
    int y = dfs(index + 1, remain);
    ret = min(x, y);
  } else if (remain > B) {
    int x = abs(index) + dfs(index + 1, remain - 1);
    int y = dfs(index + 1, remain);
    ret = min(x, y);
  } else {
    int x = abs(index - 100) + dfs(index + 1, remain - 1);
    int y = dfs(index + 1, remain);
    ret = min(x, y);
  }
  return ret;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  cin >> R >> G >> B;
  int ans = INF;
  chmin(ans, dfs(-1000, R + G + B));
  cout << ans << endl;

  return 0;
}
