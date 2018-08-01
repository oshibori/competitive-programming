#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DBG 1
#define dump(o)                                                                \
  if (DBG) {                                                                   \
    cerr << #o << " " << o << endl;                                            \
  }
#define dumpc(o)                                                               \
  if (DBG) {                                                                   \
    cerr << #o;                                                                \
    for (auto &e : (o))                                                        \
      cerr << " " << e;                                                        \
    cerr << endl;                                                              \
  }
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define each(it, c) for (auto it = (c).begin(); it != (c).end(); it++)
#define all(c) c.begin(), c.end()
const int INF =
    sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);

struct UnionFind {
  // https://beta.atcoder.jp/contests/arc099/submissions/2926148
  // written by ei1333
  vector<int> data;

  UnionFind(int sz) { data.assign(sz, -1); }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)
      return (false);
    if (data[x] > data[y])
      swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k) {
    if (data[k] < 0)
      return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) { return (-data[find(k)]); }
};
struct DisjointSet {
  vector<int> rank, p;
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
  bool unite(int x, int y) {
    if (same(x, y))
      return false;
    link(findSet(x), findSet(y));
    return true;
  }
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
signed main() {
  int n, a, b, q, t;
  cin >> n >> q;
  DisjointSet ds(n);
  rep(i, 0, q) {
    cin >> t >> a >> b;
    if (t == 0)
      ds.unite(a, b);
    else if (t == 1) {
      if (ds.same(a, b))
        cout << 1 << endl;
      else
        cout << 0 << endl;
    }
  }
  return 0;
}
