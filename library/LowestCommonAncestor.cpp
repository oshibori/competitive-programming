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
struct Graph {
  int V;
  vector<vector<int>> g;
  vector<int> dist;
  Graph(int V) : V(V), g(V), dist(V, -1) {}
  void add_edge(int s, int t) {
    g[s].push_back(t);
    g[t].push_back(s);
  }
};

struct Tree { // rooted tree
  vector<vector<int>> g, parent;
  int root, V, log2_n;
  vector<int> depth;
  int get_depth(int x) { return depth[x]; }
  void dfs(int v, int p, int d) {
    parent[0][v] = p;
    depth[v] = d;
    rep(i, 0, g[v].size()) {
      if (g[v][i] != p)
        dfs(g[v][i], v, d + 1);
    }
  }
  Tree(Graph G, int root)
      : root(root), V(G.V), g(G.g), depth(V), log2_n(1 + (int)log2(V)) {
    parent.resize(log2_n, vector<int>(V));
    dfs(root, -1, 0);
    for (int k = 0; k + 1 < log2_n; k++) {
      for (int v = 0; v < V; v++) {
        if (parent[k][v] < 0)
          parent[k + 1][v] = -1;
        else
          parent[k + 1][v] = parent[k][parent[k][v]];
      }
    }
  }
  int lca(int u, int v) {
    if (depth[u] > depth[v])
      swap(u, v);
    for (int k = 0; k < log2_n; k++) {
      if ((depth[v] - depth[u]) >> k & 1) {
        v = parent[k][v];
      }
    }
    if (u == v)
      return u;
    for (int k = log2_n - 1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  Graph g(N);
  rep(i, 0, N) {
    int k;
    cin >> k;
    rep(j, 0, k) {
      int c;
      cin >> c;
      g.add_edge(i, c);
    }
  }
  Tree t(g, 0);
  int Q;
  cin >> Q;
  loop(Q) {
    int u, v;
    cin >> u >> v;
    cout << t.lca(u, v) << endl;
  }

  return 0;
}
