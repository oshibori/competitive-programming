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
using pii = pair<int, int>;
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

  int N, X;
  cin >> N >> X;
  vector<int> T(N + 1);
  rep(i, 1, N + 1) { cin >> T[i]; }
  vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
  dp[1][0] = 0;
  dp[1][1] = X;

  rep(i, 1, N) {
    int j2 = upper_bound(all(T), T[i] + X) - T.begin();
    int j1 = j2 - 1;
    dump(j1, j2);
    rep(k, 0, i + 1) {
      //      chmax(dp[i][k], dp[i - 1][k]);
      //      if(k>=1)chmax(dp[i][k],dp[i][k-1]);
      if (j1 < N + 1)
        chmax(dp[j1][k + 1], dp[i][k] + min(X, T[j1] - T[i]));
      if (j2 < N + 1)
        chmax(dp[j2][k + 1], dp[i][k] + min(X, T[j2] - T[i]));
    }
    dump(i, dp[i]);
  }

  dump(dp);
  vector<int> ans(N + 1);
  rep(i, 1, N + 1) {
    rep(k, 1, i + 1) { chmax(ans[k], dp[i][k]); }
  }
  rep(i, 1, N + 1) cout << (ans[i] = max(ans[i], ans[i - 1])) << endl;

  return 0;
}
