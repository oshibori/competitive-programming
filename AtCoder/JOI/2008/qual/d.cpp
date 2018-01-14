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
struct Point {
  int x, y;
  Point() {}
  Point(int a, int b) : x(a), y(b) {}
  Point operator+(const Point a) const {
    return Point(this->x + a.x, this->y + a.y);
  }
  Point operator-(const Point a) const {
    return Point(this->x - a.x, this->y - a.y);
  }
  Point &operator-=(Point &p) {
    this->x -= p.x;
    this->y -= p.y;
    return (*this);
  }
  bool operator<(const Point &p)const { return (x == p.x) ? y < p.y : x < p.x; }
  bool operator>(const Point &p)const { return (x == p.x) ? y > p.y : x > p.x; }
  bool operator==(const Point &p)const { return (x == p.x) ? y == p.y : false; }
};
istream &operator>>(istream &is, Point &p) {
  is >> p.x >> p.y;
  return is;
}
ostream &operator<<(ostream &os, Point &p) { os << p.x << " " << p.y; }
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int M;
  cin >> M;
  vector<Point> v(M);
  rep(i, 0, M) { cin >> v[i]; }
  int N;
  cin >> N;
  map<Point, int> m;
  rep(i, 0, N) {
    Point x;
    cin >> x;
    m[x]++;
  }

  rep(i, 1, M) v[i] -= v[0];

  Point ans;
  for (auto &o : m) {
    bool f = true;
    rep(i, 1, M) {
      if (!m.count(v[i] + o.first)) {
        f = false;
        break;
      }
    }
    if (f) {
      ans = o.first - v[0];
      break;
    }
  }
  cout << ans << endl;

  return 0;
}
