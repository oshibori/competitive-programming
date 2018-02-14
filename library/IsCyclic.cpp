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
  vector<int> visited, recStack;
  vector<int> indeg;
  Graph(int V) : V(V), g(V), visited(V), indeg(V), recStack(V) {}
  void add_edge(int s, int t) { g[s].push_back(t); }
  bool is_cyclic() {
    fill(all(visited), 0);
    fill(all(recStack), 0);

    rep(i, 0, V) {
      if (isCyclicUtil(i))
        return true;
    }
    return false;
  }
  bool isCyclicUtil(int v) {
    if (!visited[v]) {
      visited[v] = recStack[v] = true;

      rep(i, 0, g[v].size()) {
        int x = g[v][i];
        if (!visited[x] and isCyclicUtil(x))
          return true;
        else if (recStack[x])
          return true;
      }
    }
    recStack[v] = false;
    return false;
  }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int V, E;
  cin >> V >> E;
  Graph g(V);
  loop(E) {
    int s, t;
    cin >> s >> t;
    g.add_edge(s, t);
  }
  cout << g.is_cyclic() << endl;

  return 0;
}
