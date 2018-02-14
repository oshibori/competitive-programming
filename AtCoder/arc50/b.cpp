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

int x, y;
int R, B;
bool f(int k) { return (R - k) / (x - 1) + (B - k) / (y - 1) >= k; };
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> R >> B;
  cin >> x >> y;
  int l = 0, r = min(R, B) + 1;
  //int l = 0, r = 1e18 + 10;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (f(m))
      l = m;
    else
      r = m;
  }
  cout << l << endl;

  return 0;
}
