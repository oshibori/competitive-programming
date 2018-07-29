#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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
/*
signed main() {
        int n;
        cin >> n;
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>()); //
node, cost
        rep(i, 0, n) {
                int u, k; cin >> u >> k;
                rep(j, 0, k) {
                        int v, c; cin >> v >> c;
                        // vは頂点の番号、cは有効辺の重み
                        adj[u].push_back(make_pair(v, c));

                }
        }
        auto dijkstra(adj);
        return 0;
}
*/
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int n, m;
  cin >> n >> m;
  int s, t;
  cin >> s >> t;
  s--, t--;
  vector<vector<pair<int, int>>> en(n, vector<pair<int, int>>()); // node, cost
  vector<vector<pair<int, int>>> sunuk(n,
                                       vector<pair<int, int>>()); // node, cost
  loop(m) {
    int u, v, a, b;
    cin >> u >> v >> a >> b;
    u--, v--;
    en[u].push_back(make_pair(v, a));
    en[v].push_back(make_pair(u, a));
    sunuk[u].push_back(make_pair(v, b));
    sunuk[v].push_back(make_pair(u, b));
  }

  int money = 1000000000000000ll;
  auto d1 = dijkstra(en, s);
  auto d2 = dijkstra(sunuk, t);
  priority_queue<pair<int, int>> pq;
  rep(i, 0, n) { pq.push(make_pair(money - (d1[i] + d2[i]), i)); }
  dump(pq);
  rep(i, 0, n) {
    while (pq.top().second < i) {
      pq.pop();
    }
    cout << pq.top().first << endl;
  }

  return 0;
}
