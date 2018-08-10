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
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, Q;
  cin >> N >> Q;
  // vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>()); // node,
  // cost
  vector<vector<int>> g(N, vector<int>());
  vector<int> deg(N, 0);
  vector<int> p;
  rep(i, 0, N - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
    deg[a]++, deg[b]++;
  }
  dump(g);
  rep(i, 0, N) {
    if (deg[i] == 1)
      p.push_back(i);
  }
  dump(p);

  vector<int> dist(N), visited(N, 0);
  for (int cnt = 0, x = p[0]; cnt < N;) {
    visited[x] = 1;
    dist[cnt] = x;

    rep(i, 0, g[x].size()) {
      dump(i);
      if (!visited[g[x][i]]) {
        x = g[x][i];
        dump(x);
        break;
      }
    }
    cnt++;
  }
  dump(dist);

  int l = 0, r = N - 1;
  int ans;
  while (Q--) {
    int m = (r + l) / 2;
    cout << "? " << dist[l] + 1 << " " << dist[r] + 1 << endl;
    cin >> ans;
    if (ans == 0) {
      cout << "! " << dist[m] + 1 << endl;
      break;
    } else {
      ans--;
      if (ans == dist[l]) {
        r = m;

      } else
        l = m + 1;
    }
  }

  return 0;
}
