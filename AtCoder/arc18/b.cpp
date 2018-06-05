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
  Point(int x, int y) : x(x), y(y) {}
  Point() {}
  Point operator+(const Point p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point p) const { return Point(x - p.x, y - p.y); }
};
istream &operator>>(istream &is, Point &p) {
  is >> p.x >> p.y;
  return is;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  int ans = 0;
  vector<Point> p(N);
  rep(i, 0, N) { cin >> p[i]; }
  rep(i, 0, N) rep(j, i + 1, N) rep(k, j + 1, N) {
    Point a = p[j] - p[i];
    Point b = p[k] - p[i];

    int s = abs(a.x * b.y - a.y * b.x);
    if (s % 2 == 0 and s > 0)
      ans++;
  }
  cout << ans << endl;

  return 0;
}
