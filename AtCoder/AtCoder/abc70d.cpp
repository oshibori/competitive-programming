#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

// O( ( |V| + |E| ) * log|V| )
const int W = 0, B = 1;
//重み付き有効グラフの隣接リスト表現
vector<int> dijkstra(const vector<vector<pair<int, int>>> &g, int s) {
	int n = g.size();
	priority_queue<pair<int, int>>pq;// cost, node
	vector<int>color(n, W), d(n, INF);
	d[s] = 0;
	pq.push(make_pair(0, s));

	while (!pq.empty()) {
		pair<int, int>f(pq.top()); pq.pop();// d[v], v
		color[f.second] = B;

		if (d[f.second] < (-1)*f.first)continue; // 最小値を取り出し、それが最短でなければ無視

		rep(i, 0, g[f.second].size()) {
			pair<int, int>v(g[f.second][i]);
			if (color[v.first] != B&&d[f.second] + v.second < d[v.first]) {
				d[v.first] = d[f.second] + v.second;
				pq.push(make_pair(d[v.first] * (-1), v.first)); // priority_queueはデフォルトで大きい値を優先するため-1を掛ける
			}
		}
	}
	return d;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<vector<pair<int, int>>> adj(N, vector<pair<int, int>>());
	rep(i, 0, N-1) {
		int a, b, c; cin >> a >> b >> c;
		a--, b--;
		adj[a].emplace_back(make_pair(b, c));
		adj[b].emplace_back(make_pair(a, c));
	}

	int Q, K; cin >> Q >> K;
	K--;
	auto d = dijkstra(adj, K);
	rep(i, 0, Q) {
		int x, y; cin >> x >> y;

		x--, y--;
		cout << d[x] + d[y] << endl;
	}
	return 0;
}