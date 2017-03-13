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
vector<vector<int>>field;
int N = 170;
void print_field() {
	if (DBG) {
		rep(i, 0, N) {
			rep(j, 0, N) {
				cout << field[i][j] << (j == N - 1 ? '\n' : ' ');
			}
		}
	}
}
int solve(int x, int y, vector<vector<int>> &field) {
	queue<pair<int, int>>Q;
	Q.push(make_pair(x, y));
	int ans(1);
	vector<int> dx{ 1,1,0,-1,-1,0 }, dy{ 0, 1, 1, 0, -1, -1 };
	while (!Q.empty()) {
		auto a = Q.front(); Q.pop();
		if (field[a.first][a.second] == 1)continue;

		rep(i, 0, dx.size()) {
			int ax = a.first + dx[i], ay = a.second + dy[i];
			if (0 <= ax&&ax < N && 0 <= ay&&ay < N&&field[ax][ay] == -1) {
				field[ax][ay] = max(0, field[a.first][a.second] - 1);
				Q.push(make_pair(ax, ay));
				ans++;
			}
		}
	}

	return ans;
}
signed main() {
	int t, n;
	while (cin >> t >> n, t || n) {
		field = vector<vector<int>>(N, vector<int>(N, -1));

		rep(i, 0, n) {
			int x, y;
			cin >> x >> y;
			x += N / 2; y += N / 2;
			field[x][y] = INF;
		}

		int sx, sy; cin >> sx >> sy;
		sx += N / 2; sy += N / 2;
		field[sx][sy] = t + 1;

		cout << solve(sx, sy, field) << endl;


	}
	return 0;
}