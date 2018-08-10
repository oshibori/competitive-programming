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
using pii = pair<int, int>;
// template<class T> ostream &operator<<(ostream &os,T &t){dump(t);return os;}
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
struct UnionFind {
  // https://beta.atcoder.jp/contests/arc099/submissions/2926148
  // written by ei1333
  vector<int> data, s;
  map<int, vector<int>> cc;
  map<int, int> rev;

  UnionFind() {}
  UnionFind(int sz) { data.assign(sz, -1); }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)
      return (false);
    if (data[x] > data[y])
      swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k) {
    if (data[k] < 0)
      return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) { return (-data[find(k)]); }
};
struct Edge {
  // source, target, cost
  int s, t, c;
  Edge() {}
  Edge(int s, int t, int c) : s(s), t(t), c(c) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
ostream &operator<<(ostream &os, Edge &e) {
  os << "(" << e.s << ", " << e.t << ", " << e.c << " )";
  return os;
}
ostream &operator<<(ostream &os, Edges &es) {
  os << "[ ";
  rep(i, 0, es.size()) { os << es[i] << (i == es.size() - 1 ? "" : ", "); }
  os << "]";
  return os;
}

ostream &operator<<(ostream &os, Graph &g) {
  os << "{ ";
  rep(i, 0, g.size()) { os << g[i] << (i == g.size() - 1 ? "" : ", "); }
  os << " }";
  return os;
}
vector<int> dijkstra(const Graph &g, int s) {
  vector<int> d(g.size(), INF), color(g.size());
  d[s] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  // cost,vertex
  pq.push(pii(0, s));
  while (pq.size()) {
    auto v = pq.top();
    pq.pop();

    if (d[v.second] < v.first)
      continue;

    color[v.second] = true;

    for (auto e : g[v.second]) {
      if (not color[e.t] and chmin(d[e.t], d[v.second] + e.c)) {
        pq.push(pii(d[e.t], e.t));
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

  vector<int> p(M), q(M), c(M);
  rep(i, 0, M) {
    cin >> p[i] >> q[i] >> c[i];
    p[i]--, q[i]--;
  }

  map<pii, int> idx; // vertex ,company
  int cnt = 0;
  rep(i, 0, M) {
    if (!idx.count(pii(p[i], c[i]))) {
      idx[pii(p[i], c[i])] = cnt++;
    }
    if (!idx.count(pii(q[i], c[i]))) {
      idx[pii(q[i], c[i])] = cnt++;
    }
  }
  rep(i, 0, N) { idx[pii(i, -1)] = cnt++; }
  Graph g(idx.size());

  for (auto v : idx) {
    g[v.second].push_back(Edge(-1, idx[pii(v.first.first, -1)], 0));
    g[idx[pii(v.first.first, -1)]].push_back(Edge(-1, v.second, 1));
  }

  rep(i, 0, M) {
    g[idx[pii(p[i], c[i])]].push_back(Edge(-1, idx[pii(q[i], c[i])], 0));
    g[idx[pii(q[i], c[i])]].push_back(Edge(-1, idx[pii(p[i], c[i])], 0));
  }

  auto d = dijkstra(g, idx[pii(0, -1)]);

  if (d[idx[pii(N - 1, -1)]] == INF) {
    cout << -1 << endl;
  } else {
    cout << d[idx[pii(N - 1, -1)]] << endl;
  }

  return 0;
}
