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
struct RMQandRUQ {
	int n;
	vector<int>d, lazy;
	RMQandRUQ(int m) {
		for (n = 1; n < m; n <<= 1);
		d.assign(2 * n, INF);
		lazy.assign(2 * n, -1);
	}
	void eval(int k, int l, int r) {
		if (lazy[k] != -1) {
			d[k] = lazy[k];
			if (r - l > 1)lazy[2 * k] = lazy[2 * k + 1] = lazy[k], lazy[k] = -1;
			lazy[k] = -1;
		}
	}
	void update(int a, int b, int x, int k = 1, int l = 0, int r = -1) {
		if (r == -1)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l&&r <= b) {
			lazy[k] = x;
			eval(k, l, r);
			return;
		}
		else {
			update(a, b, x, 2 * k, l, (l + r) / 2);
			update(a, b, x, 2 * k + 1, (l + r) / 2, r);
			d[k] = min(d[2 * k], d[2 * k + 1]);

		}
	}
	int find(int a, int b, int k = 1, int l = 0, int r = -1) {
		if (r == -1)r = n;

		eval(k, l, r);

		if (r <= a || b <= l)return INF;
		if (a <= l&&r <= b) {
			return d[k];
		}
		else {
			int vl, vr;
			vl = find(a, b, 2 * k, l, (l + r) / 2);
			vr = find(a, b, 2 * k + 1, (l + r) / 2, r);
			return min(vl, vr);
		}

	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, q; cin >> n >> q;
	RMQandRUQ seg(n);
	rep(z, 0, q) {
		int com; cin >> com;
		if (com) {
			int s, t; cin >> s >> t;
			cout << seg.find(s, t + 1) << endl;
		}
		else {
			int s, t, x; cin >> s >> t >> x;
			seg.update(s, t + 1, x);
		}
	}
	return 0;
}