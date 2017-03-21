#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	// bitDP
	int N, M; cin >> N >> M;
	vector<vector<int>>G(N, vector<int>(N, 0));
	rep(i, 0, M) {
		int x, y; cin >> x >> y; x--, y--;
		G[x][y] = 1;
	}
	vector<int>dp(1 << N, 0);
	dp[0] = 1;
	rep(bits, 1, 1 << N) {

		rep(j, 0, N) {
			if ((bits & 1 << j)) {
				bool f(true);
				rep(k, 0, N) {
					if (G[j][k] && bits & 1 << k)f = false;
				}
				if (f)dp[bits] += dp[bits ^ (1 << j)];
			}
		}
	}

	cout << dp[(1 << N) - 1] << endl;







	// ƒƒ‚‰»Ä‹A

	//int N, M; cin >> N >> M;
	//vector<vector<int>>G(N, vector<int>(N, 0));
	//vector<int>indeg(N, 0);
	//rep(i, 0, M) {
	//	int x, y; cin >> x >> y; x--, y--;
	//	G[x][y] = 1;
	//	indeg[y]++;
	//}
	//vector<long long>dp((1 << N), 0);

	//function<long long(int, vector<int>)>dfs = [&](int s, vector<int> v) -> long long {
	//	if (s == 0)return 1;

	//	if (dp[s] != 0)return dp[s];

	//	long long ans(0);
	//	rep(i, 0, N) {
	//		if (v[i] == 0 && s&(1 << i)) {
	//			vector<int>w(v);
	//			rep(j, 0, N)if (G[i][j])w[j]--;
	//			ans += dfs(s ^ (1 << i), w);
	//		}
	//	}
	//	return dp[s] = ans;
	//};

	//cout << dfs((1 << N) - 1, indeg) << endl;



	return 0;
}