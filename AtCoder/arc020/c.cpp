#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

typedef __int128_t Int;
#define DBG 1
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)

#define int unsigned long long
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
std::ostream &operator<<(std::ostream &dest, __int128_t value) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}

__int128 parse(string &s) {
  __int128 ret = 0;
  for (int i = 0; i < s.length(); i++)
    if ('0' <= s[i] && s[i] <= '9')
      ret = 10 * ret + s[i] - '0';
  return ret;
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
//(a*b)%mod
long long modmul(long long a, long long b, long long mod) {
  long long x = 0, y = a % mod;
  while (b > 0) {
    if (b & 1)
      x = x + y % mod;
    y = y * 2 % mod;
    b >>= 1;
  }
  return x % mod;
}
long long modpow(long long base, long long exponent, long long mod) {
  long long res = 1;
  while (exponent > 0) {
    if (exponent & 1)
      res = (res * base) % mod;
    base = (base * base) % mod;
    exponent >>= 1;
  }
  return res;
}
long long extgcd(long long a, long long b, long long &x, long long &y) {
  long long g = a;
  x = 1;
  y = 0;
  if (b != 0) {
    g = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  }
  return g;
}
//オイラーのφ関数（Euler's totient function）
// nと互いに素な数[1,n]の個数
// http://mathtrain.jp/phi
int euler_totient(int n) {
  int ret = n;
  for (int x = 2; x * x <= n; x++) {
    if (n % x)
      continue;
    ret -= ret / x;
    while (n % x == 0)
      n /= x;
  }
  if (n != 1)
    ret -= ret / n;
  return ret;
}

long long modinv(long long x, long long m) {
  return modpow(x, (m == MOD ? m - 2 : euler_totient(m) - 1), m);
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  vector<int> a(N), L(N);
  rep(i, 0, N) { cin >> a[i] >> L[i]; }
  dump(a, L);
  int B;
  cin >> B;
  //  assert(is_prime(B));
  int x, y, s = 0, ans = 0;
  rep(i, 0, N) {
    x = a[N - 1 - i];
    y = to_string(a[N - 1 - i]).size();
    int doubling = 0;
    int cnt = 1;
    int aaa = 0;
    int l = L[N - 1 - i], ll = l;
    while (ll > 0) {
      if (ll & 1) {
        doubling = (doubling + x * modpow(10, y * aaa, B) % B);
        aaa += cnt;
      }
      ll >>= 1;
      x = (modpow(10, y * cnt, B) + 1) * x % B;
      cnt <<= 1;
    }

    (ans += (doubling * modpow(10, s, B)) % B) %= B;
    dump(ans);
    s += y * l;
  }

  cout << ans << endl;
  return 0;
}
