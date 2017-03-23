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
const double EPS = 1e-7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	double x, y; cin >> x >> y;
	double a, b; a = min(x, y); b = max(x, y);
	//cin >> a >> b;
	double t = min(360 - (b - a), (b - a));


	t = t / 2;
	dump(t);

	if (360 - (b - a) > b - a) {

		cout << fixed << setprecision(4) << (a + b) / 2 << endl;
	}


	else {
		double ans = (a + 360 + b) / 2;
		if (ans - 360.0> EPS)ans -= 360;
		cout << fixed << setprecision(4) << ans << endl;
	}


	/*if (t - a> EPS)cout << t << endl;
	else cout << a + t << endl;
*/

//if (t > 90.0) {
//	t = 180 - t;
//	a -= t;
//	if (a < 0)a += 360;
//}
//

//cout << a + t << endl;



	return 0;
}