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
struct BipartiteGraph {
  int V;
  vector<int> match, used;
  vector<vector<int>> G;
  BipartiteGraph(int n) {
    V = n;
    G = vector<vector<int>>(V);
    match = vector<int>(V, -1);
    used = vector<int>(V, 0);
  }
  void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
  }
  bool dfs(int v) {
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
      int u = G[v][i], w = match[u];
      if (w < 0 || !used[w] && dfs(w)) {
        match[v] = u;
        match[u] = v;
        return true;
      }
    }
    return false;
  }
  int bipartite_matching() {
    int res = 0;
    match = vector<int>(V, -1);
    for (int v = 0; v < V; v++) {
      if (match[v] < 0) {
        used = vector<int>(V, 0);
        if (dfs(v))
          res++;
      }
    }
    return res;
  }
  int f() { return (V - count(all(match), -1)) / 2; }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int r, c;
  cin >> r >> c;
  vector<string> v(r);
  rep(i, 0, r) { cin >> v[i]; }
  auto inrange = [&](int x, int y) {
    return 0 <= x and x < r and 0 <= y and y < c;
  };
  BipartiteGraph g(r * c);
  int cnt = 0;
  int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
  rep(i, 0, r) rep(j, 0, c) {
    if (v[i][j] == '.') {
      cnt++;
      rep(k, 0, 4) {
        int x = i + dx[k], y = j + dy[k];
        if (inrange(x, y) && v[x][y] == '.') {
          g.add_edge(i * c + j, x * c + y);
        }
      }
    }
  }
  cout << cnt - g.bipartite_matching() << endl;

  return 0;
}
