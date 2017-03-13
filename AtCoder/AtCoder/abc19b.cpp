#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DBG 0
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);

signed main() {
	string s; cin >> s;
	string ans;
	int i = 0;
	while (i<s.length()) {
		string tmp; 
		tmp += s[i];
		dump(tmp);
		int j = i + 1;
		while (j<s.length()) {
			if (tmp[0] == s[j])tmp += s[j++];
			else break;
			dump(tmp);
		}
		ans += tmp[0] + to_string(tmp.length());
		dump(ans);
		i = j;
		dump(i);
	}
	cout << ans << endl;
	return 0;
}