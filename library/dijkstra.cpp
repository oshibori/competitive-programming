// copied from https://github.com/minaminao/competitive-programming/blob/master/library/library/GraphTheory.cpp written by minaminao
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

inline ostream &operator<<(ostream &os, const Edges &es) {
  os << "[";
  for (int i = 0; i < es.size(); i++) {
    os << es[i] << (i == es.size() - 1 ? "" : ", ");
  }
  os << "]";
  return os;
}
inline ostream &operator<<(ostream &os, const Graph &g) {
  os << "{";
  for (int i = 0; i < g.size(); i++) {
    os << g[i] << (i == g.size() - 1 ? "" : ", ");
  }
  os << "}";
  return os;
}
void addArc(Graph &g, int s, int d, Weight w = 1) {
  g[s].emplace_back(s, d, w);
}
void addEdge(Graph &g, int a, int b, Weight w = 1) {
  addArc(g, a, b, w);
  addArc(g, b, a, w);
}

vector<int> dijkstra(const Graph &g, int s, Array &dist) {
  int n = g.size();
  assert(s < n);
  enum { WHITE, GRAY, BLACK };
  vector<int> color(n, WHITE);
  color[s] = GRAY;
  vector<int> prev(n, -1);
  dist.assign(n, INF);
  dist[s] = 0;
  using State = tuple<Weight, int, int>; //始点からの最短距離 子 親
  priority_queue<State, vector<State>, greater<State>> pq;
  pq.emplace(0, s, -1);
  while (pq.size()) {
    Weight d;
    int v, u;
    tie(d, v, u) = pq.top();
    pq.pop();
    if (dist[v] < d)
      continue;
    color[v] = BLACK;
    prev[v] = u;
    for (auto &e : g[v]) {
      if (color[e.d] == BLACK)
        continue;
      if (dist[e.d] > dist[v] + e.w) {
        dist[e.d] = dist[v] + e.w;
        pq.emplace(dist[e.d], e.d, v);
        color[e.d] = GRAY;
      }
    }
  }
  return prev;
}
