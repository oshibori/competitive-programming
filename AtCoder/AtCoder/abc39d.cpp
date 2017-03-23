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
	int H, W; cin >> H >> W;
	vector<string>v(H); rep(i, 0, H)cin >> v[i];
	vector<string>before(v);

	auto within = [&](int x, int y) {
		return 0 <= x&&x < H && 0 <= y&&y < W;
	};

	int dx[]{ 1,1,0,-1,-1,-1,0,1 }, dy[]{ 0,1,1,1,0,-1,-1,-1 };

	rep(i, 0, H)rep(j, 0, W) {
		if (v[i][j] == '.') {
			rep(k, 0, 8) {
				int X = i + dx[k], Y = j + dy[k];
				if (within(X, Y))before[X][Y] = '.';
			}
		}
	}

	vector<string>after(before);
	rep(i, 0, H)rep(j, 0, W) {
		if (before[i][j] == '#') {
			rep(k, 0, 8) {
				int X = i + dx[k], Y = j + dy[k];
				if (within(X, Y))after[X][Y] = '#';
			}
		}
	}

	auto vec_equal = [&](vector<string>&a, vector<string>&b) {
		rep(i, 0, H)rep(j, 0, W)if (a[i][j] != b[i][j])return false;
		return true;
	};

	if (vec_equal(after, v)) {
		cout << "possible" << endl;
		rep(i, 0, H)cout << before[i] << endl;
	}
	else cout << "impossible" << endl;
	
	return 0;
}