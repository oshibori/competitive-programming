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
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K; cin >> N >> K;
	vector<int>a, b, c;
	DisjointSet uf(N);
	rep(i, 0, N - 1) {
		int x, y, z; cin >> x >> y >> z;
		x--, y--;
		a.push_back(x);
		b.push_back(y);
		c.push_back(z);
		if (z == 0)uf.unite(x, y);

	}

	dump(uf.connectedComponentSize(0));
	if (uf.connectedComponentSize(0) > K) {
		cout << -1 << endl;
		return 0;
	}
	set<int>v;
	rep(i, 0, N - 1) {
		if (!uf.same(a[i],0) && !uf.same(b[i],0)) uf.unite(a[i], b[i]);
	}
	
	rep(i, 0, N - 1) {
		if (!uf.same(a[i], b[i])) {
			if (uf.same(a[i],0))v.insert(b[i]);
			else if (uf.same(b[i],0))v.insert(a[i]);
		}
	}
	int ans(0);
	vector<int>d;
	for (auto &o : v)d.push_back(uf.connectedComponentSize(o));
	sort(all(d), greater<int>());
	while (N > K&&ans < d.size()) {
		N -= d[ans++];
	}
	cout << ans << endl;

	return 0;
}