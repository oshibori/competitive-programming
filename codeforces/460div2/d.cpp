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

struct Graph {
  int V;
  vector<vector<int>> g;
  vector<int> visited, recStack;
  string s;
  vector<int> indeg;
  Graph(int V, string s)
      : V(V), g(V), visited(V), s(s), indeg(V), recStack(V) {}
  void add_edge(int s, int t) { g[s].push_back(t); }
  bool is_cyclic() {
    rep(i, 0, V) {
      sort(all(g[i]));
      g[i].erase(unique(all(g[i])), g[i].end());
    }
    fill(all(visited), 0);
    fill(all(recStack), 0);

    rep(i, 0, V) {
      if (isCyclicUtil(i))
        return true;
    }
    return false;
  }
  bool isCyclicUtil(int v) {
    if (!visited[v]) {
      visited[v] = recStack[v] = true;

      rep(i, 0, g[v].size()) {
        int x = g[v][i];
        if (!visited[x] and isCyclicUtil(x))
          return true;
        else if (recStack[x])
          return true;
      }
    }
    recStack[v] = false;
    return false;
  }
  int largest_path() {
    rep(i, 0, V) {
      rep(j, 0, g[i].size()) { indeg[g[i][j]]++; }
    }
    int ret = 0;
    map<char, int> m;
    vector<map<char, int>> memo(V);
    rep(i, 0, V) {
      if (indeg[i] == 0) {
        auto a = dfs(i, m, memo);
        auto f = max(a);
        chmax(ret, f);
      }
    }
    return ret;
  }
  int max(map<char,int>&m){
    int ret=0;
    for(auto &o:m){
      chmax(ret,o.second);
    }
    return ret;
  }
  map<char, int> dfs(int x, map<char, int> m, vector<map<char, int>> &memo) {
    if (!memo[x].empty())
      return memo[x];
    m[s[x]]++;
    if (g[x].size() == 0) {
      return memo[x] = m;
    }
    int ret = 0;
    rep(i, 0, g[x].size()) {
      auto a = dfs(g[x][i], m, memo);
      auto f = max(a);
      if (chmax(ret, f)) {
        memo[x] = a;
      }
    }
    return memo[x];
  }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  string s;
  cin >> s;
  Graph g(N, s);
  rep(i, 0, M) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g.add_edge(a, b);
  }

  if (g.is_cyclic()) {
    cout << -1 << endl;
  } else {
    cout << g.largest_path() << endl;
  }

  return 0;
}
