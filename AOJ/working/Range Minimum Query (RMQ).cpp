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
const int INF = (1ll << 31) - 1;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template<typename T>
struct RangeMinimumQuery {
	// 1-indexedで木を構成
	// それぞれの要素は 0-indexed
	int n;
	vector<T>d;
	RangeMinimumQuery(int m) {
		// m is the number of data
		// 簡単にするため、要素数を２のべき乗に
		for (n = 1; n < m; n <<= 1);
		d.assign(2 * n, INF);
	}
	void update(int i, T x) {
		// update ith (0-indexed) number
		// index i に対応するleaf node の
		// The index of leaf node which corresponds to ith num is (n+i).
		d[n + i] = x;
		for (int j = (n + i) / 2; j > 0; j >>= 1) {
			d[j] = min(d[j * 2], d[j * 2 + 1]);// children: (2*n),(2*n+1)
			// 簡単に親や子にアクセスできる
			// This is because SegmentTree is a complete binary tree.
		}
	}
	T query(int l, int r) {
		// query [l,r)
		return query(l, r, 1, 0, n);// nでないと完全二分木にならない
	}
	T query(int a, int b, int k, int l, int r) {
		// query for min of [a,b)
		// 後ろの方の引数は、計算の簡単化のための引数
		// kは節点の番号、l,r はその節点が[l,r)に対応付いていることを表す
		// したがって、外からはquery(a,b,1,0,n)として呼ぶ

		// [a,b) と [l,r)が交差しなければINF
		if (r <= a || b <= l)return INF;

		// [a,b)が[l,r)を完全に含んでいれば、この節点の値
		if (a <= l&&r <= b)return d[k];
		else {
			//そうでなければ、2つの子の最小値
			T vl = query(a, b, k * 2, l, (l + r) / 2);
			T vr = query(a, b, k * 2 + 1, (l + r) / 2, r);
			return min(vl, vr);
		}
	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, q; cin >> n >> q;
	RangeMinimumQuery<int> rmq(n);
	rep(i, 0, q) {
		int com; cin >> com;
		int x, y; cin >> x >> y;
		if (com)cout << rmq.query(x, y + 1) << endl;
		else rmq.update(x, y);
	}
	//dump(rmq.d);
	return 0;
}