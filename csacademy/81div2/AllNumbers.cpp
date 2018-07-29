#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
// typedef __int128_t Int;
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

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  nCr_compute_factinv(N);
  vector<int> D(N);
  map<int, int> a;
  map<int, mint> b, c;
  rep(i, 0, N) {
    cin >> D[i];
    a[D[i]]++;
  }
  sort(all(D));
  // ex
  for (auto z : a) {
    int x = z.first, y = z.second;

    b[x] = fact[N - 1] * x;
    for (auto s : a) {
      int p = s.first, q = s.second;
      if (x == p)
        b[x] /= fact[q - 1];
      else
        b[x] /= fact[q];
    }
  }
  dump(b);

  for (auto z : a) {
    int x = z.first, y = z.second;

    for (auto w : a) {
      int u = w.first, v = w.second;
      if (u == 0)
        continue;
      mint tmp = fact[N - 2];

      for (auto s : a) {
        int p = s.first, q = s.second;
        if (x == p or u == p) {
          if (u == x) {
            tmp /= fact[q - 2];
          } else
            tmp /= fact[q - 1];
        } else
          tmp /= fact[q];
      }
      c[x] += tmp*x;
    }
  }
  dump(c);

  mint ans = 0;

  rrep(i, 0, N) {
    for (auto z : a) {
      int x = z.first, y = z.second;
      dump(i,x,y);
      mint inc=0;
      if (i == N - 1) {
        inc+= b[x]  * pow(mint(10), i);
      } else {
        inc+= c[x]  * pow(mint(10), i);
      }
      dump(inc);
      ans+=inc;
      dump(ans);
    }
  }
  cout << ans << endl;

  return 0;
}
