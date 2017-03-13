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
vector<vector<int>>G;
vector<int>salary;
int solve(int x = 0) {
	if (salary[x] != -1)return salary[x];

	vector<int>v;
	rep(i, 0, G[x].size()) {
		v.push_back(solve(G[x][i]));
	}
	if (v.empty())v.push_back(0);
	return salary[x] = *max_element(all(v)) + *min_element(all(v)) + 1;
}
signed main() {
	int N; cin >> N;
	salary = vector<int>(N, -1);
	G = vector<vector<int>>(N);

	rep(i, 1, N) {
		int b; cin >> b; b--;
		G[b].push_back(i);
	}

	cout << solve(0) << endl;

	return 0;
}