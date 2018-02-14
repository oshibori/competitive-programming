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

struct edge {
  int to, cap, cost, rev;
  edge(int to, int cap, int cost, int rev)
      : to(to), cap(cap), cost(cost), rev(rev) {}
};
struct Graph {
  int V;
  vector<vector<edge>> G;
  vector<int> dist, prev_v, prev_e;
  Graph(int V) : V(V), dist(V), prev_v(V), prev_e(V), G(V) {}
  void add_edge(int from, int to, int cap, int cost) {
    G[from].push_back(edge(to, cap, cost, G[to].size()));
    G[to].push_back(edge(from, 0, -cost, G[from].size() - 1));
  }
  int min_cost_flow(int s, int t, int f) {
    int res = 0;
    while (f > 0) {
      fill(all(dist), INF);
      dist[s] = 0;
      bool update = true;
      while (update) {
        update = false;
        rep(v, 0, V) {
          if (dist[v] == INF)
            continue;
          rep(i, 0, G[v].size()) {
            edge &e = G[v][i];
            if (e.cap > 0 and dist[e.to] > dist[v] + e.cost) {
              dist[e.to] = dist[v] + e.cost;
              prev_v[e.to] = v;
              prev_e[e.to] = i;
              update = true;
            }
          }
        }
      }
      if (dist[t] == INF)
        return -1;
      int d = f;
      for (int v = t; v != s; v = prev_v[v]) {
        chmin(d, G[prev_v[v]][prev_e[v]].cap);
      }
      f -= d;
      res += d * dist[t];
      for (int v = t; v != s; v = prev_v[v]) {
        edge &e = G[prev_v[v]][prev_e[v]];
        e.cap -= d;
        G[v][e.rev].cap += d;
      }
    }
    return res;
  }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int V, E, F;
  cin >> V >> E >> F;
  Graph g(V);
  rep(i, 0, E) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    g.add_edge(a, b, c, d);
  }
  cout << g.min_cost_flow(0, V - 1, F) << endl;

  return 0;
}
