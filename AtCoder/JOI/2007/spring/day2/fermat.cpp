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

int mod_pow(int x, int n, int p) {
  int ret = 1;
  while (n) {
    if (n & 1)
      (ret *= x) %= p;
    n >>= 1;
    (x *= x) %= p;
  }
  return ret;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, P;
  cin >> P >> N;
    int v[10000];memset(v,0,sizeof(v));
    int inv[10000];memset(inv,0,sizeof(inv));
//  vector<int> v(P), inv(P);
  rep(i, 0, P) {
    int x = mod_pow(i, N, P);
    dump(x);
    v[i] = x;
    inv[x]++;
  }
  dump(v);
  dump(inv);

  int ans = 0;
  rep(i, 0, P) rep(j, 0, P) ans += inv[(v[i] + v[j]) % P];

  cout << ans << endl;

  return 0;
}
