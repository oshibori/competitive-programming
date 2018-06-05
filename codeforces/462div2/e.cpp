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
struct Circle {
  int x, y, r;
  Circle() {}
};
istream &operator>>(istream &is, Circle &c) {
  is >> c.x >> c.y >> c.r;
  return is;
}
bool f(Circle a, Circle b) {
  double dx = abs(a.x - b.x), dy = abs(a.y - b.y);
  double dz = sqrt(dx * dx + dy * dy);
  return EPS < a.r + b.r - dz;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  vector<Circle> c(N);
  rep(i, 0, N) { cin >> c[i]; }
  if (N == 1) {
    cout << 2 << endl;
  } else if (N == 2) {
    cout << 3 + f(c[0], c[1]) << endl;
  } else {
    bool f1 = f(c[0], c[1]);
    bool f2 = f(c[1], c[2]);
    bool f3 = f(c[2], c[0]);
    bool f4 = f1 and f2 and f3;
    cout << 4 + f1 + f2 + f3 + f4 << endl;
  }

  return 0;
}
