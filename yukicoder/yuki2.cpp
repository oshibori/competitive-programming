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
  vector<int> primes;
  vector<char> is_prime = eratos(n);
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

vector<int> a;
int f(int n) {
  if (a[n] != -1)
    return a[n];

  auto x = prime_factorization(n);
  x.erase(unique(all(x)), x.end());

  for (auto &p : x) {
    int m = n;
    while (m % p == 0) {
      m /= p;
      if (f(m) == 0) {
        return a[n] = 1;
      }
    }
  }
  return a[n] = 0;
}
void solve() {
  int N;
  cin >> N;
  a = vector<int>(N + 1, -1);
  cout << (f(N) ? "Alice" : "Bob") << endl;
}
void solve2() {
  int N;
  cin >> N;
  auto p = prime_factorization(N);
  map<int, int> m;
  for (auto &o : p)
    m[o]++;
  int ans = 0;
  for (auto &o : m)
    ans ^= o.second;
  cout << (ans == 0 ? "Bob" : "Alice") << endl;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // solve();
  solve2();

  return 0;
}
