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

	int R, C, K; cin >> R >> C >> K;
	vector<string>v(R); rep(i, 0, R)cin >> v[i];

	function<bool(int, int)> within = [&](int x, int y) {
		return 0 <= x&&x < R && 0 <= y&&y < C;
	};
	int dx[4]{ 1,0,-1,0 }, dy[4]{ 0,1,0,-1 };

	//function<int(int, int)> bfs = [&](int a, int b) {
	//	queue<pair<int, int>>Q;
	//	vector<vector<int>>G(R, vector<int>(C, 0));
	//	Q.push(make_pair(a, b));
	//	G[a][b] = 1;
	//	bool f(true);
	//	while (!Q.empty()) {
	//		auto u = Q.front(); Q.pop();
	//		int x = u.first, y = u.second;
	//		if (G[x][y] == K)continue;
	//		rep(i, 0, 4) {
	//			int X = x + dx[i], Y = y + dy[i];
	//			if (within(X, Y) && v[X][Y] == 'o') {
	//				if (G[X][Y] == 0) {
	//					G[X][Y] = G[x][y] + 1;
	//					Q.push(make_pair(X, Y));
	//				}
	//			}
	//			else {
	//				f = false;
	//				break;
	//			}
	//		}




	//		if (!f)break;

	//	}

	//	//cout << endl;
	//	//rep(i, 0, R) {
	//	//	rep(j, 0, C)cout << G[i][j];
	//	//	cout << endl;
	//	//}

	//	return f;

	//};

	vector<vector<int>>down(R, vector<int>(C, 0)), up(R, vector<int>(C, 0));
	rep(i, 0, C) {
		rep(j, 0, R) {
			if (v[j][i] == 'o') {
				int cnt(0);
				while (j + cnt < R&&v[j + cnt][i] == 'o')cnt++;
				int c(cnt);
				rep(k, 0, cnt)down[j + k][i] = c--;
				j = j + cnt;
			}
		}
		rrep(j, 0, R) {
			if (v[j][i] == 'o') {
				int cnt(0);
				while (0 <= j - cnt&&v[j - cnt][i] == 'o')cnt++;
				int c(cnt);
				rep(k, 0, cnt)up[j - k][i] = c--;
				j = j - cnt;
			}
		}
	}


	//cout << endl;
	//rep(i, 0, R) {
	//	rep(j, 0, C)cout << down[i][j];
	//	cout << endl;
	//}
	//cout << endl;
	//rep(i, 0, R) {
	//	rep(j, 0, C)cout << up[i][j];
	//	cout << endl;
	//}

	int ans(0);
	rep(i, 0, R)rep(j, 0, C) {
		bool f(true);
		rep(k, j - (K - 1), j + K) {
			if (!within(i, k)) {
				f = false;
				break;
			}

			if (!(K - abs(j - k) <= up[i][k] && K - abs(j - k) <= down[i][k])) {
				f = false;
				break;
			}
		}
		ans += f;
	}




	cout << ans << endl;


	return 0;
}