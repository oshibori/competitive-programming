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
struct RangeUpdateQuery {
	int n;
	vector<T>d;
	RangeUpdateQuery(int m) {
		for (n = 1; n < m; n <<= 1);
		d.assign(2 * n, INF);
	}
	int get(int i) {
		update(i, i + 1, -1);
		return d[n + i];
	}
	void update(int a, int b, T x) {
		return update(a, b, x, 1, 0, n);
	}
	void update(int a, int b, T x, int k, int l, int r) {
		// [a,b) [l,r)
		if (r <= a || b <= l)return;
		else if (a <= l&&r <= b) {
			if (x >= 0)d[k] = x;
			return;
		}
		else {
			// [l,r) のどこかを変更するとなると、
			// d[ [l,r) ] == z(同じ値)  が保てなくなるので子に値を移す
			// 
			if (d[k] != INF)d[2 * k] = d[2 * k + 1] = d[k], d[k] = INF;
			update(a, b, x, 2 * k, l, (l + r) / 2);
			update(a, b, x, 2 * k + 1, (l + r) / 2, r);
		}
	}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, q; cin >> n >> q;
	RangeUpdateQuery<int> ruq(n);
	rep(i, 0, q) {
		int com; cin >> com;
		if (com) {
			int i; cin >> i;
			cout << ruq.get(i) << endl;
		}
		else {
			int s, t, x; cin >> s >> t >> x;
			ruq.update(s, t + 1, x);
		}
	}
	return 0;
}