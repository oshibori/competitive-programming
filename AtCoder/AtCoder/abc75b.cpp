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
	int H, W; cin >> H >> W;
	vector<string>v(H);
	rep(i, 0, H)cin >> v[i];
	vector<int>dx = { 1,1,0,-1,-1,-1,0,1 }, dy = { 0,1,1,1,0,-1,-1,-1 };
	auto inrange=[&](int i, int j) { return i >= 0 && i < H && j >= 0 && j < W; };
	rep(i, 0, H)rep(j, 0, W) {
		if (v[i][j] == '.') {
			int a(0);
			rep(k, 0, 8) {
				int x = i + dx[k], y = j + dy[k];
				if (!inrange(x, y))continue;
				if (v[x][y] == '#')a++;
			}
			v[i][j] = '0' + a;
		}
	}
	rep(i, 0, H)cout << v[i] << endl;

	return 0;
}