#include "bits/stdc++.h"
using namespace std; 
//https://www.geeksforgeeks.org/calculate-xor-1-n/
// Function to calculate xor from 1 to n
long computeXOR(const int n) 
{ 
    // Modulus operator are expensive on most of the  
    // computers. n & 3 will be equivalent to n % 4.    
  
    switch(n & 3) // n % 4  
    { 
    case 0: return n;     // if n is multiple of 4 
    case 1: return 1;     // If n % 4 gives remainder 1   
    case 2: return n + 1; // If n % 4 gives remainder 2     
    case 3: return 0;     // If n % 4 gives remainder 3   
    } 
} 

//約数を求める 未ソート
vector<int> divisor(int x) {
  vector<int> ret;
  int i;
  for (i = 1; i * i < x; i++) {
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

//拡張ユークリッドの互除法
// ax+by=gcd(a,b) を満たす x, y を求める
// http://mathtrain.jp/euclid (一次不定方程式への応用)
long long extgcd(long long a, long long b, long long &x, long long &y) {
  long long g = a;
  x = 1;
  y = 0;
  if (b != 0) {
    g = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  }
  return g;
}
// 中国剰余定理 (CRT)
// https://qiita.com/drken/items/ae02240cd1f8edfc86fd
// 答えを x ≡ r (mod. M) として、{r, M} をリターン, 存在しない場合は {0, -1}
// をリターン
// b[i]:= x%m[i]
inline long long mod(long long a, long long m) { return (a % m + m) % m; }
pair<long long, long long> ChineseRem(const vector<long long> &b,
                                      const vector<long long> &m) {
  long long r = 0, M = 1;
  for (int i = 0; i < (int)b.size(); ++i) {
    long long p, q;
    long long d = extgcd(M, m[i], p, q); // p is inv of M/d (mod. m[i]/d)
    if ((b[i] - r) % d != 0)
      return make_pair(0, -1); // no solution
    long long tmp = (b[i] - r) / d * p % (m[i] / d);
    r += M * tmp;
    M *= m[i] / d;
  }
  return make_pair(mod(r, M), M);
}

const double EPS = 1e-8;
// mod(double)
double modulo(double x, double mod) {
  x -= floor(x / mod) * mod;
  if (x < EPS || x + EPS > mod)
    x = 0;
  return x;
}

//最小非負剰余(c/c++は絶対値最小剰余)
int modulo(int x, int mod) {
  return (x % mod < 0) ? x % mod + abs(mod) : x % mod;
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
//(a*b)%mod
long long modmul(long long a, long long b, long long mod) {
  long long x = 0, y = a % mod;
  while (b > 0) {
    if (b & 1)
      x = x + y % mod;
    y = y * 2 % mod;
    b >>= 1;
  }
  return x % mod;
}
//素数判定（Miller-Rabin primality test）2^24程度から
// miller_rabin_primality_test(n, 5)
bool miller_rabin_primality_test(long long x, int iteration) {
  if (x < 2)
    return false;
  if (x != 2 && x % 2 == 0)
    return false;
  long long s = x - 1;
  while (s % 2 == 0)
    s /= 2;
  for (int i = 0; i < iteration; i++) {
    long long a = rand() % (x - 1) + 1, temp = s;
    long long mod = modpow(a, temp, x);
    while (temp != x - 1 && mod != 1 && mod != x - 1) {
      mod = modmul(mod, mod, x);
      temp *= 2;
    }
    if (mod != x - 1 && temp % 2 == 0)
      return false;
  }
  return true;
}

//逆元
// xy%m=1, y<m となるyを求める
// xとmは互いに素
long long modinv(long long x, long long m) {
  long long s, t;
  extgcd(x, m, s, t);
  return (s + m) % m;
}

//素数判定
bool is_prime(int x) {
  if (x <= 1)
    return false;
  else if (x == 2)
    return true;
  if (x % 2 == 0)
    return false;
  for (int i = 3; i * i <= x; i += 2)
    if (x % i == 0)
      return false;
  return true;
}

//旧 エラトステネスの篩
// n以下の正整数を素数か合成数か判定してis_prime[]に格納
void eratos(int n, bool is_prime[]) {
  fill(is_prime, is_prime + n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= n; i++)
    if (is_prime[i]) {
      int j = i + i;
      while (j <= n) {
        is_prime[j] = false;
        j += i;
      }
    }
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

//素因数分解 faster
// http://www.osak.jp/diary/diary_201310.html#20131017
vector<int> prime_factorization(int x) {
  vector<int> min_fact(x + 1);
  min_fact[1] = 1;
  for (int i = 2; i <= x; i++) {
    if (min_fact[i] != 0)
      continue;
    for (int j = i; j <= x; j += i) {
      if (min_fact[j] == 0)
        min_fact[j] = i;
    }
  }
  vector<int>fact;
  while(x>1){
    int f = min_fact[x];
    fact.emplace_back(f);
    x/=f;
  }
  return fact;
}

//オイラーのφ関数（Euler's totient function）
// nと互いに素な数[1,n]の個数
// http://mathtrain.jp/phi
int euler_totient(int n) {
  int ret = n;
  for (int x = 2; x * x <= n; x++) {
    if (n % x)
      continue;
    ret -= ret / x;
    while (n % x == 0)
      n /= x;
  }
  if (n != 1)
    ret -= ret / n;
  return ret;
}

// nCr配列をパスカルの三角形から生成
// double なら 10^308 くらいまでOK
using Num = double;
vector<vector<Num>> nCr;
void compute_nCr(int n) {
  vector<Num> a(1, 1), b(2, 1);
  nCr = {a, b};
  for (int i = 3; i <= n + 1; i++) {
    swap(a, b);
    b.resize(i);
    b[0] = 1;
    b[i - 1] = 1;
    for (int j = 1; j < i - 1; j++)
      b[j] = a[j - 1] + a[j];
    nCr.emplace_back(b);
  }
}
//確率版
// i段目の和は必ず1.0
void compute_nCr_probability(int n) {
  vector<Num> a(1, 1.0), b(2, 1.0 / 2.0);
  nCr = {a, b};
  for (int i = 3; i <= n + 1; i++) {
    swap(a, b);
    b.resize(i);
    b.front() = a.front() / 2.0;
    b.back() = a.back() / 2.0;
    for (int j = 1; j < i - 1; j++)
      b[j] = a[j - 1] / 2.0 + a[j] / 2.0;
    nCr.emplace_back(b);
  }
}

// n進法
// Radix r("0123456789abcdef");
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0208
class Radix {
private:
  const char *s;
  int a[128];

public:
  Radix(const char *s = "0123456789ABCDEF") : s(s) {
    for (int i = 0; s[i]; i++)
      a[(int)s[i]] = i;
  }
  // 10進整数 → n進法文字列
  string format(long long x, int n) {
    if (!x)
      return "0";
    char t[64] = {};
    int i;
    for (i = 62; x; i--) {
      t[i] = s[x % n];
      x /= n;
    }
    return string(t + i + 1);
  }
  // m進法文字列 → n進法文字列
  string format(const string &t, int m, int n) {
    return format(format(t, m), n);
  }
  // m進法文字列 → 10進整数
  long long format(const string &t, int m) {
    long long sm = a[(int)t[0]];
    for (int i = 1; i < (int)t.length(); i++)
      sm = sm * m + a[(int)t[i]];
    return sm;
  }
};

// partition function(分割数)
// dp[i][j]=jのi分割の総数
vector<vector<int>> partition_function(int M, int N) {
  vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
  dp[0][0] = 1;
  for (int i = 1; i < M + 1; i++)
    for (int j = 0; j < N + 1; j++) {
      if (j - i >= 0)
        dp[i][j] = (dp[i][j - i] + dp[i - 1][j]) % MOD;
      else
        dp[i][j] = dp[i - 1][j] % MOD;
    }
  return dp;
}
