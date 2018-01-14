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
//最大公約数 複数個
int gcd(const vector<int> &v) {
  int ret = v[0];
  for (int i = 1; i < v.size(); i++)
    ret = gcd(ret, v[i]);
  return ret;
}

signed main() {
  // cin.tie(0);
  // ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, 0, N) { scanf("%d", &A[i]); }
  vector<int> B(N);
  rep(i, 0, N) { scanf("%d", &B[i]); }

  vector<int> C(N);
  rep(i, 0, N) {
    if (B[i] > A[i]) {
      cout << -1 << endl;
      return 0;
    } else
      C[i] = A[i] - B[i];
  }

  int g = gcd(C);

  if (g == 0) {
    cout << *max_element(all(A)) + 1 << endl;
    return 0;
  }

  auto d = divisor(g);
  int K = INF;
  rep(i, 0, d.size()) {
    bool f = true;
    rep(j, 0, N) {
      if (B[j] != A[j] % d[i]) {
        f = false;
        break;
      }
    }
    if (f)
      chmin(K, d[i]);
  }
  if (K == INF)
    cout << -1 << endl;
  else
    cout << K << endl;

  return 0;
}
