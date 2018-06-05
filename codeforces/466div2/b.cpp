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

map<int, int> dp;
int N, K, A, B;
int dfs(int x) {
  dump(x);
  if (dp.count(x))
    return dp[x];

  if (x == 1)
    return dp[x] = 0;

  if (x % K == 0) {
    int y = x / K;
    return dp[x] = min(dfs(y) + B, dfs(y) + A * (x - y));
  } else {
    int y = x % K;
    int z = (x - y == 0);
    return dp[x] = dfs(x - (y - z)) + A * (y - z);
  }
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  cin >> N >> K >> A >> B;
  int X = N;

  if (K == 1) {
    cout << A * (N - 1) << endl;
    return 0;
  }

  cout << dfs(N) << endl;

  return 0;
}
