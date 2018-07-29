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

// isBipartite ? =======================================================
vector<vector<int>> g;
vector<int> color;
bool isBipartite_proc(int, int);
bool isBipartite() {
  color.resize(g.size(), 0);
  rep(i, 0, g.size()) {
    if (color[i] == 0) {
      if (!isBipartite_proc(i, 1))
        return false;
    }
  }
  return true;
}
bool isBipartite_proc(int v, int c) {
  color[v] = c;
  for (auto u : g[v]) {
    if (color[u] == c)
      return false;
    if (color[u] == 0 and !isBipartite_proc(u, -c))
      return false;
  }
  return true;
}
//======================================================================
void dfs(int v, int c, int &x, int &y) {
  color[v] = c;
  (c == 1 ? x++ : y++);
  for (auto u : g[v]) {
    if (color[u] == 0)
      dfs(u, -c, x, y);
  }
}
vector<pair<int, int>> partial() {
  color.assign(g.size(), 0);
  vector<pair<int, int>> ret;
  rep(i, 0, g.size()) {
    if (color[i] == 0) {
      int x = 0, y = 0;
      dfs(i, 1, x, y);
      ret.push_back(make_pair(x, y));
    }
  }
  return ret;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, M;
  cin >> N >> M;
  g.resize(N);
  vector<vector<int>> v(N, vector<int>(N, 1));
  rep(i, 0, N) v[i][i] = 0;
  rep(i, 0, M) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    v[a][b] = v[b][a] = 0;
  }
  rep(i, 0, N) rep(j, 0, N) {
    if (v[i][j])
      g[i].push_back(j);
  }

  if (!isBipartite()) {
    cout << -1 << endl;
    return 0;
  }

  auto p = partial();

  set<pair<int, int>> s;
  s.insert(make_pair(0, 0));
  for (auto x : p) {
    set<pair<int, int>> tmp;
    for (auto y : s) {
      tmp.insert(make_pair(x.first + y.first, x.second + y.second));
      tmp.insert(make_pair(x.first + y.second, x.second + y.first));
    }
    swap(s, tmp);
  }
  int ans = INF;
  for (auto y : s) {
    chmin(ans, y.first * (y.first - 1) / 2 + y.second * (y.second - 1) / 2);
  }
  cout << ans << endl;

  return 0;
}
