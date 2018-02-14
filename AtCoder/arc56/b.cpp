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

struct Graph {
  int V;
  vector<vector<int>> g;
  vector<int> visited, occupied;
  int S;
  Graph(int V, int S) : S(S), V(V), g(V), visited(V), occupied(V) {}
  void add_edge(int s, int t) {
    g[s].push_back(t);
    g[t].push_back(s);
  }
  void solve() {
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(INF, S));
    vector<int> cost(V, -INF);
    while (pq.size()) {
      auto p = pq.top();
      pq.pop();
      int c = p.first, u = p.second;
      dump(c, u);
      if (c < cost[u]) {
        continue;
      }
      chmax(cost[u], c);
      dump(cost);
      for (auto v : g[u]) {
        int x = min(cost[u], u);
        if (cost[v] < x) {
          pq.push(make_pair(x, v));
        }
      }
    }
    rep(i, 0, V) {
      if (i < cost[i])
        cout << i + 1 << endl;
    }
  }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  int S;
  cin >> S;
  S--;
  Graph g(N, S);
  rep(i, 0, M) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g.add_edge(u, v);
  }
  g.solve();

  return 0;
}
