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
void print_vv(vector<vector<int>>v) {
	rep(i, 0, v.size()) {
		rep(j, 0, v[i].size()) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
void print_v(vector<int>v) {
	rep(i, 0, v.size())cout << v[i] << " ";
	cout << endl;
}
int N, K;
vector<vector<int>>table(11, vector<int>(1, 0));
vector<vector<int>>dp(11, vector<int>(2048, -1));
int dfs(int n, int k) {
	if (n == 10)return 0;
	if (dp[n][k] != -1)return dp[n][k];
	int res(0);
	rep(i, 0, table[n].size()) {
		if (k + i > K) break;
		res = max(res, dfs(n + 1, k + i) + table[n][i]);
	}

	return dp[n][k] = res;
}
signed main() {
	cin >> N >> K;
	vector<int>v(N), kind(N), num(11, 0);
	rep(i, 0, N) {
		cin >> v[i] >> kind[i];
		table[--kind[i]].push_back(v[i]);
		num[kind[i]]++;
	}

	rep(i, 0, 11) {
		sort(table[i].begin() + 1, table[i].end(), greater<int>());
		//print_v(table[i]);
		rep(j, 1, table[i].size()) {
			table[i][j] += table[i][j - 1];
		}
		//print_v(table[i]);
		rep(j, 1, table[i].size()) {
			table[i][j] += (j - 1)*j;
		}
		//print_v(table[i]);
	}
	//print_vv(table);
	//vector<vector<int>>dp(table);
	//rep(i, 1, 10) {
	//	rep(j, 1, k + 1) {
	//		if (dp[i][j] == 0)break;
	//		for (int l = 0; l + j < k + 1; l++) {
	//			bool f1(false), f2(false);
	//			if (dp[i + 1][j + l] == 0)f1 = true;
	//			if (dp[i + 1][j + l] < dp[i][j] + dp[i + 1][l])f2 = true;
	//			dp[i + 1][j + l] = max(dp[i + 1][j + l], dp[i][j] + dp[i + 1][l]);
	//			if (f1 || f2)break;
	//		}
	//		//print_vv(dp);
	//	}
	//}
	cout << dfs(0, 0) << endl;
	return 0;
}