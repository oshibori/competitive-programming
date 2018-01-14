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

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, w;
  cin >> n >> w;
  vector<pair<int, int>> item;
  item.push_back(make_pair(0, 0));
  rep(i, 0, n) {
    int v, w;
    cin >> w >> v;
    item.push_back(make_pair(v, w));
  }
  vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
  rep(i, 1, n + 1) {
    rep(j, 0, w + 1) {
      dp[i][j] = dp[i - 1][j];
      if (j - item[i].second >= 0) {
        dp[i][j] =
            max(dp[i - 1][j], dp[i - 1][j - item[i].second] + item[i].first);
      }
    }
  }
  cout << dp[n][w] << endl;

  return 0;
}
