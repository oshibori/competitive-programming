#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define DBG 0
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

istream &operator>>(istream &is, Point &p) {
  is >> p.x >> p.y;
  return is;
}

int dist2(Point a, Point b) {
  return ((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}
int N;
int W, H;
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> W >> H;

  vector<Point> p(N);
  rep(i, 0, N) { cin >> p[i]; }
  int ans = 0;
  rep(i, 0, N) rep(j, 0, N) rep(k, 0, N) rep(l, 0, N) {
    if (i == j || i == k || i == l)
      continue;
    if (j == k || j == l)
      continue;
    if (k == l)
      continue;

    int s = min(min(p[i].x, W - p[i].x), min(p[i].y, H - p[i].y));
    int r1 = dist2(p[i], p[j]), r2 = dist2(p[k], p[l]),
        dist = dist2(p[i], p[k]);

    if (r1 > dist + r2 and s * s >= r1 and
        4 * dist * r2 < (pow(r1 - dist - r2, 2)))
      ans++;
  }
  cout << ans << endl;

  return 0;
}
