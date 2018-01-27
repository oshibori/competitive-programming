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
const int MOD = (int)(1e4) + 7;
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
  string s;
  cin >> s;
  vector<int> a(N + 1);
  map<char, int> m;
  m['J'] = 2;
  m['O'] = 1;
  m['I'] = 0;
  vector<vector<int>> dp(N + 1, vector<int>(8, 0));
  dp[0][1 << 2] = 1;
  rep(i, 1, N + 1) rep(j, 0, 8) {
    if (((1 << m[s[i - 1]]) & j) == 0) {
      continue;
    }
    rep(k, 0, 8) {
      if ((j & k) != 0)
        (dp[i][j] += dp[i - 1][k]) %= MOD;
    }
  }
  dump(dp);
  int ans = 0;
  rep(i, 0, 8)(ans += dp[N][i]) %= MOD;
  cout << ans << endl;

  return 0;
}
