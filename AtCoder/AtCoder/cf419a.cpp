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
bool f(int x) {
	string ret;
	if (x / 60 < 10)ret.push_back('0');
	ret.append(to_string(x / 60));
	if (ret == "24")ret = "00";
	x %= 60;
	if (x < 10)ret.push_back('0');
	ret.append(to_string(x));
	dump(ret);

	return ret[0] == ret[3] && ret[1] == ret[2];
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int ans(INF);
	int a, b; char c;
	cin >> a >> c >> b;
	int x = 60 * a + b;
	rep(i, 0, 60 * 24)if (f(x + i))chmin(ans, i);
	cout << ans << endl;
	return 0;
}