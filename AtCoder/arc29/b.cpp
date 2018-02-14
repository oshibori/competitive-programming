#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
// typedef __int128_t Int;
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

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  double a, b;
  cin >> a >> b;
  if (a > b)
    swap(a, b);
  int N;
  cin >> N;
  rep(i, 0, N) {
    double c, d;
    cin >> c >> d;
    if(c>d)swap(c,d);
    if (a <= c and b <= d) {
      cout << "YES" << endl;
      continue;
    }

    double l = 0, r = PI / 2;
    loop(100) {
      double m = (l + r) / 2;
      if (b * cos(m) + a * sin(m) > d)
        l = m;
      else
        r = m;
    }
    if (a * cos(l) + b * sin(l) <= c) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }

  return 0;
}
