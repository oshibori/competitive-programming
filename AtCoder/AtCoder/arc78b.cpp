#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
using Graph = vector<vector<pair<int, int>>>;
void assign_color(Graph &g, vector<int>&c, int s) {
	queue<int>q;
	q.push(s);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		if (c[x] == 0)c[x] = 1;
		else continue;

		rep(i, 0, g[x].size()) {
			q.push(g[x][i].first);
		}
	}
}
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
	Graph g(N);
	rep(i, 0, N - 1) {
		int a, b; cin >> a >> b;
		a--, b--;
		g[a].emplace_back(make_pair(b, 1)); g[b].emplace_back(make_pair(a, 1));
	}
	vector<int>b(N, 0), w(N, 0);
	b[N - 1] = -1, w[0] = -1;
	//assign_color(g, b, 0); assign_color(g, w, N - 1);

	auto d_from1 = dijkstra(g, 0), d_fromN = dijkstra(g, N - 1);
	int cntb(0), cntw(0), cntelse(0);
	//rep(i, 0, N) {
	//	if (b[i] == 1 && w[i] == 1) {
	//		if (d_from1[i] <= d_fromN[i])cntb++;
	//		else cntw++;
	//	}
	//	else if (b[i] == 1 && w[i] != 1)cntb++;
	//	else if (b[i] != 1 && w[i] == 1)cntw++;
	//}
	rep(i, 0, N) {

		if (d_from1[i] <= d_fromN[i])cntb++;
		else cntw++;
	}
	cout << (cntb > cntw ? "Fennec" : "Snuke") << endl;
	return 0;
}