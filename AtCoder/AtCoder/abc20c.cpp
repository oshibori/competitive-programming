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
int dp[11][11][11][11];
int H, W, T;
vector<string>field;
int dx[4]{ 1,0,-1,0 }, dy[4]{ 0,1,0,-1 };
bool withIn(int x, int y) {
	return 0 <= x&&x < H && 0 <= y&&y < W;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	cin >> H >> W >> T;
	rep(i, 0, H) {
		string p; cin >> p;
		field.emplace_back(p);
	}

	int l = 1, r = T;

	while (r - l > 1) {

		int mid = (l + r) / 2;
		
		//wf
		memset(dp, INF, sizeof(dp));
		rep(i, 0, H)rep(j, 0, W)dp[i][j][i][j] = 0;

		int sx, sy, gx, gy;

		rep(i, 0, H)rep(j, 0, W)rep(k, 0, 4) {

			int X = i + dx[k], Y = j + dy[k];

			if (!withIn(X, Y))continue;

			dp[i][j][X][Y] = (field[X][Y] == '#' ? mid : 1);

			if (field[i][j] == 'S')sx = i, sy = j;
			else if (field[i][j] == 'G')gx = i, gy = j;
		}
		
		rep(n, 0, H)rep(m, 0, W)rep(a, 0, H)rep(b, 0, W)rep(c, 0, H)rep(d, 0, W) {
			dp[a][b][c][d] = min(dp[a][b][c][d], dp[a][b][n][m] + dp[n][m][c][d]);
		}

		if (dp[sx][sy][gx][gy] <= T)l = mid;
		else r = mid;
	}

	cout << l << endl;

	return 0;
}

























































//#include "bits/stdc++.h"
//using namespace std;
//#ifdef _DEBUG
//#include "dump.hpp"
//#else
//#define dump(...)
//#endif
//
////#define int long long
//#define rep(i,a,b) for(int i=(a);i<(b);i++)
//#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
//#define all(c) begin(c),end(c)
//const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
//const int MOD = (int)(1e9) + 7;
//template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
//template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
//int dp[11][11][110][110];
//vector<string>vec;
//int H, W, T;
//int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
//int dfs(vector<string>v, int x, int y, int b, int w) {
//	if (x < 0 || H <= x || y < 0 || W <= y || (v[x][y] == 'S'&&(b != 0 || w != 0)))return 0;
//
//
//	if (v[x][y] == 'G')return (++w + b > T ? 0 : (T - w) / b);
//
//	if (v[x][y] == '.')w++;
//	if (v[x][y] == '#')b++;
//
//	v[x][y] = 'S';
//	int res(0);
//	rep(i, 0, 4) {
//		int X = x + dx[i], Y = y + dy[i];
//		res = max(res, dfs(v, X, Y, b, w));
//	}
//
//	return dp[x][y][b][w] = res;
//}
//int solve() {
//	cin >> H >> W >> T;
//	if (T >= 35)return 0;
//	vec = vector<string>(H); rep(i, 0, H) { cin >> vec[i]; }
//	memset(dp, 0, sizeof(dp));
//	int ans(0);
//	rep(i, 0, H)rep(j, 0, W)if (vec[i][j] == 'S')ans = dfs(vec, i, j, 0, 0);
//	cout << ans << endl;
//	return 0;
//}
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//
//	solve();
//
//
//	return 0;
//}