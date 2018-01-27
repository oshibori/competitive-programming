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
template <int M> ostream &operator<<(ostream &os, const ModInt<M> &m) {
  return os << m.x;
}
template <int M> istream &operator>>(istream &is, ModInt<M> &m) {
  signed long long s;
  is >> s;
  m = ModInt<M>(s);
  return is;
};
template <int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
  ModInt<MOD> r = 1;
  while (k) {
    if (k & 1)
      r *= a;
    a *= a;
    k >>= 1;
  }
  return r;
}

using mint = ModInt<1000000007>;

// nCrで用いる
vector<mint> fact, factinv;
// nCrで用いる 予め計算しておく
void nCr_compute_factinv(int N) {
  N = min(N, mint::Mod - 1);
  fact.resize(N + 1);
  factinv.resize(N + 1);
  fact[0] = 1;
  rep(i, 1, N + 1) fact[i] = fact[i - 1] * i;
  factinv[N] = fact[N].inverse();
  for (int i = N; i >= 1; i--)
    factinv[i - 1] = factinv[i] * i;
}
mint nCr(int n, int r) {
  if (n >= mint::Mod)
    return nCr(n % mint::Mod, r % mint::Mod) *
           nCr(n / mint::Mod, r / mint::Mod);
  return r > n ? 0 : fact[n] * factinv[n - r] * factinv[r];
}

int bitcnt(int bit) {
  int ret = 0;
  while (bit != 0) {
    bit &= bit - 1;
    ret++;
  }
  return ret;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  int k;
  cin >> k;
  if(k==0){
    cout<<1<<endl;
    return 0;
  }
  else if(s=="1"){
    cout<<0<<endl;
    return 0;
  }

  int n = s.size();
  dump(n);
  nCr_compute_factinv(n);
  vector<mint> v(n + 1, 0);

  reverse(all(s));
  int x = count(all(s), '1');
  if (k >= 1) {
    rep(i, 0, s.size()) {
      if (s[i] == '0')
        continue;
      dump(i, x);

      v[x] += 1;
      x--;
      rep(j, 1, i + 1) v[x + j] += nCr(i, j);
      dump(v);
    }
  }

  k--;
  loop(k) {
    vector<mint> w(n + 1, 0);
    v[1] = 0;
    rep(i, 1, n + 1) w[bitcnt(i)] += v[i];
    swap(v, w);
  }
  cout << v[1] << endl;

  return 0;
}
