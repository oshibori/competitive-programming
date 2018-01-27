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

  int N, M;
  cin >> N >> M;
  vector<int> p(1 + N);
  rep(i, 1, N + 1) { cin >> p[i]; }
  vector<int> c(M), e(M);
  rep(i, 0, M) { cin >> c[i] >> e[i]; }

  sort(1 + all(p), greater<int>());
  rep(i, 1, N + 1) p[i] += p[i - 1];
  dump(p);

  int X = (int)(N) + 1;
  vector<int> dp(X, INF);
  dp[0] = 0;
  rep(i, 0, M) rrep(j, 0, X) chmin(dp[j], dp[max(j - c[i], 0)] + e[i]);

  int ans = 0;
  rep(i, 0, X) { chmax(ans, p[min(i, N)] - dp[i]); }
  cout << ans << endl;
  dump(dp);

  return 0;
}
