#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
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
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
using pii = pair<int, int>;
// template<class T> ostream &operator<<(ostream &os,T &t){dump(t);return os;}
template <typename T, typename S>
istream &operator>>(istream &is, pair<T, S> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, pair<T, S> &p) {
  os << p.first << " " << p.second;
  return os;
}

template <typename T> void printvv(const vector<vector<T>> &v) {
  cerr << endl;
  rep(i, 0, v.size()) rep(j, 0, v[i].size()) {
    if (typeid(v[i][j]).name() == typeid(INF).name() and v[i][j] == INF) {
      cerr << "INF";
    } else
      cerr << v[i][j];
    cerr << (j == v[i].size() - 1 ? '\n' : ' ');
  }
  cerr << endl;
}
/*
   typedef __int128_t Int;
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
 */

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
template <int MOD> struct ModInt {
  static const int Mod = MOD;
  unsigned x;
  ModInt() : x(0) {}
  ModInt(signed sig) {
    int sigt = sig % MOD;
    if (sigt < 0)
      sigt += MOD;
    x = sigt;
  }
  ModInt(signed long long sig) {
    int sigt = sig % MOD;
    if (sigt < 0)
      sigt += MOD;
    x = sigt;
  }
  int get() const { return (int)x; }

  ModInt &operator+=(ModInt that) {
    if ((x += that.x) >= MOD)
      x -= MOD;
    return *this;
  }
  ModInt &operator-=(ModInt that) {
    if ((x += MOD - that.x) >= MOD)
      x -= MOD;
    return *this;
  }
  ModInt &operator*=(ModInt that) {
    x = (unsigned long long)x * that.x % MOD;
    return *this;
  }
  ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
  ModInt &operator++(int) { return (*this) += ModInt(1); }

  ModInt inverse() const {
    signed a = x, b = MOD, u = 1, v = 0;
    while (b) {
      signed t = a / b;
      a -= t * b;
      std::swap(a, b);
      u -= t * v;
      std::swap(u, v);
    }
    if (u < 0)
      u += MOD;
    ModInt res;
    res.x = (unsigned)u;
    return res;
  }
};
template <int MOD> ostream &operator<<(ostream &os, const ModInt<MOD> &m) {
  return os << m.x;
}
template <int MOD> istream &operator>>(istream &is, ModInt<MOD> &m) {
  signed long long s;
  is >> s;
  m = ModInt<MOD>(s);
  return is;
};
// pow(mint(2), 1000) のように
template <int MOD> ModInt<MOD> pow(ModInt<MOD> a, unsigned long long k) {
  ModInt<MOD> r = 1;
  while (k) {
    if (k & 1)
      r *= a;
    a *= a;
    k >>= 1;
  }
  return r;
}

//#define int long long を使っても大丈夫
using mint = ModInt<1000000007>;

int N, X, Y, Z;
vector<int> decode(int mask) {
  vector<int> d;
  int cnt = 1;
  while (mask) {
    if (mask & 1) {
      d.push_back(cnt);
      cnt = 1;
    } else
      cnt++;
    mask >>= 1;
  }
  d.eb(0);
  reverse(all(d));
  return d;
}
int encode(vector<int> d) {
  int ret = 0;
  for (int x : d) {
    ret <<= x;
    ret |= (1 << (x - 1));
  }
  return ret & ((1 << (X + Y + Z - 1)) - 1);
}
int dp[1 << 17][40];
int dfs(int mask = 0, int x = 0) {
  int p = mask & (1 << (Z - 1));
  int q = mask & (1 << (Z + Y - 1));
  int r = mask & (1 << (Z + Y + X - 1));
  if (!!p & !!q & !!r)
    return 0;

  if (x == N) {
    return 1;
  }
  if (dp[mask][x] != -1)
    return dp[mask][x];
  int ret = 0;
  rep(a, 1, 11) {
    int nmask = mask << a;
    nmask |= (1 << (a - 1));
    nmask &= (1 << (X + Y + Z)) - 1;
    (ret += dfs(nmask, x + 1)) %= MOD;
  }
  return dp[mask][x] = ret;
}
//高速累乗 繰り返し自乗法
//オーバーフローする可能性があれば掛け算にmodmul()を使う
long long modpow(long long base, long long exponent, long long mod) {
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

  cin >> N >> X >> Y >> Z;
  memset(dp, 0xff, sizeof(dp));
  mint all = modpow(10, N, MOD);
  mint aaa = dfs();
  cout << all - aaa << endl;

  return 0;
}
