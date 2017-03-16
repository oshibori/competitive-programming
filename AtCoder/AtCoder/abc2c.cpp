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
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	double x1, y1; cin >> x1 >> y1;
	double x2, y2; cin >> x2 >> y2;
	double x3, y3; cin >> x3 >> y3;

	x2 -= x1; y2 -= y1;
	x3 -= x1; y3 -= y1;

	cout <<fixed<<setprecision(3)<< 0.5*abs(x2*y3 - y2*x3) << endl;




	return 0;
}