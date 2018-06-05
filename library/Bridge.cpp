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
// Bridges in a undirected graph
struct Bridge {
  int V;
  vector<vector<int>> G;
  vector<int> visited, lowest, parent, prenum;
  Bridge() {}
  Bridge(int V) : V(V), G(V), visited(V), prenum(V), parent(V), lowest(V) {}
  void add_edge(int s, int t) {
    G[s].push_back(t);
    G[t].push_back(s);
  }
  void dfs(int cur, int prev, vector<pair<int, int>> &b) {
    static int time = 0;
    visited[cur] = true;
    prenum[cur] = lowest[cur] = ++time;
    for (auto next : G[cur]) {
      if (not visited[next]) {
        parent[next] = cur;
        dfs(next, cur, b);
        lowest[cur] = min(lowest[cur], lowest[next]);
        if (lowest[next] > prenum[cur]) {
          b.push_back(make_pair(cur, next));
        }
      } else if (next != prev) {
        lowest[cur] = min(lowest[cur], lowest[next]);
      }
    }
  }
  vector<pair<int, int>> bridges() {
    fill(all(visited), false);
    vector<pair<int, int>> b;
    for (int i = 0; i < V; i++) {
      if (not visited[i]) {
        dfs(i, -1, b);
      }
    }
    return b;
  }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int V, E;
  cin >> V >> E;
  Bridge g(V);
  loop(E) {
    int s, t;
    cin >> s >> t;
    g.add_edge(s, t);
  }
  auto b = g.bridges();
  for (auto &e : b) {
    if (e.first > e.second)
      swap(e.first, e.second);
  }
  sort(all(b));
  for (auto e : b) {
    cout << e.first << " " << e.second << endl;
  }
  return 0;
}
