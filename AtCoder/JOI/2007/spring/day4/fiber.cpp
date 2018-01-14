#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
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

int bfs(vector<vector<int>> g) {
  vector<int> color(g.size(),-1);
  int c = 0;
  rep(loop, 0, g.size()) {
    if (color[loop] != -1)
      continue;
    queue<int> q;
    q.push(loop);
    while (not q.empty()) {
      int u = q.front();
      q.pop();
      if (color[u] != -1)
        continue;
      color[u] = c;
      rep(i, 0, g[u].size()) q.push(g[u][i]);
    }
    c++;
  }
  return c;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  vector<vector<int>> g(N); // dist,cost
  rep(i, 0, M) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cout << bfs(g)-1 << endl;

  return 0;
}
