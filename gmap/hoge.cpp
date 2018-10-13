//#include <bits/stdc++.h>
// utility
#include <bitset>
#include <tuple>
#include <typeinfo>
// error handling
#include <cassert>
// string
#include <cctype>
#include <cstring>
#include <string>
// container
#include <array>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// algorithm
#include <algorithm>
// iterator
#include <iterator>
// math
#include <cmath>
#include <complex>
#include <numeric>
#include <random>
// i/o
#include <cstdio>
#include <iomanip>
#include <iostream>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
typedef __int128_t Int;
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
#define fi first
#define se second
using pii = pair<int, int>;
// template<class T> ostream &operator<<(ostream &os,T &t){dump(t);return os;}
template <typename T, typename S>
istream &operator>>(istream &is, pair<T, S> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T> void printvv(const vector<vector<T>> &v) {
  cerr << endl;
  rep(i, 0, v.size()) rep(j, 0, v[i].size()) {
    if (typeid(v[i][j]) == typeid(INF) and v[i][j] == INF) {
      cerr << "INF";
    } else
      cerr << v[i][j];
    cerr << (j == v[i].size() - 1 ? '\n' : ' ');
  }
  cerr << endl;
}

#ifndef _DEBUG
#define printvv(...)
#endif
void YES(bool f) { cout << (f ? "YES" : "NO") << endl; }
void Yes(bool f) { cout << (f ? "Yes" : "No") << endl; }
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
using Weight = int;
using Flow = int;
struct Edge {
  int s, d;
  Weight w;
  Flow c;
  Edge(){};
  Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w), c(w){};
};
bool operator<(const Edge &e1, const Edge &e2) { return e1.w < e2.w; }
bool operator>(const Edge &e1, const Edge &e2) { return e2 < e1; }
inline ostream &operator<<(ostream &os, const Edge &e) {
  return (os << '(' << e.s << ", " << e.d << ", " << e.w << ')');
}

using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

using Chimera = Graph;
using EmbeddedGraph = Graph;
using SegmentGraph = Graph;

void addArc(Graph &g, int s, int d, Weight w = 1) {
  g[s].emplace_back(s, d, w);
}
void addEdge(Graph &g, int a, int b, Weight w = 1) {
  addArc(g, a, b, w);
  addArc(g, b, a, w);
}
struct UnionFind {
  vector<int> data;
  int sz;

  UnionFind(int sz) : sz(sz) { data.assign(sz, -1); }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)
      return (false);
    if (data[x] > data[y])
      swap(x, y);
    data[x] += data[y];
    data[y] = x;
    sz--;
    return (true);
  }

  int find(int k) {
    if (data[k] < 0)
      return (k);
    return (data[k] = find(data[k]));
  }
  vector<vector<int>> connected_components() {
    map<int, vector<int>> mp;
    rep(i, 0, data.size()) { mp[find(i)].emplace_back(i); }
    vector<vector<int>> cc;
    for (auto &x : mp) {
      cc.emplace_back(x.second);
    }
    return cc;
  }
  int size() { return sz; }
  int size(int k) { return (-data[find(k)]); }
};

struct Mapping {
  vector<int> to_emb, to_g;
  Mapping() {}
  Mapping(int n) {
    // random init
    iota(all(to_emb), 0);
    iota(all(to_g), 0);
  }
};
Graph in() { return Graph(); }
EmbeddedGraph init_emb(UnionFind &uf) {
  const int Nqbits = 8 * 16 * 16;
  const int Nunits = 16 * 16;
  EmbeddedGraph emb(Nqbits);
  rep(i, 0, Nunits) {
    int x = 8 * i;
    int y = x + 4;

    if (i < 16 * 15) {
      rep(j, 0, 4) {
        addEdge(emb, x + j, x + j + 16 * 8);
        uf.unite(x + j, x + j + 16 * 8);
      }
    }
    if (i % 16 < 15) {
      rep(j, 0, 4) {
        addEdge(emb, y + j, y + j + 8);
        uf.unite(y + j, y + j + 8);
      }
    }
  }

  return emb;
}
Chimera init_chimera() {
  const int Nqbits = 8 * 16 * 16;
  const int Nunits = 16 * 16;
  Chimera chimera(Nqbits);
  rep(i, 0, Nunits) {
    int x = 8 * i;
    int y = x + 4;

    rep(j, 0, 4) rep(k, 0, 4) { addEdge(chimera, x + j, y + k); }

    if (i < 16 * 15) {
      rep(j, 0, 4) { addEdge(chimera, x + j, x + j + 16 * 8); }
    }
    if (i % 16 < 15) {
      rep(j, 0, 4) { addEdge(chimera, y + j, y + j + 8); }
    }
  }

  return chimera;
}
Chimera chimera;
SegmentGraph gen_seg_graph(UnionFind &uf) {
  vector<vector<int>> cc = uf.connected_components();
  map<int, int> ch_idx; // uf_idx -> seg_idx;
  rep(i, 0, cc.size()) { ch_idx[uf.find(cc[i][0])] = i; }

  SegmentGraph seg(cc.size());
  vector<vector<int>>target_tables(cc.size(),vector<int>(cc.size());
  rep(i,0,cc.size()){
    vector<int> &table = target_tables[i];
    for (int vertex : cc[i]) {
      for (Edge &e : chimera[vertex]) {
        table[e.d] = 1;
      }
    }
  }
}
Mapping SimulatedAnnealing(Graph &in) { return Mapping(); }
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  Graph g = in();
  UnionFind uf(2048);
  chimera = init_chimera();
  EmbeddedGraph emb = init_emb(uf);

  Mapping mapping(g.size());

  return 0;
}
