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


int dp[40][40][40][40];
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int w, h;
	while (cin >> w >> h, w&&h) {
		memset(dp, 0x3f, sizeof(dp));
		rep(i, 0, h)rep(j, 0, w)dp[i][j][i][j] = 0;
		rep(i, 0, 2 * h - 1) {
			if (i % 2 == 0) {
				rep(j, 0, w - 1) {
					int x; cin >> x;
					// i/2 j,j+1
					dp[i / 2][j][i / 2][j + 1] = (x ? INF : 1);
					dp[i / 2][j + 1][i / 2][j] = (x ? INF : 1);
				}
			}
			else {
				rep(j, 0, w) {
					int x; cin >> x;
					// i/2 i/2+1 j
					dp[i / 2][j][i / 2 + 1][j] = (x ? INF : 1);
					dp[i / 2 + 1][j][i / 2][j] = (x ? INF : 1);
				}
			}
		}
		//rep(a, 0, h)rep(b, 0, w)rep(i, 0, h)rep(j, 0, w)rep(x, 0, h)rep(y, 0, w) {
		//	chmin(dp[i][j][x][y], dp[i][j][a][b] + dp[a][b][x][y]);
		//}
		queue<pair<int, int>>q;
		q.push(make_pair(0, 0));
		int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
		auto within = [&](int x, int y) {return 0 <= x&&x < h && 0 <= y&&y < w; };
		vector<vector<int>>d(h, vector<int>(w, -1));
		while (!q.empty()) {
			auto u = q.front(); q.pop();
			rep(i, 0, 4) {
				int x = u.first+dx[i], y = u.second+dy[i];
				if (within(x, y)&&dp[u.first][u.second][x][y]==1&&d[x][y]==-1) {
					q.push(make_pair(x, y));
					d[x][y] = d[u.first][u.second] + 1;
				}
			}
		}

		int ans = d[h - 1][w - 1];
		cout << (ans == -1 ? 0 : ans + 1+1) << endl;
	}
	return 0;
}