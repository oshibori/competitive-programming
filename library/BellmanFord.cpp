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
void addArc(Graph &g, int s, int d, Weight w = 1) {
  g[s].emplace_back(s, d, w);
}
void addEdge(Graph &g, int a, int b, Weight w = 1) {
  addArc(g, a, b, w);
  addArc(g, b, a, w);
}

//単一始点最短経路(負閉路あり) // Bellman-Ford O(|V||E|) // dist:
// 始点から各頂点までの最短距離 //戻り値: 最短経路木の親頂点, 負閉路なし:true
// あり:false
pair<vector<int>, bool> bellmanFord(const Graph &g, int s, Array &dist) {
  int n = g.size();
  vector<int> prev(n, -1);
  Edges es;
  for (int i = 0; i < n; i++)
    for (auto &e : g[i])
      es.emplace_back(e);
  dist.assign(n, INF);
  dist[s] = 0;
  bool negative_cycle = false;
  for (int i = 0;; i++) {
    bool update = false;
    for (auto &e : es) {
      if (dist[e.s] != INF && dist[e.d] > dist[e.s] + e.w) {
        dist[e.d] = dist[e.s] + e.w;
        prev[e.d] = e.s;
        update = true;
      }
    }
    if (!update)
      break;
    if (i > n) {
      negative_cycle = true;
      break;
    }
  }
  return make_pair(prev, !negative_cycle);
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int V, E, r;
  cin >> V >> E >> r;
  Graph g(V);
  loop(E) {
    int s, t, d;
    cin >> s >> t >> d;
    addArc(g, s, t, d);
  }
  vector<int> dist;
  auto x = bellmanFord(g, r, dist);

  if (not x.second) {
    cout << "NEGATIVE CYCLE" << endl;
  } else {
    rep(i, 0, V) {
      if (dist[i] == INF)
        cout << "INF" << endl;
      else
        cout << dist[i] << endl;
    }
  }

  return 0;
}
