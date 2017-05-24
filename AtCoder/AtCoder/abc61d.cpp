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
const int INF = 900000000000000000;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
//list<int>L;
//vector<int>check;// 
//int N, M;
//vector<vector<int>>G;
//bool visit(int n) {
//	dump(n);
//	if (check[n] == 1)return true;
//	else if (check[n] == 0) {
//		check[n] = 1;
//		rep(i, 0, N) {
//			bool f(false);
//			if (G[n][i] >= 0)chmax(f, visit(i));
//			if (f)return f;
//		}
//		check[n] = 2;
//		L.push_front(n);
//		return false;
//	}
//}
//bool is_cycle() {
//	bool f(false);
//	rep(i, 0, N) {
//		chmax(f, visit(i));
//		if (f)return f;
//	}
//	return false;
//}
// 隣接リストで使う辺を表す型
struct Edge {
	int to, cost;  // 辺の接続先頂点, 辺の重み
	Edge(int to, int cost) : to(to), cost(cost) {}  // コンストラクタ
};

typedef vector<vector<Edge> > AdjList;  // 隣接リストの型
AdjList graph;  // グラフの辺を格納した構造体
				// graph[v][i]は頂点vから出るi番目の辺Edge


vector<int> dist; // 最短距離

				  // 戻り値がtrueなら負の閉路を含む
bool bellman_ford(int n, int s) { // nは頂点数、sは開始頂点
	dist = vector<int>(n, INF);
	dist[s] = 0; // 開始点の距離は0
	for (int i = 0; i < n; i++) {
		for (int v = 0; v < n; v++) {
			for (int k = 0; k < graph[v].size(); k++) {
				Edge e = graph[v][k];
				if (dist[v] != INF && dist[e.to] > dist[v] + e.cost) {
					dist[e.to] = dist[v] + e.cost;
					if (i == n - 1) return true; // n回目にも更新があるなら負の閉路が存在
				}
			}
		}
	}
	return false;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M; cin >> N >> M;
	graph = AdjList(N);
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		from--, to--;
		graph[from].push_back(Edge(to, -cost));
	}

	if (bellman_ford(N, 0)) {
		cout << "inf" << endl;
		return 0;
	}
	cout << -dist[N - 1] << endl;


	return 0;
	//cin >> N >> M;
	//G = vector<vector<int>>(N, vector<int>(N, -1));
	//check = vector<int>(N, 0);
	//rep(i, 0, M) {
	//	int a, b, c; cin >> a >> b >> c;
	//	a--, b--;
	//	G[a][b] = c;
	//}
	//if (is_cycle()) {
	//	cout << "inf" << endl;
	//	return 0;
	//}

	return 0;
}