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
  int from, to, cost, rev;
  Edge(int from, int to, int cost, int rev)
      : from(from), to(to), cost(cost), rev(rev) {}
};
struct Graph {
  int V;
  vector<vector<Edge>> G;
  vector<int> used;
  Graph(int V) : V(V) {
    used = vector<int>(V, 0);
    G = vector<vector<Edge>>(V);
  }
  void add_edge(int from, int to, int cost = 1) {
    G[from].push_back(Edge(from, to, cost, G[to].size()));
    G[to].push_back(Edge(to, from, 0, G[from].size() - 1));
  }
  int augment_path(int s, int t, int f) {
    if (s == t)
      return f;
    used[s] = true;
    rep(i, 0, G[s].size()) {
      Edge &e = G[s][i];
      if (!used[e.to] && e.cost > 0) {
        int d = augment_path(e.to, t, min(f, e.cost));
        if (d > 0) {
          e.cost -= d;
          G[e.to][e.rev].cost += d;
          return d;
        }
      }
    }
    return 0;
  }
  int max_flow(int s, int t) {
    int flow = 0;
    while (1) {
      used = vector<int>(V, 0);
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

  int N, M;
  cin >> N >> M;
  vector<int> a(N);
  rep(i, 0, N) { cin >> a[i]; }
  vector<int> b(N);
  rep(i, 0, N) { cin >> b[i]; }
  int suma = accumulate(all(a), 0);
  int sumb = accumulate(all(b), 0);
  auto idx = [&](int x) { return x + N; };
  Graph g(2 * N + 2);
  int s = 2 * N, t = s + 1;

  rep(i, 0, N) {
    g.add_edge(s, i, a[i]);
    g.add_edge(idx(i), t, b[i]);
    g.add_edge(i, idx(i), INF);
  }

  rep(i, 0, M) {
    int p, q;
    cin >> p >> q;
    p--, q--;
    g.add_edge(p, idx(q), INF);
    g.add_edge(q, idx(p), INF);
  }
  int f = g.max_flow(s, t);
  if (f == suma and f == sumb) {
    cout << "YES" << endl;
    auto &G = g.G;
    vector<vector<int>> ans(N, vector<int>(N));
    rep(i, 0, N) {
      rep(j, 0, G[i].size()) {
        auto &e = G[i][j];
        if (idx(0) <= e.to and e.to <= idx(N - 1))
          ans[i][e.to - N] = INF - e.cost;
      }
    }
    rep(i, 0, N) rep(j, 0, N) cout << ans[i][j] << (j == N - 1 ? '\n' : ' ');
  } else
    cout << "NO" << endl;

  return 0;
}
