#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const double EPS = 1e-10;
bool atari(string s, string t) {
	rep(i, 0, s.size()) {
		if (s[i] == '*' || t[i] == '*')continue;
		else if (s[i] != t[i])return false;
	}
	return true;
}
signed main() {
	int n, m;
	while (cin >> n >> m, n || m) {
		map<string, int>M;
		long long ans(0);
		rep(i, 0, n) {
			string s; int a; cin >> s >> a;
			M[s] = a;
		}
		rep(i, 0, m) {
			string s; cin >> s;
			each(it, M) {
				if (atari(it->first, s))ans += it->second;
			}
		}
		cout << ans << endl;
	}
	return 0;
}