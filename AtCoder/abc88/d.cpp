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
// O( ( |V| + |E| ) * log|V| )
const int W = 0, B = 1;
//重み付き有効グラフの隣接リスト表現
vector<int> dijkstra(const vector<vector<pair<int, int>>> &g, int s) {
  int n = g.size();
  priority_queue<pair<int, int>> pq; // cost, node
  vector<int> color(n, W), d(n, INF);
  d[s] = 0;
  pq.push(make_pair(0, s));

  while (!pq.empty()) {
    pair<int, int> f(pq.top());
    pq.pop(); // d[v], v
    color[f.second] = B;

    if (d[f.second] < (-1) * f.first)
      continue; // 最小値を取り出し、それが最短でなければ無視

    rep(i, 0, g[f.second].size()) {
      pair<int, int> v(g[f.second][i]);
      if (color[v.first] != B && d[f.second] + v.second < d[v.first]) {
        d[v.first] = d[f.second] + v.second;
        pq.push(make_pair(
            d[v.first] * (-1),
            v.first)); // priority_queueはデフォルトで大きい値を優先するため-1を掛ける
      }
    }
  }
  return d;
}
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int h, w;
bool inrange(int x, int y) { return 0 <= x and x < h and 0 <= y and y < w; }
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) { cin >> s[i]; }
  vector<vector<pair<int, int>>> adj(h * w,
                                     vector<pair<int, int>>()); // node, cost
  auto idx = [&](int x, int y) { return x * w + y; };

  int black = 0, white = 0;
  rep(i, 0, h) rep(j, 0, w) {
    s[i][j] == '#' ? black++ : white++;
    if (s[i][j] == '#')
      continue;
    rep(k, 0, 4) {
      int x = i + dx[k], y = j + dy[k];
      if (not inrange(x, y) or s[x][y] == '#')
        continue;
      adj[idx(i, j)].push_back(make_pair(idx(x, y), 1));
    }
  }
  auto d = dijkstra(adj, 0);
  if (d[idx(h - 1, w - 1)] == INF) {
    cout << -1 << endl;
  } else {
    dump(white,d[idx(h-1,w-1)]);
    cout << white - d[idx(h - 1, w - 1)]-1 << endl;
  }

  return 0;
}
