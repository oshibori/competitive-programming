#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
vector<vector<int>>v;
int N, K;
int dp[6][128];
bool solve(int i, int x) {
	if (i == N)return x == 0;
	bool res(false);
	rep(j, 0, K)res = max(res, solve(i + 1, x^v[i][j]));
	return dp[i][x] = res;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	memset(dp, 0, sizeof(dp));
	cin >> N >> K;
	v = vector<vector<int>>(N, vector<int>(K));
	rep(i, 0, N)rep(j, 0, K)cin >> v[i][j];
	if (solve(0, 0))cout << "Found" << endl;
	else cout << "Nothing" << endl;
	return 0;
}