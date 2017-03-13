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

signed main() {
	string s; int cnt(0);
	while (getline(cin, s)) {
		rep(i, 0, s.size() - 4) {
			if (s.substr(i, 5) == "apple") {
				s[i] = 'p';
				s[i + 1] = 'e';
				s[i + 2] = 'a';
				s[i + 3] = 'c';
				s[i + 4] = 'h';
			}
			else if (s.substr(i, 5) == "peach") {
				s[i] = 'a';
				s[i + 1] = 'p';
				s[i + 2] = 'p';
				s[i + 3] = 'l';
				s[i + 4] = 'e';
			}
		}
		cout << s << endl;
	}
	return 0;
}