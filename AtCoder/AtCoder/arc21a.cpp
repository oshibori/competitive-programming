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
	vector<vector<int>>a(4, vector<int>(4));
	rep(i, 0, 4)rep(j, 0, 4)cin >> a[i][j];

	bool f(false);

	rep(i, 0, 4)rep(j, 0, 3)if (a[i][j] == a[i][j + 1]||a[j][i]==a[j+1][i])f = true;
	
	cout << (f ? "CONTINUE" : "GAMEOVER") << endl;

	return 0;
}