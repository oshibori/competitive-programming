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
const int MOD = (int)(1e9 + 7); const int B(1), W(0);
int n, m;
vector<vector<int>>v;
int dfs(vector<int>d, int s = 0) {
	d[s] = B;
	int ans(0); bool f = true;
	rep(i, 0, n) {
		if (d[i] == W&&v[s][i] == 1) {
			ans += dfs(d, i);
			f = false;
		}
	}

	if (f) {
		if(accumulate(d.begin(),d.end(),0)==n)return 1;
		else return 0;
	}


	return ans;
}
signed main() {
	cin >> n >> m; v = vector<vector<int>>(n, vector<int>(n, 0));
	rep(i, 0, m) {
		int a, b; cin >> a >> b;
		v[--a][--b] = 1;
		v[b][a] = 1;
	}
	vector<int>d(n, W);
	cout << dfs(d, 0) << endl;
	return 0;
}