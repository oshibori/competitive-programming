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
//約数を求める 未ソート
vector<int> divisor(int x) {
  vector<int> ret;
  int i;
  for (i = 2; i * i < x; i++) {
    if (x % i)
      continue;
    ret.emplace_back(i);
    ret.emplace_back(x / i);
  }
  if (i * i == x)
    ret.emplace_back(i);
  return ret;
}

//最大公約数
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
//最小公倍数
int lcm(int x, int y) { return x / gcd(x, y) * y; }
//最大公約数 複数個
int gcd(const vector<int> &v) {
  int ret = v[0];
  for (int i = 1; i < v.size(); i++)
    ret = gcd(ret, v[i]);
  return ret;
}
//最小公倍数 複数個
int lcm(const vector<int> &v) {
  int ret = v[0];
  for (int i = 1; i < v.size(); i++)
    ret = lcm(ret, v[i]);
  return ret;
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
bitset<100005> sss[9700];
signed main(signed argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, M;
  cin >> N >> M;
  vector<int> a(N);
  rep(i, 0, N) { cin >> a[i]; }
  int cnt = 0;
  map<int, int> prime_to_idx;
  vector<int> primes(101010, 0);
  rep(i, 2, primes.size()) {
    if (primes[i] != 0)
      continue;
    prime_to_idx[i] = cnt++;
    for (int j = i; j < primes.size(); j += i) {
      primes[j] = i;
    }
  }

  rep(i, 0, N) {
    int tmp = a[i];
    while (tmp != 1) {
      int d = primes[tmp];
      sss[prime_to_idx[d]].set(i);
      tmp /= d;
    }
  }

  rep(i, 1, M + 1) {
    bitset<100005> ans;
    int tmp = i;
    while (tmp != 1) {
      int d = primes[tmp];
      ans |= sss[prime_to_idx[d]];
      tmp /= d;
    }
    cout << N - ans.count() << endl;
  }

  return 0;
}
