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
// undirected graph
struct ArticulationPoint {
  int V;
  vector<vector<int>> G;
  vector<int> visited, prenum, parent, lowest;
  int timer;
  ArticulationPoint() {}
  ArticulationPoint(int V)
      : V(V), G(V), visited(V), prenum(V), parent(V), lowest(V) {}
  void add_edge(int s, int t) {
    G[s].push_back(t);
    G[t].push_back(s);
  }
  void dfs(int cur, int prev) {
    // ノードcurを訪問した直後の処理
    prenum[cur] = lowest[cur] = timer;
    timer++;
    visited[cur] = true;
    for (auto next : G[cur]) {
      if (not visited[next]) {
        // node-cur からnode-nextへ訪問する直前の処理
        parent[next] = cur;
        dfs(next, cur);
        // node-nextの探索が終了した直後の処理
        lowest[cur] = min(lowest[cur], lowest[next]);
      } else if (next != prev) {
        // edge(cur-->next)がBack-edgeの場合の処理
        lowest[cur] = min(lowest[cur], prenum[next]);
      }
    }
  }
  set<int> art_points(int root = 0) {
    fill(all(visited), false);
    timer = 1;
    // lowestの計算
    for(int i=0;i<V;i++){
      if(not visited[i])
    dfs(root, -1); // 0 is root
    }
    set<int> ap;
    int np = 0;
    for (int i = 1; i < V; i++) {
      int p = parent[i];
      if (p == 0)
        np++;
      else if (prenum[p] <= lowest[i])
        ap.insert(p);
    }
    if (np > 1)
      ap.insert(root);
    return ap;
  }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int V, E;
  cin >> V >> E;
  ArticulationPoint g(V);
  loop(E) {
    int s, t;
    cin >> s >> t;
    g.add_edge(s, t);
  }
  auto x = g.art_points();

  for (auto a : x)
    cout << a << endl;
  return 0;
}
