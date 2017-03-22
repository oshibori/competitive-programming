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
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }


template<typename T>
class DisjointSet {
public:
	// ２つのグループを１つにまとめる　と　2つの要素が同じグループに所属しているかどうかを判定する
	vector<T>rank, p, S; // p->parent  S[findSet(v)] ->連結成分の大きさ
	DisjointSet() {}
	DisjointSet(int size) {
		S.resize(size, 1);
		rank.resize(size, 0);
		p.resize(size, 0);
		rep(i, 0, size)makeSet(i);
	}
	void makeSet(int x) {
		p[x] = x;
		rank[x] = 0;
	}
	bool same(int x, int y) {   // 判定する
		return findSet(x) == findSet(y);
	}
	void unite(int x, int y) { // 連結するときにはこれを使う
		if (same(x, y))return;
		link(findSet(x), findSet(y));
	}
	void link(int x, int y) {
		if (rank[x] > rank[y]) {
			p[y] = x;
		}
		else {
			p[x] = y;
			if (rank[x] == rank[y]) {
				rank[y]++;
			}
		}

		S[x] = S[y] = S[x] + S[y];
	}
	int findSet(int x) {
		if (x != p[x]) {
			p[x] = findSet(p[x]);// path compression
		}
		return p[x];
	}
	int connectedComponentSize(int x) {
		return S[findSet(x)];
	}
};
class Query {
public:
	// t==1 unite, t==0 answer
	int t, year, a, b, v, w;
	Query() {}
	bool operator<(const Query &other) {
		if (year != other.year)return year > other.year;
		else return t < other.t;
	}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N, M; cin >> N >> M;
	DisjointSet<int> g(N);
	vector<Query>q;
	rep(i, 0, M) {
		int a, b, y; cin >> a >> b >> y; a--, b--;
		Query x;
		x.a = a; x.b = b; x.year = y; x.t = 1;
		q.push_back(x);
	}
	int Q; cin >> Q; vector<int>v(Q), w(Q); rep(i, 0, Q)cin >> v[i] >> w[i];
	rep(i, 0, Q) {
		Query x;
		v[i]--; w[i];
		x.v = v[i]; x.year = w[i]; x.t = 0;
		q.push_back(x);
	}

	sort(all(q));

	map < pair<int, int>, int>ans;

	rep(i, 0, M + Q) {
		if (q[i].t) {
			g.unite(q[i].a, q[i].b);
		}
		else {
			ans[make_pair(q[i].v, q[i].year)] = g.connectedComponentSize(q[i].v);
		}
	}

	rep(i, 0, Q) {
		cout << ans[make_pair(v[i], w[i])] << endl;
	}

	// TLE
	//int N, M; cin >> N >> M;
	//vector<vector<pair<int, int>>>G(N); // dis, year
	//rep(i, 0, M) {
	//	int a, b, y; cin >> a >> b >> y; a--, b--;
	//	G[a].push_back(make_pair(b, y));
	//	G[b].push_back(make_pair(a, y));
	//}
	//int Q; cin >> Q;
	//rep(i, 0, Q) {
	//	int v, w; cin >> v >> w; v--;
	//	vector<bool>d(N, false); d[v] = true;
	//	queue<int>q; q.push(v);
	//	while (!q.empty()) {
	//		int u = q.front(); q.pop();
	//		d[u] = true;
	//		rep(j, 0, G[u].size()) {
	//			auto x = G[u][j];
	//			if (x.second > w&&!d[x.first])q.push(x.first);
	//		}
	//	}
	//	cout << accumulate(all(d), 0) << endl;
	//	
	//}

	return 0;
}