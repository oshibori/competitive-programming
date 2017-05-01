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
struct RangeMinimumQuery {
	// 0-indexedで木を構成
	int n;
	vector<int>d;
	RangeMinimumQuery(int m) {
		// m is the number of data
		// 簡単にするため、要素数を２のべき乗に
		for (n = 1; n < m; n <<= 1);
		d.assign(2 * n, INF);
	}
	void update(int i, int x) {
		// update ith (0-indexed) number
		// index i に対応するleaf node の
		// The index of leaf node which corresponds to ith num is (n+i-1).
		i += n - 1;
		d[i] = x;
		while (i > 0) {
			i = (i - 1) / 2;// parent:(n-1)/2
			d[i] = min(d[i * 2 + 1], d[i * 2 + 2]);// children: (2*n+1),(2*n+2)
			// 簡単に親や子にアクセスできる
			// この番号付けが上手く働くのは、
			// This is because SegmentTree is a complete binary tree.
		}
	}
	int query(int l, int r) {
		// query [l,r)
		return query(l, r, 0, 0, n);// nでないと完全二分木にならない
	}
	int query(int a, int b, int k, int l, int r) {
		// query for min of [a,b)
		// 後ろの方の引数は、計算の簡単化のための引数
		// kは節点の番号、l,r はその節点が[l,r)に対応付いていることを表す
		// したがって、外からはquery(a,b,0,0,n)として呼ぶ

		// [a,b) と [l,r)が交差しなければINF
		if (r <= a || b <= l)return INF;

		// [a,b)が[l,r)を完全に含んでいれば、この節点の値
		if (a <= l&&r <= b)return d[k];
		else {
			//そうでなければ、2つの子の最小値
			int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return min(vl, vr);
		}
	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, q; cin >> n >> q;
	RangeMinimumQuery rmq(n);
	rep(i, 0, q) {
		int com; cin >> com;
		int x, y; cin >> x >> y;
		if (com)cout << rmq.query(x, y + 1) << endl;
		else rmq.update(x, y);
	}
	dump(rmq.d);
	return 0;
}