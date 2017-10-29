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
	int N; cin >> N;
	vector<string>v(N);
	rep(i, 0, N)cin >> v[i];
	int ans(0);
	auto within = [&](int x, int y) {
		return 0 <= x&&x < N && 0 <= y&&y < N;
	};
	int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
	rep(i, 0, N)rep(j, 0, N) {

		bool g(v[i][j]=='x');
		rep(k, 0, 4) {
			int x = dx[k] + i;
			int y = dy[k] + j;
			if (!within(x, y))continue;
			if (v[x][y] != 'x')g = false;
		}
		if (g) {
			ans++;
			rep(k, 0, N)v[k][j] = 'o', v[i][k] = 'o';
		}
		dump(v);
	}
	cout << ans << endl;
	return 0;
}