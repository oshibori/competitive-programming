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

struct SCC {
  int V;
  vector<vector<int>> G, rG, SC;
  vector<int> vs, cmp; // post order, topological order
  vector<bool> used;

  SCC() {}
  SCC(int V) : V(V), G(V), rG(V), used(V), cmp(V) {}
  void add_arc(int s, int t) {
    G[s].push_back(t);
    rG[t].push_back(s);
  }
  void dfs(int v) {
    used[v] = true;
    for (int i : G[v]) {
      if (not used[i])
        dfs(i);
    }
    vs.push_back(v);
  }
  void rdfs(int v, int k) {
    used[v] = true;
    cmp[v] = k;
    for (int i : rG[v]) {
      if (not used[i])
        rdfs(i, k);
    }
  }
  int scc() {
    fill(all(used), false);
    vs.clear();
    SC.clear();
    rep(v, 0, V) {
      if (not used[v])
        dfs(v);
    }
    fill(all(used), false);
    int k = 0;
    rrep(i, 0, vs.size()) {
      if (not used[vs[i]])
        rdfs(vs[i], k++);
    }
    SC.resize(k);
    rep(i, 0, V) { SC[cmp[i]].emplace_back(i); }
    rep(i, 0, SC.size()) { sort(all(SC[i])); }
    return k;
  }
};
