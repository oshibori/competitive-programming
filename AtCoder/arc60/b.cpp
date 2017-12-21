#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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

int f(int b, int n) {
  int ret = 0;
  while (n) {
    ret += n % b;
    n /= b;
  }
  return ret;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, s;
  cin >> n >> s;
  if (s == n) {
    cout << n + 1 << endl;
    return 0;
  } else {
    rep(b, 2, 1 + sqrt(n + 1)) {
      if (f(b, n) == s) {
        cout << b << endl;
        return 0;
      }
    }
    int ans = INF;
    rep(p, 1, 1 + sqrt(n)) {
      if ((n - s) % p == 0) {
        int b = 1 + (n - s) / p;
        if(!(b>=2))continue;
        if (f(b, n) == s) {
          chmin(ans, b);
        }
      }
    }
    if (ans == INF)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }

  return 0;
}
