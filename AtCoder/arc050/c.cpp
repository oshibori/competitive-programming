#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
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
// const int MOD = (int)(1e9) + 7;
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
int MOD;
struct ModInt {
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
ostream &operator<<(ostream &os, const ModInt &m) { return os << m.x; }
istream &operator>>(istream &is, ModInt &m) {
  signed long long s;
  is >> s;
  m = ModInt(s);
  return is;
};
// pow(mint(2), 1000) のように
ModInt pow(ModInt a, unsigned long long k) {
  ModInt r = 1;
  while (k) {
    if (k & 1)
      r *= a;
    a *= a;
    k >>= 1;
  }
  return r;
}

int gcd(int x, int y) { return (y == 0 ? x : gcd(y, x % y)); }
// using Num = unsigned long long;
template <typename Num> struct Matrix {
  vector<vector<Num>> v, w;
  Matrix() {}
  Matrix(int n, int m) : v(n, vector<Num>(m, 0)) { assert(n > 0 and m > 0); }
  inline int height() const { return (int)v.size(); }
  inline int width() const { return (int)v[0].size(); }
  inline Num &at(int i, int j) {
    assert(0 <= i and i < height() and 0 <= j and j < width());
    return v[i][j];
  }
  inline const Num &at(int i, int j) const {
    assert(0 <= i and i < height() and 0 <= j and j < width());
    return v[i][j];
  }
  inline vector<Num> &operator[](int x) {
    assert(0 <= x and x < height());
    return v[x];
  }
  inline const vector<Num> &operator[](int x) const {
    assert(0 <= x and x < height());
    return v[x];
  }

  static Matrix identity(int n) {
    Matrix A(n, n);
    for (int i = 0; i < n; i++)
      A.at(i, i) = 1;
    return A;
  }
  inline static Matrix identity(const Matrix &A) {
    return identity(A.height());
  }
  Matrix &operator*=(const Matrix &B) {
    int n = height(), m = B.width(), p = B.height();
    assert(p == width());
    w.assign(n, vector<Num>(m, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        Num x = 0;
        for (int k = 0; k < p; k++)
          (x += (at(i, k)) * (B.at(k, j)));
        w[i][j] = x;
      }
    v.swap(w);
    return *this;
  }
};
template <typename Num>
Matrix<Num> operator^(const Matrix<Num> &m, long long exponent) {
  Matrix<Num> A = m, B = Matrix<Num>::identity(m);
  while (exponent) {
    if (exponent & 1)
      B *= A;
    A *= A;
    exponent >>= 1;
  }
  return B;
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

  int A, B, M;
  cin >> A >> B >> M;
  MOD = M;
  int D = gcd(A, B);
  dump(D);
  Matrix<ModInt> x(2, 2);
  x.at(0, 0) = 10;
  x.at(0, 1) = 1;
  x.at(1, 0) = 0;
  x.at(1, 1) = 1;
  Matrix<ModInt> y = x;
  y.at(0, 0) = modpow(10, D, M);
  x = x ^ (A - 1);
  y = y ^ (B / D - 1);
  Matrix<ModInt> a(2, 1);
  a.at(0, 0) = 1;
  a.at(1, 0) = 1;
  dump(x.v);
  dump(y.v);
  x *= a;
  y *= a;
  dump(x.v);
  dump(y.v);
  ModInt ret = x.at(0, 0) * y.at(0, 0);
  cout << ret << endl;

  return 0;
}
