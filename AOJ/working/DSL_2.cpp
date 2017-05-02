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
	int n;
	vector<int>d;
	RangeMinimumQuery(int m) {
		for (n = 1; n < m; n <<= 1);
		d.assign(2 * n, INF);
	}
	void update(int i, int x) {
		d[n + i] = x;
		for (int j = (n + i) / 2; j > 0; j >>= 1)
			d[j] = min(d[2 * j], d[2 * j + 1]);
	}
	int query(int a, int b) {
		return query(a, b, 1, 0, n);
	}
	int query(int a, int b, int k, int l, int r) {
		// [a,b) [l,r)
		if (r <= a || b <= l)return INF;
		else if (a <= l&&r <= b)return d[k];
		else {
			int vl, vr;
			vl = query(a, b, 2 * k, l, (l + r) / 2);
			vr = query(a, b, 2 * k + 1, (l + r) / 2, r);
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
		int com, a, b; cin >> com >> a >> b;
		if (com)cout << (rmq.query(a, b + 1)==INF?(1ll<<31)-1:rmq.query(a,b+1)) << endl;
		else rmq.update(a, b);
	}
	return 0;
}