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
	int e(0), l(0);
	rep(i, 0, 6) {
		int E; cin >> E;
		e |= (1 << E);
	}
	int B; cin >> B;
	rep(i, 0, 6) {
		int L; cin >> L;
		l |= (1 << L);
	}
	auto bitcount = [&](int x) {
		int ret(0);
		while (x)x &= (x - 1), ret++;
		return ret;
	};

	int ans;
	int b = bitcount(e&l);
	if (b == 6)ans = 1;
	else if (b == 5 && (l&(1 << B)))ans = 2;
	else if (b == 5)ans = 3;
	else if (b == 4)ans = 4;
	else if (b == 3)ans = 5;
	else ans = 0;
	cout << ans << endl;

	return 0;
}