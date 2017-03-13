#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
int ans = 0; int n, a;
vector<int>v; vector<vector<vector<int> > >dp;
int solve(int i = 0, int sum = 0, int cnt = 0) {
	if (dp[i][sum][cnt] != -1)return dp[i][sum][cnt];
	if (i == n) {
		if (cnt&&sum == a*cnt)return dp[i][sum][cnt] = 1;
		else return 0;
	}
	return dp[i][sum][cnt] = solve(i + 1, sum + v[i], cnt + 1) + solve(i + 1, sum, cnt);
}
signed main() {
	cin >> n >> a; v = vector<int>(n); rep(i, 0, n)cin >> v[i];
	dp = vector<vector<vector<int> > >(51, vector <vector<int> >(2510, vector<int>(51, -1)));
	cout << solve() << endl;
	return 0;
}