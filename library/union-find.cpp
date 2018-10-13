#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

#define DBG 1
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define all(c) c.begin(), c.end()
const int INF =
    sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;

// 重み付きunion-find
// https://qiita.com/drken/items/cce6fc5c579051e64fab
// n: 要素数
// SUM_UNITY: 基本的に 0 を入れます
// SUM_UNITY について補足ですが、重み付き UnionFind の重みは一般にアーベル群
// (足し算と引き算ができる代数系) を乗せられます。その場合は、SUM_UNITY
// には「アーベル群の単位元」を入れます。
template <class Abel> struct UnionFind {
  vector<int> par;
  vector<int> rank;
  vector<Abel> diff_weight;

  UnionFind(int n = 1, Abel SUM_UNITY = 0) { init(n, SUM_UNITY); }

  void init(int n = 1, Abel SUM_UNITY = 0) {
    par.resize(n);
    rank.resize(n);
    diff_weight.resize(n);
    for (int i = 0; i < n; ++i)
      par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
  }

  int root(int x) {
    if (par[x] == x) {
      return x;
    } else {
      int r = root(par[x]);
      diff_weight[x] += diff_weight[par[x]];
      return par[x] = r;
    }
  }

  Abel weight(int x) {
    root(x);
    return diff_weight[x];
  }

  bool issame(int x, int y) { return root(x) == root(y); }

  bool merge(int x, int y, Abel w) {
    w += weight(x);
    w -= weight(y);
    x = root(x);
    y = root(y);
    if (x == y)
      return false;
    if (rank[x] < rank[y])
      swap(x, y), w = -w;
    if (rank[x] == rank[y])
      ++rank[x];
    par[y] = x;
    diff_weight[y] = w;
    return true;
  }

  Abel diff(int x, int y) { return weight(y) - weight(x); }
};

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
