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
int modpow(int base, int exp) {
  int ret = 1;
  while (exp) {
    if (exp & 1)
      (ret *= base) %= MOD;
    (base *= base) %= MOD;
    exp >>= 1;
  }
  return ret;
}
int inv(int a) { return modpow(a, MOD - 2); }
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  vector<int> f(N + K);
  f[0] = 1;
  rep(i, 1, f.size())(f[i] = i * f[i - 1]) %= MOD;

  if (N > K) {
    cout << ((f[N - 1 + K] * inv(f[K])) % MOD) * inv(f[N - 1]) % MOD << endl;
  }

  else {
    int large = K % N, small = N - large;
    cout << ((f[N] * inv(f[large])) % MOD) * inv(f[small]) % MOD << endl;
  }

  return 0;
}
