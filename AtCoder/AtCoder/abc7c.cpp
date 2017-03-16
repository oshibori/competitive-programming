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

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int dx[4]{ 1,0,-1,0 }, dy[4]{ 0,1,0,-1 };
	int R, C; cin >> R >> C;
	int sy, sx, gy, gx; cin >> sy >> sx >> gy >> gx;
	sy--, sx--, gy--, gx--;
	vector<string>M(R); rep(i, 0, R)cin >> M[i];
	vector<vector<int>>D(R, vector<int>(C, INF));
	queue<pair<int, int>>Q;
	Q.push(make_pair(sy, sx));
	D[sy][sx] = 0;
	while (!Q.empty()) {
		auto u = Q.front(); Q.pop();
		rep(i, 0, 4) {
			int Y = u.first + dy[i], X = u.second + dx[i];
			if (M[Y][X] == '.'&&D[Y][X] == INF) {
				D[Y][X]= D[u.first][u.second] + 1;
				Q.push(make_pair(Y, X));
			}
		}
		//cout << endl;
		//rep(i, 0, R)rep(j, 0, C)cout << (D[i][j] == INF ? -1 : D[i][j]) << (j == C - 1 ? '\n' : ' ');

	}
	cout << D[gy][gx] << endl;
	return 0;
}