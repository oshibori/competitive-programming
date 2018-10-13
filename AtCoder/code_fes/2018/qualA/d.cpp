#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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
#define fi first
#define se second
#define eb emplace_back
using pii = pair<int, int>;
// template<class T> ostream &operator<<(ostream &os,T &t){dump(t);return os;}
template <typename T, typename S>
istream &operator>>(istream &is, pair<T, S> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T> void printvv(const vector<vector<T>> &v) {
  cerr << endl;
  rep(i, 0, v.size()) rep(j, 0, v[i].size()) {
    if (typeid(v[i][j]) == typeid(INF) and v[i][j] == INF) {
      cerr << "INF";
    } else
      cerr << v[i][j];
    cerr << (j == v[i].size() - 1 ? '\n' : ' ');
  }
  cerr << endl;
}

#ifndef _DEBUG
#define printvv(...)
#endif
void YES(bool f) { cout << (f ? "YES" : "NO") << endl; }
void Yes(bool f) { cout << (f ? "Yes" : "No") << endl; }
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
long long modpow(long long base, long long exponent, long long mod = MOD) {
  long long res = 1;
  while (exponent > 0) {
    if (exponent & 1)
      res = res * base % mod;
    base = base * base % mod;
    exponent >>= 1;
  }
  return res;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int D, F, T, N;
  cin >> D >> F >> T >> N;
  vector<int> x(N + 1, 0), dp(N + 3, 0);
  rep(i, 1, N + 1) { cin >> x[i]; }
  x.eb(D);
  x.eb(INF);
  dp[0] = 1;
  dump(x);
  dump(dp);
  rep(i, 0, N + 1) {
    if (i > 0)
      (dp[i] += dp[i - 1]) %= MOD;

    int j = upper_bound(all(x), x[i] + F - T) - x.begin();
    int k = upper_bound(all(x), x[i] + F) - x.begin();
    int v = (dp[i] * modpow(2ll, j - i - 1)) % MOD;
    dump(i, j, k, v);
    dump(dp);
    (dp[j] += v) %= MOD;
    (dp[k] += -v + MOD) %= MOD;
    dump(dp);
    if (i == 0)
      dp[i] = 0;
  }
  dp[0]=1;
  int ans = 0;
  rep(i, 0, N + 1) {
    if (D - x[i] <= F) {
      int j = upper_bound(all(x), x[i] + F - T) - x.begin();
      if(x[j]==INF)j--;
      dump(i,j);
      (ans += dp[i] * modpow(2ll, j - i - 1)) %= MOD;
    }
  }
  cout << ans << endl;
  return 0;
}
