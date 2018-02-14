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
struct Graph {
  vector<vector<int>> g;
  int V;
  vector<int> visited;
  Graph(int V) : V(V), g(V), visited(V) {}
  void add_edge(int s, int t) {
    g[s].push_back(t);
    g[t].push_back(s);
  }
  int CC() {
    fill(all(visited), 0);
    int cnt = 0;
    rep(i, 0, V) {
      if (not visited[i]) {
        dump(i);
        dump(visited);
        dfs(i);
        cnt++;
      }
    }
    return cnt;
  }
  void dfs(int x) {
    if (visited[x])
      return;
    visited[x] = 1;
    rep(i, 0, g[x].size()) { dfs(g[x][i]); }
  }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, M;
  cin >> N >> M;
  Graph g(N);
  rep(i, 0, M) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g.add_edge(a, b);
    g.add_edge(b, a);
  }
  cout << g.CC()-1 << endl;

  return 0;
}
