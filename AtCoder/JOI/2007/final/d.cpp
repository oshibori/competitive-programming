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
void tsort(vector<vector<int>> &g, vector<int> &visited, vector<int> &result,
           int x) {
  if (visited[x])
    return;
  visited[x] = 1;

  rep(i, 0, g[x].size()) { tsort(g, visited, result, g[x][i]); }
  result.push_back(x);
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  vector<vector<int>> g(N);
  rep(i, 0, M) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
  }
  vector<int> visited(N, 0), t1;
  rep(i, 0, N) {
    if (visited[i])
      continue;
    tsort(g, visited, t1, i);
  }
  reverse(all(t1));

  rep(i, 0, N) { cout << t1[i] + 1 << endl; }

  rep(i, 1, N) {
    bool f = true;
    int x = t1[i - 1], y = t1[i];
    rep(j, 0, g[x].size()) {
      if (g[x][j] == y)
        f = false;
    }
    if (f) {
      cout << 1 << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}
