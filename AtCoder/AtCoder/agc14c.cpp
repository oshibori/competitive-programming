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

int H, W, K;
vector<string>A;
vector<vector<int>>field;
int sx, sy;
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
auto within = [&](int x, int y) {
	return 0 <= x&&x < H && 0 <= y&&y < W;
};
struct point {
	int x, y, v;
	point(int a, int b, int c) :x(a), y(b), v(c) {};
	bool operator<(const point &other) const {
		return v < other.v;
	}
	bool operator>(const point &other) {
		return v > other.v;
	}
};
void bfs(int x = sx, int y = sy, int c = K + 1) {
	priority_queue<point>pq;
	pq.push(point(x, y, c));
	while (!pq.empty()) {
		auto u = pq.top(); pq.pop();
		if (field[u.x][u.y] != -1)continue;
		field[u.x][u.y] = u.v;
		rep(i, 0, 4) {
			int a = u.x + dx[i], b = u.y + dy[i];
			if (within(a, b) && A[a][b] == '.')pq.push(point(a, b, u.v - 1));
		}
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> H >> W >> K;
	A = vector<string>(H);
	field = vector<vector<int>>(H, vector<int>(W, -1));

	rep(i, 0, H)cin >> A[i];
	rep(i, 0, H)rep(j, 0, W)if (A[i][j] == 'S') {
		A[i][j] = '.';
		sx = i; sy = j; break;
	}
	dump(sx, sy);

	bfs();

	int m(INF);
	rep(i, 0, H)rep(j, 0, W) {
		//cout << field[i][j] << (j == W - 1 ? '\n' : ' ');
		if (field[i][j] > 0) {
			int l = min(i, j);
			int r = min(H - 1 - i, W - 1 - j);
			chmin(m, min(l, r));
		}
	}
	dump(m);

	cout << 1 + (m + K - 1) / K << endl;
	//int ans(1);

	//while (m) {
	//	dump(m);
	//	m = max(0, m - K);
	//	ans++;
	//}
	//cout << ans << endl;

	return 0;
}