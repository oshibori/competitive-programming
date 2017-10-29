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
	int q; cin >> q;
	rep(i, 0, q) {
		int n; cin >> n;
		int ans;
		if (1 <= n&&n <= 3)ans = -1;
		else if (n % 2 == 0)ans = n / 4;
		else if (n % 4 == 1) {
			if (n != 5)	ans = n / 4 - 1;
			else ans = -1;
		}
		else {
			if (n == 7 || n == 11)ans = -1;
			else ans = n / 4 - 1;
		}
		cout << ans << endl;
	}
	return 0;
}