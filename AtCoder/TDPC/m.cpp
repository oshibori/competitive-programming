#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define ll long long
#define ll1 1ll
#define ONE 1ll
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
template <typename T> class mat : public vector<vector<T>> {
private:
  int r, c; //行,列
public:
  int row() const { return r; }
  int column() const { return c; }
  mat(int n, int m, T val = 0) {
    r = n, c = m;
    for (int i = 0; i < n; i++) {
      this->push_back(vector<T>(m, val));
    }
  }
  mat operator+(const mat &another) {
    if (r != another.r && c != another.c) {
      cout << "足し算失敗(サイズ不一致)" << endl;
      exit(1);
    }
    mat<T> X(r, c);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        X[i][j] = (*this)[i][j] + another[i][j];
      }
    }
    return X;
  }
  mat operator+(const T val) {
    mat<T> X(r, c);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        X[i][j] = (*this)[i][j] + val;
      }
    }
    return X;
  }
  mat operator-(const mat &another) {
    if (r != another.r && c != another.c) {
      cout << "引き算失敗(サイズ不一致)" << endl;
      exit(1);
    }
    mat<T> X(r, c);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        X[i][j] = (*this)[i][j] - another[i][j];
      }
    }
    return X;
  }
  mat operator-(const T val) {
    mat<T> X(r, c);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        X[i][j] = (*this)[i][j] - val;
      }
    }
    return X;
  }
  vector<T> operator*(const vector<T> &another) {
    if (c != (int)another.size()) {
      cout << "掛け算失敗(サイズ不一致)" << endl;
      exit(1);
    }
    vector<T> vec(r, 0);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        vec[i] += (*this)[i][j] * another[j];
      }
    }
    return vec;
  }
  mat operator*(const mat &another) {
    if (c != another.r) {
      cout << "掛け算失敗(サイズ不一致)" << endl;
      exit(1);
    }
    mat<T> X(r, another.c);
    for (int i = 0; i < r; i++) {
      for (int k = 0; k < c; k++) {
        for (int j = 0; j < (another.c); j++) {
          X[i][j] += (*this)[i][k] * another[k][j];
        }
      }
    }
    return X;
  }
  mat operator-() {
    mat<T> X(r, c);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        X[i][j] = -(*this)[i][j];
      }
    }
    return X;
  }
  int rank() {
    int res = 0;
    mat B(r, c);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        B[i][j] = (*this)[i][j];
      }
    }
    for (int i = 0; i < c; i++) {
      if (res == r)
        return res;
      int pivot = res;
      for (int j = res + 1; j < r; j++) {
        if (abs(B[j][i]) > abs(B[pivot][i])) {
          pivot = j;
        }
      }
      if (abs(B[pivot][i]) < EPS)
        continue;
      swap(B[pivot], B[res]);
      for (int j = i + 1; j < c; j++) {
        B[res][j] /= B[res][i];
      }
      for (int j = res + 1; j < r; j++) {
        for (int k = i + 1; k < c; k++) {
          B[j][k] -= B[res][k] * B[j][i];
        }
      }
      res++;
    }
    return res;
  }
  T det() {
    if (r != c) {
      cout << "正方行列でない(行列式定義不可)" << endl;
      exit(1);
    }
    T ans = 1;
    mat B(r, r);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < r; j++) {
        B[i][j] = (*this)[i][j];
      }
    }
    for (int i = 0; i < r; i++) {
      for (int j = i + 1; j < r; j++) {
        // 行i,jをgcdしている!
        for (; B[j][i] != 0; ans = -ans) {
          // 行をswapしているので(-1)倍する
          T tm = B[i][i] / B[j][i];
          for (int k = i; k < r; k++) {
            T t = B[i][k] - tm * B[j][k];
            B[i][k] = B[j][k];
            B[j][k] = t;
          }
        }
      }
      ans *= B[i][i];
    }
    return ans;
  }
  mat inverse() {
    if (r != c) {
      cout << "正方行列でない(逆行列定義不可)" << endl;
      exit(1);
    }
    mat B(r, 2 * r);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < r; j++) {
        B[i][j] = (*this)[i][j];
      }
    }
    for (int i = 0; i < r; i++) {
      B[i][r + i] = 1;
    }
    for (int i = 0; i < r; i++) {
      int pivot = i;
      for (int j = i; j < r; j++) {
        if (abs(B[j][i]) > abs(B[pivot][i])) {
          pivot = j;
        }
      }
      if (abs(B[pivot][i]) < EPS) {
        cout << "解なしor不定" << endl;
        exit(1);
      }
      swap(B[i], B[pivot]);
      for (int j = i + 1; j <= 2 * r; j++) {
        B[i][j] /= B[i][i];
      }
      for (int j = 0; j < r; j++) {
        if (i != j) {
          for (int k = i + 1; k <= 2 * r; k++) {
            B[j][k] -= B[j][i] * B[i][k];
          }
        }
      }
    }
    mat res(r, r);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < r; j++) {
        res[i][j] = B[i][r + j];
      }
    }
    return res;
  }
  void print() {
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < (c - 1); j++) {
        cout << (*this)[i][j] << ",";
      }
      cout << (*this)[i][c - 1] << endl;
    }
  }
};

template <typename T> vector<T> eq_solve(const mat<T> &A, const vector<T> &b) {
  if (A.row() != A.column()) {
    cout << "正方行列でない(解なしor不定)" << endl;
    exit(1);
  }
  int n = A.row();
  mat<T> B(n, n + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      B[i][j] = A[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    B[i][n] = b[i];
  }
  for (int i = 0; i < n; i++) {
    int pivot = i;
    for (int j = i; j < n; j++) {
      if (abs(B[j][i]) > abs(B[pivot][i])) {
        pivot = j;
      }
    }
    if (abs(B[pivot][i]) < EPS) {
      cout << "解なしor不定" << endl;
      exit(1);
    }
    swap(B[i], B[pivot]);
    for (int j = i + 1; j <= n; j++) {
      B[i][j] /= B[i][i];
    }
    for (int j = 0; j < n; j++) {
      if (i != j) {
        for (int k = i + 1; k <= n; k++) {
          B[j][k] -= B[j][i] * B[i][k];
        }
      }
    }
  }
  vector<T> res(n);
  for (int i = 0; i < n; i++) {
    res[i] = B[i][n];
  }
  return res;
}

template <typename T> mat<T> pow(mat<T> A, long long cnt) {
  if (A.row() != A.column()) {
    cout << "累乗不可" << endl;
  }
  int n = A.row();
  mat<T> B(n, n);
  for (int i = 0; i < n; i++) {
    B[i][i] = 1;
  }
  while (cnt > 0) {
    if (cnt & 1) {
      B = B * A;
    }
    A = A * A;
    cnt >>= 1;
  }
  return B;
}

template <typename T> mat<T> mod_mul(mat<T> &A, mat<T> &B) {
  if (A.column() != B.row()) {
    cout << "掛け算失敗(サイズ不一致)" << endl;
    exit(1);
  }
  mat<T> X(A.row(), B.column());
  for (int i = 0; i < A.row(); i++) {
    for (int k = 0; k < A.column(); k++) {
      for (int j = 0; j < B.column(); j++) {
        X[i][j] = (X[i][j] + A[i][k] * B[k][j]) % MOD;
      }
    }
  }
  return X;
}

template <typename T> mat<T> mod_pow(mat<T> A, long long cnt) {
  if (A.row() != A.column()) {
    cout << "累乗不可" << endl;
  }
  int n = A.row();
  mat<T> B(n, n);
  for (int i = 0; i < n; i++) {
    B[i][i] = 1;
  }
  while (cnt > 0) {
    if (cnt & 1) {
      B = mod_mul(B, A);
    }
    A = mod_mul(A, A);
    cnt >>= 1;
  }
  return B;
}

signed main(signed argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int H, R;
  cin >> H >> R;
  vector<vector<int>> g(R, vector<int>(R));
  rep(i, 0, R) rep(j, 0, R) { cin >> g[i][j]; }
  mat<mint> A(R, R);
  rep(k, 0, R) {
    mint dp[1 << 16][16];
    rep(bits, 0, 1 << R) rep(i, 0, R) dp[bits][i] = 0;
    dp[1 << k][k] = 1;
    rep(bits, 0, 1 << R) {
      rep(i, 0, R) {
        rep(j, 0, R) { dp[bits][i] += dp[bits ^ (1 << i)][j] * g[i][j]; }
        A[k][i] += dp[bits][i];
      }
    }
  }
  cout << pow(A, H)[0][0] << endl;

  return 0;
}
