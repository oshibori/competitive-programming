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
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int V, E; cin >> V >> E;
	vector<vector<int>>G(V, vector<int>(V, INF));
	rep(i, 0, E) {
		int s, t, d; cin >> s >> t >> d;
		G[s][t] = d;
	}
	int ans(INF);
	vector<vector<int>>dp((1 << V), vector<int>(V, INF));
	dp[(1 << V) - 1][0] = 0;
	// 現在の状況(2^n)* 今どこにいるのか(n)* 次にどこにいくのか(n) = O(n*n*2^n)
	// bits>X を満たすXは必ず計算し終わっている。
	for (int bits = (1 << V) - 1 - 1; bits >= 0; bits--) {
		rep(i, 0, V) {
			// current point
			rep(j, 0, V) {
				if (!(bits&(1 << j))) {// not yet
					chmin(dp[bits][i], dp[bits | (1 << j)][j] + G[i][j]);
				}
			}


		}
	}
	cout << (dp[0][0] == INF ? -1 : ans) << endl;
	return 0;
}

// メモ化再帰
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int V, E; cin >> V >> E;
//	vector<vector<int>>G(V, vector<int>(V, INF));
//	rep(i, 0, E) {
//		int s, t, d; cin >> s >> t >> d;
//		G[s][t] = d;
//	}
//	vector<vector<int>>dp(1 << V, vector<int>(V, -1));
//	function<int(int, int)> tsp = [&](int S, int v) {
//		if (dp[S][v] >= 0)return dp[S][v];
//		if (S == (1 << V) - 1 && v == 0)return dp[S][0] = 0;
//
//		int ret = INF;
//		rep(i, 0, V) {
//			if (!(S&(1 << i)))chmin(ret, tsp(S | (1 << i), i) + G[v][i]);
//		}
//		return dp[S][v] = ret;
//
//	};
//	int ans = tsp(0, 0);
//	cout << (ans == INF ? -1 : ans) << endl;
//	return 0;
//}