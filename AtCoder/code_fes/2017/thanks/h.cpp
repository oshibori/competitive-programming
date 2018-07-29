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
struct DisjointSet {
  vector<int> rank, p;
  DisjointSet() {}
  DisjointSet(int size) {
    rank.resize(size, 0);
    p.resize(size, 0);
    rep(i, 0, size) makeSet(i);
  }
  void makeSet(int x) {
    p[x] = x;
    rank[x] = 0;
  }
  bool same(int x, int y) { return findSet(x) == findSet(y); }
  bool unite(int x, int y) {
    if (same(x, y))
      return false;
    link(findSet(x), findSet(y));
    return true;
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
  }
  int findSet(int x) {
    if (x != p[x]) {
      p[x] = findSet(p[x]); // path compression
    }
    return p[x];
  }
};

int N, M;
vector<vector<pair<int, int>>> g;
vector<int> root, depth;
vector<vector<int>> parent, max_cost;
void dfs(int, int, int);
int L;
void init() {
  L = log2(N);
  L++;
  depth.resize(N, -1);
  parent.resize(L, vector<int>(N));
  max_cost.resize(L, vector<int>(N, -1));
  rep(i, 0, N) {
    if (depth[i] == -1) {
      root.push_back(i);
      dfs(i, -1, 0);
    }
  }

  rep(k, 1, L) {
    rep(i, 0, N) {
      if (parent[k - 1][i] == -1) {
        parent[k][i] = -1;
        max_cost[k][i] = -1;
      } else {
        parent[k][i] = parent[k - 1][parent[k - 1][i]];
        if (parent[k][i] != -1) {
          max_cost[k][i] =
              max(max_cost[k - 1][i], max_cost[k - 1][parent[k - 1][i]]);
        }
      }
    }
  }
  dump(depth, root);
  dump(parent);
  dump(max_cost);
}
void dfs(int x, int p, int d) {
  depth[x] = d;
  parent[0][x] = p;
  for (auto q : g[x]) {
    if (q.first != p) {
      max_cost[0][q.first] = q.second;
      dfs(q.first, x, d + 1);
    }
  }
}
int query(int u, int v) {
  int u_c = -1, v_c = -1;
  if (depth[u] > depth[v])
    swap(u, v);
  rep(k, 0, L) {
    if ((depth[v] - depth[u]) >> k & 1) {
      chmax(v_c, max_cost[k][v]);
      v = parent[k][v];
    }
  }

  if(u==v){
    return max(u_c,v_c);
  }


  rrep(k, 0, L) {
    if (parent[k][u] != parent[k][v]) {
      chmax(v_c, max_cost[k][v]);
      chmax(u_c, max_cost[k][u]);
      u = parent[k][u];
      v = parent[k][v];
    }
  }
  chmax(v_c, max_cost[0][v]);
  chmax(u_c, max_cost[0][u]);
  return max(v_c, u_c);
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  cin >> N >> M;
  DisjointSet uf(N);
  g.resize(N);

  vector<int> a(M), b(M);
  rep(i, 0, M) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;

    if (uf.unite(a[i], b[i])) {
      g[a[i]].push_back(make_pair(b[i], i + 1));
      g[b[i]].push_back(make_pair(a[i], i + 1));
    }
  }
  init();
  int Q;
  cin >> Q;
  loop(Q) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (not uf.same(x, y)) {
      cout << -1 << endl;
    } else {
      cout << query(x, y) << endl;
    }
  }

  return 0;
}
