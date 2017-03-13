#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstdio>
#include<cstdlib>
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

map<int, vector<int> >M;
int solve(int i=1,int deep=0) {
	if (M.find(i) == M.end()) {
		return deep;
	}
	int ans = 0;
	for (int j = 0; j < M[i].size(); j++) {
		ans=max(ans,solve(M[i][j],deep+1));
	}
	return ans;
}
signed main() {
	int n; cin >> n; vector<int>a(n + 1, 0);
	rep(i, 2, n + 1)cin >> a[i];
	rep(i, 2, n + 1) {
		M[a[i]].push_back(i);
	}
	cout << solve() << endl;
	return 0;
}