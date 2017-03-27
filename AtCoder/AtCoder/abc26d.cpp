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

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int A, B, C; cin >> A >> B >> C;

	function<bool(double)>f = [&](double t) {
		double ret = A*t + B*sin(C*t*PI);
		dump(ret);
		return ret > 100.0;
	};
	cerr << setprecision(8);
	cerr.fixed;

	double l(0.0), r(2000.0);
	rep(i, 0, 100) {

		double mid = (l + r) / 2;

		if (f(mid))r = mid;
		else l = mid;

	}

	dump(f(l));
	cout << fixed << setprecision(15) << l << endl;

	return 0;
}