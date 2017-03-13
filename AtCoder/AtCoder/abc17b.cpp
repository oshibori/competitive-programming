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
	string s; cin >> s;
	int i = 0;
	while (i < s.size()) {
		if (i < s.size() - 1 && s[i] == 'c'&&s[i + 1] == 'h')i += 2;
		else if (s[i] == 'o' || s[i] == 'k' || s[i] == 'u')i++;
		else break;

	}
	if (i == s.size())cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}