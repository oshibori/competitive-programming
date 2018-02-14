#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
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
  // map<pair<int,int>>m;
  set<pair<int, int>> ss;
  vector<int> visited;
  Graph(int V) : V(V), visited(V) {}
  void add_edge(int s, int t) {
    ss.insert(make_pair(s, t));
    ss.insert(make_pair(t, s));
  }
  void CC() {
    fill(all(visited), 0);
    vector<int> ans;
    rep(i, 0, V) {
      if (!visited[i]) {
        ans.push_back(dfs(i));
      }
    }
    sort(all(ans));
    cout << ans.size() << endl;
    rep(i, 0, ans.size()) cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }
  int dfs(int x) {
    if (visited[x])
      return 0;
    visited[x] = true;
    int ret = 1;
    rep(i, 0, V) {
      if (ss.count(make_pair(x, i)))
        continue;
      ret += dfs(i);
    }
    return ret;
  }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  Graph g(N);
  vector<int> deg(N, N - 1);
  rep(i, 0, M) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g.add_edge(a, b);
    deg[a]--, deg[b]--;
  }
  g.CC();

  return 0;
}
