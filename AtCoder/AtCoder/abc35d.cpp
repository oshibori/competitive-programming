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
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

const int W = 0, B = 1;
//重み付き有効グラフの隣接リスト表現
vector<int> dijkstra(const vector<vector<pair<int, int>>> &g,int s) {
	int n = g.size();
	priority_queue<pair<int, int>>pq; // cost,node
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

	int N, M, T; cin >> N >> M >> T;
	vector<int>A(N); rep(i, 0, N)cin >> A[i];
	vector < vector < pair<int, int>>>graph(N),graph_rev(N);
	rep(i, 0, M) {
		int a, b, c; cin >> a >> b >> c;
		a--, b--;
		graph[a].emplace_back(make_pair(b, c));
		graph_rev[b].emplace_back(make_pair(a, c));

	}
	vector<int>forward(dijkstra(graph, 0)), back(dijkstra(graph_rev, 0));
	dump(forward); dump(back);
	int ans(0);
	rep(i, 0, N) {
		chmax(ans, max(0LL, (T - (forward[i] + back[i])))*A[i]);
	}
	cout << ans << endl;
	return 0;
}