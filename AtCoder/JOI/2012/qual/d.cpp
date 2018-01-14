#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define DBG 0
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define loop(n) rep(loop, (0), (n))
#define all(c) begin(c), end(c)
const int INF =
    sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e4);
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

  const int R = 1, G = 2, B = 3, W = 0;
  int N, K;
  cin >> N >> K;
  vector<int> v(N + 1, 0);
  rep(i, 0, K) {
    int A, B;
    cin >> A >> B;
    v[A] = B;
  }

  if (DBG) {
    cout << endl;
    rep(i, 1, N + 1) cout << i << (i == N ? '\n' : ' ');
    rep(i, 1, N + 1) cout << v[i] << (i == N ? '\n' : ' ');
    cout << endl;
  }

  vector<vector<int>> dp(N + 1, vector<int>(4, W));
  if (v[1])
    dp[1][v[1]] = 1;
  else
    rep(i, 1, 4) dp[1][i] = 1;
  if (v[2]) {
    rep(i, 1, 4) dp[2][v[2]] += dp[1][i];
  } else {
    rep(c, 1, 4) rep(j, 1, 4) dp[2][c] += dp[1][j];
  }

  rep(i, 3, N + 1) {
    if (v[i]) {
      rep(j, 1, 4) {
        if (j != v[i])
          dp[i][v[i]] += dp[i - 1][j] + (dp[i - 1][v[i]] != 0) * dp[i - 2][j];
      }
      dp[i][v[i]] %= MOD;
    } else {
      rep(c, 1, 4) {
        rep(j, 1, 4) if (j != c) dp[i][c] +=
            dp[i - 1][j] + (dp[i - 1][c] != 0) * dp[i - 2][j];
        dp[i][c] %= MOD;
      }
    }
  }
  if (DBG) {
    cout << endl;
    rep(j, 1, 4) rep(i, 1, N + 1) cout << dp[i][j] << (i == N ? '\n' : ' ');
    cout << endl;
  }
  cout << (dp[N][1] + dp[N][2] + dp[N][3])%MOD << endl;

  return 0;
}
