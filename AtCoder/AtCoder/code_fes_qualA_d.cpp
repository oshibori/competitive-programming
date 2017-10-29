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
	int H, W, d; cin >> H >> W >> d;
	vector<vector<int>>v(H, vector<int>(W, -1));
	vector<vector<set<int>>>s(H, vector<set<int>>(W));
	auto within = [&](int x, int y) {
		return 0 <= x&&x < H && 0 <= y&&y < W;
	};
	rep(i, 0, H)rep(j, 0, W) {
		if (v[i][j] != -1)continue;
		
		int c;
		for (c = 0; s[i][j].count(c); c++);

		v[i][j] = c;

		int x = d, y = 0;
		while (x) {
			if (within(i + x, j + y)) {
				s[i + x][j + y].insert(c);
			}
			x--; y++;
		}
		while (y) {
			if (within(i + x, j + y)) {
				s[i + x][j + y].insert(c);
			}
			x--; y--;
		}


	}

	return 0;
}