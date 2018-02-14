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
using P = pair<int, int>;
struct Graph {
  int V;
  vector<vector<int>> g;
  vector<int> dist;
  int x;
  vector<int> h;
  Graph(int V, int x, vector<int> h) : h(h), x(x), V(V), dist(V, -1), g(V) {}
  void add_edge(int s, int t) {
    g[s].push_back(t);
    g[t].push_back(s);
  }
  P dfs(int node, int parent = -1) {
    // first -> dist, second->flag
    dump(node, parent, g[node]);
    P ret;
    ret.second = h[node];
    rep(i, 0, g[node].size()) {
      int y = g[node][i];
      if (y == parent)
        continue;
      P a = dfs(y, node);
      dump(a);
      if (a.second) {
        ret.first += a.first + 2;
        ret.second = 1;
      }
    }
    return ret;
  }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, x;
  cin >> N >> x;
  vector<int> h(N);
  x--;
  rep(i, 0, N) { cin >> h[i]; }
  Graph g(N, x, h);
  rep(i, 0, N - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g.add_edge(a, b);
  }
  cout << g.dfs(x).first << endl;

  return 0;
}
