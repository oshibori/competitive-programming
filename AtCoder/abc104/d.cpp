//#include <bits/stdc++.h>
// utility
#include <bitset>
#include <tuple>
#include <typeinfo>
// error handling
#include <cassert>
// string
#include <cctype>
#include <cstring>
#include <string>
// container
#include <array>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// algorithm
#include <algorithm>
// iterator
#include <iterator>
// math
#include <cmath>
#include <complex>
#include <numeric>
#include <random>
// i/o
#include <cstdio>
#include <iomanip>
#include <iostream>

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

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  string S;
  cin >> S;
  string abc = "ABC";

  vector<vector<mint>> dp(S.size() + 1, vector<mint>(4));

  int n = S.size();

  dp[n][3] = 1;

  rrep(i, 0, S.size()) {

    dp[i][3] = dp[i + 1][3] * (S[i] == '?' ? 3 : 1);

    rrep(j, 0, 3) {

      dp[i][j] = dp[i + 1][j] * (S[i] == '?' ? 3 : 1) +
                 dp[i + 1][j + 1] * (S[i] == abc[j] or S[i] == '?' ? 1 : 0);
    }
  }
  cout<<dp[0][0]<<endl;

  return 0;
}
