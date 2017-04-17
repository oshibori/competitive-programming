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
class WaterAndOxygen {
public:
	double maxDays(int remainH20, int remainO2, int costH2O, int costO2) {
		double a = remainH20, b = remainO2, c = costH2O, d = costO2;

		double x = 2 * (a*d - b*c) / (c + 2 * d);
		if (x < 0.0)x = 0.0;

		return min((a - x) / c, (b + 0.5*x) / d);
	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int a, b, c, d; cin >> a >> b >> c >> d;
	cout << fixed << setprecision(8) << WaterAndOxygen().maxDays(a, b, c, d) << endl;

	return 0;
}