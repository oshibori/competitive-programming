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

vector<int> D;
int dp[5][100010];
int dfs(int c = 0, int i = 0) {
  dump(c, i, D[i]);
  int &ret = dp[c][i];
  if (ret >= 0)
    return ret;
  if (c == 4)
    return ret = 1;

  auto x = lower_bound((i + 1) + all(D), D[i] * 2) - D.begin();
  dump(x);
  ret = 0;
  rep(j, x, D.size()) {
    dump(dfs(c + 1, j));
    (ret += dfs(c + 1, j)) %= MOD;
  }
  dump(ret);
  return ret;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  D.resize(N + 1);
  rep(i, 1, N + 1) { cin >> D[i]; }
  sort(all(D));
  dump(D);
  //  memset(dp, 0xff, sizeof(dp));
  //  cout << dfs(0, 0) << endl;

  map<int, int> m;
  rep(i, 0, N + 1) {
    int x = lower_bound(i + 1 + all(D), 2 * D[i]) - D.begin();
    m[x] = i;
    dump(i, x);
  }

  memset(dp, 0, sizeof(dp));
  rep(i, 1, N + 1) dp[1][i] = i;
  rep(i, 2, 5) rep(j, i, D.size()) {
    int x = upper_bound(D.begin(), D.begin() + j, D[j] / 2) - D.begin()-1;
    dump(i, j, x);
    dp[i][j] = dp[i - 1][x];
    (dp[i][j] += dp[i][j - 1])%=MOD;
  }

  cout << dp[4][N] << endl;

  return 0;
}
