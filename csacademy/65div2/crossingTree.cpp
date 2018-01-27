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

vector<int> dfs(vector<int> &visited, vector<vector<int>> &g, int x) {
  dump(x,visited);

  visited[x] = 1;
  vector<int> ret;
  ret.push_back(x);
  vector<vector<int>> v;
  rep(i, 0, g[x].size()) {
    if (!visited[g[x][i]]) {
      auto a = dfs(visited, g, g[x][i]);
      v.push_back(a);
    }
  }
  sort(all(v),
       [&](vector<int> &p, vector<int> &q) { return p.size() < q.size(); });
  dump(v);

  rep(i, 0, v.size()) {
    rep(j, 0, v[i].size()) { ret.push_back(v[i][j]); }
    if(g[x].size()>2 and i<v.size()-1)ret.push_back(x);
  }
  dump(ret);
  return ret;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<vector<int>> g(N, vector<int>());
  rep(i, 0, N - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int s;
  rep(i, 0, N) {
    if (g[i].size() == 1)
      s = i;
  }

  vector<int> visited(N, 0);
  auto ans = dfs(visited, g,s);
  cout << ans.size()-1 << endl;
  rep(i, 0, ans.size()) cout << ans[i]+1 << (i == ans.size() - 1 ? '\n' : ' ');

  return 0;
}
