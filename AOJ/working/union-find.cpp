#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);

class DisjointSet {
public:
	// ２つのグループを１つにまとめる　と　2つの要素が同じグループに所属しているかどうかを判定する
	// 木が深くなればなるほど効率が悪くなるので、
	// rankを使うことにより必要以上に深さが大きくなることがないように管理する
	vector<int>rank, p, S; // p->parent  S[findSet(v)] ->連結成分の大きさ
	DisjointSet() {}
	DisjointSet(int size) {
		// [0,size)　 
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
signed main() {
	int n, a, b, q, t;
	cin >> n >> q;
	DisjointSet ds(n);
	rep(i, 0, q) {
		cin >> t >> a >> b;
		if (t == 0)ds.unite(a, b);
		else if (t == 1) {
			if (ds.same(a, b))cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	return 0;
}