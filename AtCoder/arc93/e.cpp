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
using pii = pair<int, int>;
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
struct DisjointSet {
  // ２つのグループを１つにまとめる　と　2つの要素が同じグループに所属しているかどうかを判定する
  vector<int> rank, p, S; // p->parent  S[findSet(v)] ->連結成分の大きさ
  DisjointSet() {}
  DisjointSet(int size) {
    S.resize(size, 1);
    rank.resize(size, 0);
    p.resize(size, 0);
    rep(i, 0, size) makeSet(i);
  }
  void makeSet(int x) {
    p[x] = x;
    rank[x] = 0;
  }
  bool same(int x, int y) { // 判定する
    return findSet(x) == findSet(y);
  }
  void unite(int x, int y) { // 連結するときにはこれを使う
    if (same(x, y))
      return;
    link(findSet(x), findSet(y));
  }
  void link(int x, int y) {
    if (rank[x] > rank[y]) {
      p[y] = x;
    } else {
      p[x] = y;
      if (rank[x] == rank[y]) {
        rank[y]++;
      }
    }

    S[x] = S[y] = S[x] + S[y];
  }
  int findSet(int x) {
    if (x != p[x]) {
      p[x] = findSet(p[x]); // path compression
    }
    return p[x];
  }
  int connectedComponentSize(int x) { return S[findSet(x)]; }
};

struct Edge {
  int source, target, cost;
  Edge(int source = 0, int target = 0, int cost = 0)
      : source(source), target(target), cost(cost){};

  bool operator<(const Edge &e) const { return cost < e.cost; }
};
using Graph = vector<vector<Edge>>;
void dfs(int s, int t, int c, vector<vector<int>> &pathMax, Graph &g) {
  dump(s, t, c);
  pathMax[s][t] = c;
  for (auto e : g[t]) {
    if (pathMax[s][e.target] == -1)
      dfs(s, e.target, max(c, e.cost), pathMax, g);
  }
}
long long modpow(long long base, long long exponent, long long mod) {
  long long res = 1;
  while (exponent > 0) {
    if (exponent & 1)
      res = res * base % mod;
    base = base * base % mod;
    exponent >>= 1;
  }
  return res;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, M;
  cin >> N >> M;
  int X;
  cin >> X;
  vector<Edge> edges;
  rep(i, 0, M) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    edges.push_back(Edge(u, v, w));
  }
  vector<vector<Edge>> mst(N);
  vector<Edge> remain;
  sort(all(edges));
  int S = 0;
  DisjointSet dset(N);
  rep(i, 0, edges.size()) {
    Edge e = edges[i];
    if (!dset.same(e.source, e.target)) {

      mst[e.source].push_back(e);
      swap(e.source, e.target);
      mst[e.source].push_back(e);

      S += e.cost;
      dset.unite(e.source, e.target);
    } else {
      remain.push_back(e);
    }
  }

  vector<vector<int>> pathMax(N, vector<int>(N, -1));
  rep(i, 0, N) { dfs(i, i, 0, pathMax, mst); }
  auto diff = [&](Edge e) { return e.cost - pathMax[e.source][e.target]; };
  int D = X - S;
  dump(D);
  if (D < 0) {
    cout << 0 << endl;
  } else {
    int lower = 0, equal = 0, upper = 0;
    for (auto e : remain) {
      dump(diff(e), e.source, e.target, e.cost, pathMax[e.source][e.target]);
      if (diff(e) < D)
        lower++;
      else if (diff(e) == D)
        equal++;
      else
        upper++;
    }
    dump(lower, equal, upper);

    int ans = (2 * (modpow(2, equal, MOD) - 1) * modpow(2, upper, MOD)) % MOD;
    if (D == 0) {
      (ans += (modpow(2, N - 1, MOD) - 2) * modpow(2, M - (N - 1), MOD)) %= MOD;
    }
    cout << ans << endl;
  }

  return 0;
}
