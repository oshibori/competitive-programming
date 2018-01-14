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

  int D, N;
  cin >> D >> N;
  vector<int> T(D);
  rep(i, 0, D) { cin >> T[i]; }
  vector<int> a(N), b(N), c(N);
  rep(i, 0, N) cin >> a[i] >> b[i] >> c[i];

  vector<vector<int>> dp(D, vector<int>(N, -1));
  rep(i, 0, N) {
    if (a[i] <= T[0] and T[0] <= b[i])
      dp[0][i] = 0;
  }

  rep(i, 1, D) rep(j, 0, N) {
    if (!(a[j] <= T[i] and T[i] <= b[j]))
      continue;
    rep(k, 0, N) {
      if (dp[i - 1][k] == -1)
        continue;
      chmax(dp[i][j], dp[i - 1][k] + abs(c[k] - c[j]));
    }
  }

  cout << *max_element(all(dp[D-1])) << endl;

  return 0;
}
