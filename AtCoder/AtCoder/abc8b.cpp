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

//bool operator<(const pair<string, int> &left, const pair<string, int>&right) {
//	return left.second < right.second;
//}
signed main() {
	int n; cin >> n; map<string, int>mp;
	rep(i, 0, n) {
		string s; cin >> s;
		mp[s]++;
	}
	pair<string, int>ans("",-1);
	for (auto &e : (mp)) {
		if (e.second > ans.second)ans = e;
	}
	cout << ans.first << endl;
	return 0;
}