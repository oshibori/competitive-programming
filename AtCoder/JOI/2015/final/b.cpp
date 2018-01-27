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

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> v(N);
  rep(i, 0, N) { cin >> v[i]; }
  vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(2, 0)));
  // [0] -> joi, [1]->ioi
  rep(i, 0, N) dp[i][i][0] = v[i];
  rep(d, 1, N) {
    rep(i, 0, N) {
      int j = (i + d) % N;
      dp[i][j][0] =
          max(v[i] + dp[(i + 1) % N][j][1], v[j] + dp[i][(j - 1 + N) % N][1]);
      dp[i][j][1] =
          (v[i] > v[j] ? dp[(i + 1) % N][j][0] : dp[i][(j - 1 + N) % N][0]);
    }
  }
  int ans = 0;
  rep(i, 0, N) { chmax(ans, dp[i][(i + N - 1) % N][0]); }
  cout << ans << endl;

  return 0;
}
