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
	int a, b, c; cin >> a >> b >> c;
	if (a & 1 || b & 1 || c & 1) {
		cout << 0 << endl;
		return 0;
	}
	set<tuple<int, int, int>>s;
	int ans(0);
	while (1) {
		s.insert(make_tuple(a, b, c));
		ans++;

		int x = b / 2 + c / 2;
		int y = a / 2 + c / 2;
		int z = a / 2 + b / 2;

		if (x & 1 || y & 1 || z & 1)break;

		a = x;
		b = y;
		c = z;

		if (s.find(make_tuple(a, b, c)) != s.end()) {
			ans = 0;
			break;
		}

	}
	cout << (ans == 0 ? -1 : ans) << endl;
	return 0;
}