#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
// typedef __int128_t Int;
#define DBG 1
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define loop(n) rep(loop, (0), (n))
#define all(c) begin(c), end(c)
const int INF =
    sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = 998244353;
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
using mint = ModInt<MOD>;

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

mint nHr(int n, int r) { return r == 0 ? 1 : nCr(n + r - 1, r); }

mint f(int x, int y, int n) {
  mint ret = 0;
  int g = min(x, y);
  rep(i, 0, g + 1) {
    mint t =
        nCr(n, x - i) * nCr(n - (x - i), y - i) * nCr(n - (x - i) - (y - i), i);
    ret += t;
  }
  return ret;
}
int gcd(int x, int y) { return (y == 0 ? x : gcd(y, x % y)); }
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  int A, B;
  cin >> A >> B;
  int K;
  cin >> K;
  nCr_compute_factinv(N);

  mint ans = 0;
  rep(a, 0, N + 1) {
    int b = (K - A * a) / B;
    if (b < 0 or b > N or A * a + B * b != K)
      continue;

    ans += nCr(N, a) * nCr(N, b);
  }
  cout << ans.get() % MOD << endl;

  return 0;
}
