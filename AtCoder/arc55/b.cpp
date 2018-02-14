#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
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

int N, K;
double dp[1111][1111][2];
double dfs(int n, int k, int ismax) {
  double &ret = dp[n][k][ismax];
  if (ret >= 0)
    return ret;
  if (n == N)
    return ret = ismax;

  ret = 0;
  double notmax = 1.0 * n / (n + 1) * dfs(n + 1, k, ismax);

  double yes = 0;
  if (k < K)
    yes = 1.0 / (n + 1) * dfs(n + 1, k + 1, 1);
  double no = 1.0 / (n + 1) * dfs(n + 1, k, 0);

  return ret = notmax + max(yes, no);
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  cin >> N >> K;
  rep(i, 0, N + 1) rep(j, 0, N + 1) rep(k, 0, 2) dp[i][j][k] = -1;
  cout << dfs(0, 0, 0) << endl;

  return 0;
}
