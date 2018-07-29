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

struct Point {
  int x, y;
  Point() {}
  Point(int x, int y) : x(x), y(y) {}
};
istream &operator>>(istream &is, Point &a) {
  is >> a.x >> a.y;
  return is;
}
Point operator-(Point a, Point b) {
  Point c;
  c.x = a.x - b.x;
  c.y = a.y - b.y;
  return c;
}
int cross(Point a, Point b) { return (a.x * b.y) - (b.x * a.y); }
struct Square {
  Point ps[4];

  bool f(Point a) {
    vector<int> c(4);
    bool l = true, r = true;
    rep(i, 0, 4) {
      c[i] = cross(ps[(i + 1) % 4] - a, ps[i] - a);

      l &= (c[i] <= 0);
      r &= (c[i] >= 0);
    }

    return l or r;
  }
};
istream &operator>>(istream &is, Square &a) {
  rep(i, 0, 4) { is >> a.ps[i]; }
  return is;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  Square a, b;
  cin >> a >> b;

  bool f = false;
  rep(i, -100, 101) rep(j, -100, 101) {
    Point x(i, j);
    f |= (a.f(x) and b.f(x));
  }

  cout << (f ? "YES" : "NO") << endl;

  return 0;
}
