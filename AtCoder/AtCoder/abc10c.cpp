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

	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	int T, V; cin >> T >> V;
	int n; cin >> n;
	bool f(false);
	rep(i, 0, n) {
		int X, Y; cin >> X >> Y;

		if (sqrt((x1 - X)*(x1 - X) + (y1 - Y)*(y1 - Y))
			+ sqrt((X - x2)*(X - x2) + (Y - y2)*(Y - y2)) <= V*T)f = true;
	}
	if (f)cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}