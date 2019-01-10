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
//エラトステネスの篩
vector<char> eratos(int n) {
  vector<char> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= n; i++)
    if (is_prime[i]) {
      int j = i + i;
      while (j <= n) {
        is_prime[j] = false;
        j += i;
      }
    }
  return is_prime;
}
//戻り値: n以下の素数
vector<int> get_primes(int n) {
  vector<char> is_prime = eratos(n);
  vector<int> primes;
  for (int i = 0; i < n + 1; i++)
    if (is_prime[i])
      primes.emplace_back(i);
  return primes;
}
//素因数分解
vector<int> prime_factorization(int x) {
  vector<int> primes = get_primes(sqrt(x)); //√x以下の素数について調べれば良い
  vector<int> factors;
  // xまでのeratosと同じ。ｘはgiven ｘまでの最大の素数。
  // だんだん左によってくる。だからsqrt(x)まででいい
  for (auto &p : primes) {
    while (x % p == 0) {
      x /= p;
      factors.emplace_back(p);
    }
  }
  if (x != 1)
    factors.emplace_back(x);
  return factors;
}
//高速累乗 繰り返し自乗法
//オーバーフローする可能性があれば掛け算にmodmul()を使う
long long modpow(long long base, long long exponent,
                 long long mod = LLONG_MAX) {
  long long res = 1;
  while (exponent > 0) {
    if (exponent & 1)
      res = res * base % mod;
    base = base * base % mod;
    exponent >>= 1;
  }
  return res;
}
signed main(signed argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  auto primes = get_primes(N + 1);
  dump(primes);
  vector<int> nfact(N + 10, 0);
  rep(i, 1, N + 1) {
    auto f = prime_factorization(i);
    dump(f);
    for (auto x : f)
      nfact[x]++;
  }
  dump(nfact);
  int ans = 0;
  set<int> st;
  rep(i, 0, primes.size()) {
    rep(j, 0, primes.size()) {
      rep(k, 0, primes.size()) {
        if (i == j or j == k or k == i)
          continue;
        int p1 = primes[i];
        int p2 = primes[j];
        int p3 = primes[k];
        map<int, int> c;
        c[p1] += 2;
        c[p2] += 4;
        c[p3] += 4;
        int x = 1;
        bool f = true;
        for (auto p : c) {
          x *= (p.se + 1);
          f &= nfact[p.fi] >= p.se;
        }
        if (f and x == 75) {
          ans++;
          dump(p1, p2, p3, modpow(p1, 2) * modpow(p2, 4) * modpow(p3, 4));
          // st.insert(modpow(p1, 2) * modpow(p2, 4) * modpow(p3, 4));
          dump(nfact[p1], nfact[p2], nfact[p3]);
        }
      }
    }
  }
  ans /= 2;
  rep(i, 0, primes.size()) {
    rep(j, 0, primes.size()) {
      if (i == j)
        continue;
      int p1 = primes[i];
      int p2 = primes[j];
      if (nfact[p1] >= 2 and nfact[p2] >= 24) {
        ans++;
      }
      if (nfact[p1] >= 4 and nfact[p2] >= 14) {
        ans++;
      }
    }
  }
  rep(i, 0, primes.size()) {
    if (nfact[primes[i]] >= 74)
      ans++;
  }
  cout << ans << endl;

  return 0;
}
