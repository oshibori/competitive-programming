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
#define each(it, c) for (auto it = (c).begin(); it != (c).end(); it++)
#define all(c) c.begin(), c.end()
const int INF =
    sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);

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
bool dfs(vector<vector<pair<int,int>>>&adj,map<int,int>&m,int x){

  bool ret=true;

  rep(i,0,adj[x].size()){
    int u=adj[x][i].first;
    int d=adj[x][i].second;
    if(m.count(u)){
      if(m[x]+d!=m[u])return false;
    }
    else {
      m[u]=m[x]+d;
      ret&=dfs(adj,m,u);
    }
  }
  return ret;

}
signed main() {
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> adj(N, vector<pair<int, int>>()); // node, cost
  vector<int> l(M), r(M), d(M);
  rep(i, 0, M) {
    cin >> l[i] >> r[i] >> d[i];
    l[i]--, r[i]--;
    adj[l[i]].push_back(make_pair(r[i], d[i]));
    adj[r[i]].push_back(make_pair(l[i], -d[i]));
  }
  map<int,int>m;
  bool f=true;
  rep(i,0,N){
    f&=dfs(adj,m,i);
  }
  cout<<(f?"Yes":"No")<<endl;
  return 0;
}
