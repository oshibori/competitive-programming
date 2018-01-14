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
const int MOD = 1234567;
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
template <typename T> struct RangeAddQuery {
  int n;
  vector<T> d;
  RangeAddQuery(int m) {
    for (n = 1; n < m; n <<= 1)
      ;
    d.assign(2 * n, T(0));
  }
  // add x to [a,b),x>=0
  void add(int a, int b, T x = -1, int k = 1, int l = 0, int r = -1) {
    if (r == -1)
      r = n;

    if (r <= a || b <= l)
      return;
    else if (a <= l && r <= b) {
      if (x >= 0)
        (d[k] += (r - l) * x) %= MOD;
      return;
    } else {
      // d[ [l,r) ] += z が保てなくなるので、子に値を下す
      if (d[k] != 0) {
        (d[2 * k] += d[k] / 2) %= MOD;
        (d[2 * k + 1] += d[k] / 2) %= MOD;
        d[k] = 0;
      }
      add(a, b, x, 2 * k, l, (l + r) / 2);
      add(a, b, x, 2 * k + 1, (l + r) / 2, r);
    }
  }
  // 0-indexed
  T get(int i) {
    add(i, i + 1);
    return d[n + i];
  }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, P;
  cin >> N >> P;
  vector<int> k(N + 1);
  rep(i, 1, N + 1) { cin >> k[i]; }
  vector<int> dp(N + 1);
  dp[0] = 1;
  vector<int> acc(N+1);
  acc[0]=1;
  int sum = 0, l = 0;
  rep(i, 1, N + 1) {
    sum += k[i];
    while (sum > P)
      sum -= k[1 + l++];
    dp[i] = acc[i - 1] - (l == 0 ? 0 : acc[l - 1]);
    dp[i] %= MOD;
    acc[i]=acc[i-1]+dp[i];
  }
  cout << dp[N] << endl;

  return 0;
}
