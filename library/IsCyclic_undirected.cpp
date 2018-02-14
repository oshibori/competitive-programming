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
struct Graph {
  int V;
  vector<vector<int>> g;
  vector<int> visited;
  vector<int> indeg;
  Graph(int V) : V(V), g(V), visited(V), indeg(V) {}
  void add_edge(int s, int t) { g[s].push_back(t); }
  bool is_cyclic() {
    fill(all(visited), 0);

    rep(i, 0, V) {
      if (!visited[i] and isCyclicUtil(i, -1))
        return true;
    }
    return false;
  }
  bool isCyclicUtil(int v, int p) {
    visited[v] = true;
    rep(i, 0, g[v].size()) {
      int x = g[v][i];
      if (not visited[x]) {
        if (isCyclicUtil(x, v))
          return true;
      } else if (x != p)
        return true;
    }
    return false;
  }
};
