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
enum { WHITE, BLACK, GRAY };
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<vector<int>>G(N);
	rep(i, 0, N-1) {
		int a, b; cin >> a >> b;
		a--; b--;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}

	vector<int>color(N, GRAY);
	vector < pair<int, int>>dp(N, make_pair(-1, -1));// dp[i]= white or blackÇÃÇ∆Ç´ÇÃèÍçáÇÃêî
	dump(color);
	function<int(int,int)>dfs = [&](int s, int prev_c) {
		dump(s, prev_c);
		if (prev_c == WHITE&&dp[s].first != -1 && dp[s].second != -1)return dp[s].first + dp[s].second;
		if (prev_c == BLACK&&dp[s].first != -1)return dp[s].first;

		bool exe(false);
		int ret(0);
		color[s] = WHITE;
		rep(i, 0, G[s].size())if (color[G[s][i]] == GRAY)exe = true, ret += dfs(G[s][i],color[s]);
		dp[s].first = ret; ret = 0;
		dump(dp[s].first);
		color[s] = GRAY;
		if (prev_c != BLACK) {
			color[s] = BLACK;
			rep(i, 0, G[s].size())if (color[G[s][i]] == GRAY)ret += dfs(G[s][i],color[s]);
			dp[s].second = ret;
			dump(dp[s].second);
			color[s] = GRAY;
		}
		dump(exe);
		if (exe) {
			if (prev_c != BLACK)return dp[s].first + dp[s].second;
			else return dp[s].first;
		}
		else {
			dp[s].first = dp[s].second = 1;
			if (prev_c != BLACK)return dp[s].first + dp[s].second;
			else return dp[s].first;
		}
	};

	cout << dfs(0, GRAY) << endl;

	return 0;
}