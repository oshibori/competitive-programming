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
struct Edge {
  int source, target, weight;
  Edge(int source, int target, int weight)
      : source(source), target(target), weight(weight) {}
};
struct Graph {
  int V;
  vector<vector<Edge>> g;
  Graph(int V) : V(V), g(V) {}
  void add_arc(int s,int t,int w=1){g[s].emplace_back(s,t,w);}
  void add_edge(int s, int t, int w = 1) { add_arc(s,t,w);add_arc(t,s,w); }
  void dfs(vector<int> &x, int v, int p, int d) {
    x[v] = d;
    rep(i, 0, g[v].size()) {
      Edge e = g[v][i];
      int u = e.target;
      if (u == p)
        continue;
      dfs(x, u, v, d + e.weight);
    }
  }
  int diameter() {
    vector<int> d(V);
    dfs(d, 0, -1, 0);
    int m = max_element(all(d)) - d.begin();
    dfs(d, m, -1, 0);
    return *max_element(all(d));
  }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  Graph g(N);
  rep(i, 0, N - 1) {
    int s, t, w;
    cin >> s >> t >> w;
    g.add_edge(s, t, w);
  }
  cout << g.diameter() << endl;
  return 0;
}
