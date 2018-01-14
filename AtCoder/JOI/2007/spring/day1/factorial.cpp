#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
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
//エラトステネスの篩
vector<char> eratos(int n) {
	vector<char> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i*i <= n; i++)
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
		while (x%p == 0) {
			x /= p;
			factors.emplace_back(p);
		}
	}
	if (x != 1)factors.emplace_back(x);
	return factors;
}



signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  auto x = prime_factorization(N);
  map<int,int>a;
  rep(i,0,x.size())a[x[i]]++;
  int l=1,r=1e8+10;

  while(abs(r-l)>1){
    dump(l,r);
    int m=(l+r)/2;

    bool f=true;
    for(auto &o:a){
      int s=o.first;
      if(a[s]>m/s){
        f=false;
        break;
      }
    }

    if(f)r=m;
    else l=m;
  }
  dump(l,r);
  cout<<r<<endl;


  return 0;
}
