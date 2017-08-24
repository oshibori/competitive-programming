#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
int dy[] = { 1,0,-1,0 }, dx[] = { 0,-1,0,1 };
vector<string>v(2);
bool within(int x, int y) {
	return 0 <= x&&x < 2 && 0 <= y&&y < v[0].size();
}
int dfs(int x = 0, int y = 0, int p = -1) {
	dump(x, y, p);
	if (!within(x, y))return 1;
	auto a = v[x][y];
	int z;
	int block;
	rep(i, 0, 4) {
		int X = x + dx[i], Y = y + dy[i];
		if (!within(X, Y))continue;
		dump(a, v[X][Y]);
		if (a == v[X][Y]) {
			z = i;
		}
	}

	dump(z);
	if (x == 0 && y == 0) {
		if (z == 3)return 3 * dfs(x, y + 1, 1) % MOD;
		else if (z == 0)return 6 * dfs(x, y + 2, 2) % MOD;
	}
	else {
		if (z == 3) {// p=1
			if (p == 1)return 2 * dfs(x, y + 1, 1) % MOD;
			else return dfs(x, y + 1, 1) % MOD;
		}
		else if (z == 0) { // p=2,3
			if (p == 1)return 2 * dfs(x, y + 2, 2) % MOD;
			else return 3 * dfs(x, y + 2, 2) % MOD;
		}
	}

}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	rep(i, 0, 2)cin >> v[i];
	cout << dfs() % MOD << endl;
	return 0;
}