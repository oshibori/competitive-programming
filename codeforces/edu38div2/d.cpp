#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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
/*
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
*/
// O( ( |V| + |E| ) * log|V| )
const int W = 0, B = 1;
//重み付き有効グラフの隣接リスト表現
vector<int> dijkstra(const vector<vector<pair<int, int>>> &g, vector<int> &a) {
  int n = g.size();
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq; // cost, node
  vector<int> color(n, W), d(n, INF);
  // d[s] = 0;
  //  pq.push(make_pair(0, s));
  rep(i, 0, n) { pq.push(make_pair(a[i], i)); }

  while (!pq.empty()) {
    pair<int, int> f(pq.top());
    pq.pop(); // d[v], v
    color[f.second] = B;

    if (a[f.second] < f.first)
      continue; // 最小値を取り出し、それが最短でなければ無視

    rep(i, 0, g[f.second].size()) {
      pair<int, int> v(g[f.second][i]);
      if (color[v.first] != B && a[f.second] + 2*v.second < a[v.first]) {
        a[v.first] = a[f.second] + 2*v.second;
        pq.push(make_pair(
            a[v.first],
            v.first)); // priority_queueはデフォルトで大きい値を優先するため-1を掛ける
      }
    }
  }
  return d;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> adj(N, vector<pair<int, int>>()); // node, cost
  loop(M) {
    int v, u, w;
    cin >> v >> u >> w;
    v--, u--;
    adj[v].push_back(make_pair(u, w));
    adj[u].push_back(make_pair(v, w));
  }
  vector<int> a(N);
  rep(i, 0, N) { cin >> a[i]; }
  dijkstra(adj, a);
  rep(i, 0, N) cout << a[i] << (i == N - 1 ? '\n' : ' ');

  return 0;
}
