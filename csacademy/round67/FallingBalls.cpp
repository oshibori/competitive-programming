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
template <typename T> class DisjointSet {
public:
  vector<T> rank, p;
  DisjointSet() {}
  DisjointSet(int size) {
    rank.resize(size, 0);
    p.resize(size, 0);
    rep(i, 0, size) makeSet(i);
  }
  void makeSet(int x) {
    p[x] = x;
    rank[x] = 0;
  }
  bool same(int x, int y) { return findSet(x) == findSet(y); }
  void unite(int x, int y) { link(findSet(x), findSet(y)); }
  void link(int x, int y) {
    if (rank[x] > rank[y]) {
      p[y] = x;
    } else {
      p[x] = y;
      if (rank[x] == rank[y]) {
        rank[y]++;
      }
    }
  }
  int findSet(int x) {
    if (x != p[x]) {
      p[x] = findSet(p[x]); // path compression
    }
    return p[x];
  }
};
template <typename T> struct RangeUpdateQuery {
  int n;
  vector<T> d;
  RangeUpdateQuery(int m) {
    for (n = 1; n < m; n <<= 1)
      ;
    d.assign(2 * n, INF);
    rep(i, n, d.size()) d[i] = i-n;
  }
  int get(int i) {
    update(i, i + 1, -1);
    return d[n + i];
  }
  void update(int a, int b, T x) { return update(a, b, x, 1, 0, n); }
  void update(int a, int b, T x, int k, int l, int r) {
    // [a,b) [l,r)
    if (r <= a || b <= l)
      return;
    else if (a <= l && r <= b) {
      if (x >= 0)
        d[k] = x;
      return;
    } else {
      // [l,r) のどこかを変更するとなると、
      // d[ [l,r) ] == z(同じ値)  が保てなくなるので子に値を移す
      //
      if (d[k] != INF)
        d[2 * k] = d[2 * k + 1] = d[k], d[k] = INF;
      update(a, b, x, 2 * k, l, (l + r) / 2);
      update(a, b, x, 2 * k + 1, (l + r) / 2, r);
    }
  }
};

struct segment {
  int x1, x2, y;
  segment(int x1, int x2, int y) : x1(x1), x2(x2), y(y) {}
  bool operator<(segment &o) { return y < o.y; }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  RangeUpdateQuery<int> tree(1e6 + 10);
  int N, M;
  cin >> N >> M;
  vector<segment> seg;
  rep(i, 0, N) {
    int a, b, c;
    cin >> a >> b >> c;
    seg.push_back(segment(a, b, c));
  }
  sort(all(seg));
  rep(i, 0, N) {
    int x1 = seg[i].x1, x2 = seg[i].x2, y = seg[i].y;
    int m = (x1 + x2) / 2;
    if ((x1 + x2) % 2 == 0) {
      tree.update(x1, m + 1, x1);
      tree.update(m + 1, x2 + 1, x2);
    } else {
      tree.update(x1, m + 1, x1);
      tree.update(m + 1, x2 + 1, x2);
    }
  }
  loop(M) {
    int x;
    cin >> x;
    cout << tree.get(x) << endl;
  }

  return 0;
}
