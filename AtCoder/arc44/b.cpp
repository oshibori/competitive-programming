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

  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  if (A[0] != 0) {

    cout << 0 << endl;
    return 0;
  }
  rep(i, 1, N) {
    if (A[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  int M = *max_element(all(A));
  vector<int> cnt(M + 2);
  rep(i, 0, N) cnt[A[i]]++;
  dump(cnt, N);
  int ans = 1;
  rep(i, 0, M + 1) {
    dump(cnt[i], cnt[i + 1]);
    (ans *= modpow(modpow(2, cnt[i]) - 1, cnt[i + 1])) %= MOD;
    dump(ans);
    (ans *= modpow(2, cnt[i] * (cnt[i] - 1) / 2)) %= MOD;
    dump(ans);
  }
  cout << ans << endl;

  return 0;
}
