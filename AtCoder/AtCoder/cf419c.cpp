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
	int N, M; cin >> N >> M;
	vector<vector<int>>v(N + 1, vector<int>(M + 1));
	rep(i, 0, N)rep(j, 0, M)cin >> v[i][j];
	vector<int>r(N), c(M);
	rep(i, 0, N) {
		int m(INF);
		rep(j, 0, M)chmin(m, v[i][j]);
		r[i] = m;
		rep(j, 0, M)v[i][j] -= m;
	}
	rep(i, 0, M) {
		int m(INF);
		rep(j, 0, N)chmin(m, v[j][i]);
		c[i] = m;
		rep(j, 0, N)v[j][i] -= m;
	}
	bool f(true);
	rep(i, 0, N)rep(j, 0, M)if (v[i][j] > 0)f = false;

	if (f) {
		cout << accumulate(all(r), 0) + accumulate(all(c), 0) << endl;
		rep(i, 0, N) {
			while (r[i]--)cout << "row " << i + 1 << endl;
		}
		rep(i, 0, M) {
			while (c[i]--)cout << "col " << i + 1 << endl;
		}
	}
	else
	{
		cout << -1 << endl;
	}







	return 0;
}