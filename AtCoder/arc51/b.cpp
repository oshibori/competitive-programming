#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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

int cnt = 0;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  cnt++;
  return gcd(b, a % b);
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int K;
  cin >> K;
  vector<int> f(45);
  f[1] = f[2] = 1;
  rep(i, 3, f.size()) f[i] = f[i - 1] + f[i - 2];

  cout << f[K + 2] << " " << f[K + 1] << endl;
  gcd(f[K+2],f[K+1]);
  dump(cnt);

  return 0;
}
