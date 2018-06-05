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
struct SCC {
  int V;
  vector<vector<int>> G, rG;
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
    return k;
  }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, M;
  cin >> N >> M;
  vector<int> r(N);
  rep(i, 0, N) { cin >> r[i]; }
  vector<vector<int>> sw(N);
  rep(i, 0, M) {
    int x;
    cin >> x;
    loop(x) {
      int y;
      cin >> y;
      y--;
      sw[y].push_back(i);
    }
  }
  SCC g(2 * M);
  auto notidx = [&](int x) { return x >= M ? x - M : x + M; };
  rep(i, 0, N) {
    if (r[i]) {
      g.add_arc(sw[i][0], sw[i][1]);
      g.add_arc(sw[i][1], sw[i][0]);
      g.add_arc(notidx(sw[i][0]), notidx(sw[i][1]));
      g.add_arc(notidx(sw[i][1]), notidx(sw[i][0]));
    } else {
      g.add_arc(notidx(sw[i][0]), sw[i][1]);
      g.add_arc(notidx(sw[i][1]), sw[i][0]);
      g.add_arc((sw[i][0]), notidx(sw[i][1]));
      g.add_arc((sw[i][1]), notidx(sw[i][0]));
    }
  }
  g.scc();
  bool f = true;
  rep(i, 0, M) { f &= g.cmp[i] != g.cmp[i + M]; }
  cout << (f ? "YES" : "NO") << endl;

  return 0;
}
