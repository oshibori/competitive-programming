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
bool isBipartite_proc(int v, int c ) {
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
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  return 0;
}
