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
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
struct RSQandRAQ {
	int n;
	vector<int>d, lazy;
	RSQandRAQ(int m) {
		for (n = 1; n < m; n <<= 1);
		d.assign(2 * n, 0);
		lazy.assign(2 * n, 0);
	}
	void eval(int k, int l, int r) {
		if (lazy[k] != 0) {
			d[k] += lazy[k];
			if (r - l > 1) {
				lazy[2 * k] += lazy[k] / 2;
				lazy[2 * k + 1] += lazy[k] / 2;
			}
			lazy[k] = 0;
		}
	}
	void add(int a, int b, int x, int k=1, int l=0, int r=-1) {
		if (r == -1)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l&&r <= b) {
			lazy[k] += (r - l)*x;
			eval(k, l, r);
		}
		else {
			add(a, b, x, 2 * k, l, (l + r) / 2);
			add(a, b, x, 2 * k + 1, (l + r) / 2, r);
			d[k] = d[2 * k] + d[2 * k + 1];
		}
	}
	int getSum(int a, int b, int k = 1, int l = 0, int r = -1) {
		if (r == -1)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return 0;
		if (a <= l&&r <= b)return d[k];
		else {
			int vl, vr;
			vl = getSum(a, b, 2 * k, l, (l + r) / 2);
			vr = getSum(a, b, 2 * k + 1, (l + r) / 2, r);
			return vl + vr;
		}
	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, q; cin >> n >> q;
	RSQandRAQ seg(n);
	rep(z, 0, q) {
		int com; cin >> com;
		if (com) {
			int s, t; cin >> s >> t;
			cout << seg.getSum(s - 1, t) << endl;
		}
		else {
			int s, t, x; cin >> s >> t >> x;
			seg.add(s - 1, t, x);
		}
	}
	return 0;
}