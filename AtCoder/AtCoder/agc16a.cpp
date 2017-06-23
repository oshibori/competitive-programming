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
bool check(string s) {
	rep(i, 1, s.size()) {
		if (s[i] != s[i - 1])return false;
		
	}
	return true;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s; cin >> s;
	int ans = s.size() ;
	rep(i, 0, s.size()) {

		string t(s);
		int cnt(0);
		while (check(t) == false) {
			cnt++;
			string u;
			rep(j, 0, t.size() - 1) {
				if (t[j] == s[i]) {
					u.push_back(t[j]);
				}
				else if (t[j + 1] == s[i]) {
					u.push_back(t[j + 1]);
				}
				else u.push_back(t[j + 1]);
			}
			t = u;
		}
		chmin(ans, cnt);

	}
	cout << ans << endl;
	return 0;
}