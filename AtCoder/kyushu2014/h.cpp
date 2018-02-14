#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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
  edge(int to, int cap, int rev) : to(to), cap(cap), rev(rev) {}
};
struct Graph {
  int V;
  vector<vector<edge>> g;
  vector<int> used;
  Graph(int V) : V(V), g(V), used(V) {}
  void add_edge(int from, int to, int cap) {
    g[from].push_back(edge(to, cap, g[to].size()));
    g[to].push_back(edge(from, 0, g[from].size() - 1));
  }
  int augment_path(int s, int t, int f) {
    if (s == t)
      return f;
    used[s] = true;

    rep(i, 0, g[s].size()) {
      edge &e = g[s][i];
      if (used[e.to] or e.cap <= 0)
        continue;
      int d = augment_path(e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        g[e.to][e.rev].cap += d;
        return d;
      }
    }
    return 0;
  }
  int max_flow(int s, int t) {
    int flow = 0;
    while (1) {
      fill(all(used), 0);
      int f = augment_path(s, t, INF);
      if (f == 0)
        break;
      flow += f;
    }
    return flow;
  }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M, P, G;
  cin >> N >> M >> P >> G;
  Graph g(M + 1);
  int s = M;
  rep(i, 0, G) {
    int l;
    cin >> l;
    g.add_edge(s, l, INF);
  }
  rep(i, 0, N) {
    int from, to, cap;
    cin >> from >> to >> cap;
    g.add_edge(from, to, cap);
  }
  cout << (g.max_flow(s, 0) >= P ? "Yes" : "No") << endl;

  return 0;
}
