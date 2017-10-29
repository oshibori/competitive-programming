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
	string s; cin >> s;
	string t;
	int x(0);
	rep(i, 0, s.length()) {
		if (s[i] != 'x')t.push_back(s[i]);
		else x++;
	}
	string t_rev(t);
	reverse(all(t_rev));
	if (t != t_rev) {
		cout << -1 << endl;
		return 0;

	}


	int ans(0);
	int l = 0, r = s.length() - 1;
	while (l < r) {
		if (s[l] == s[r])l++, r--;
		else if (s[l] == 'x')l++, ans++;
		else if (s[r] == 'x')r--, ans++;
	}
	cout << ans << endl;

	return 0;
}