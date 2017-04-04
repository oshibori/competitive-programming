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
int popcount(int x) {
	int ret(0);
	while (x) {
		ret += (x & 1);
		x >>= 1;
	}
	return ret;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M; cin >> N >> M;
	vector<vector<int>>G(N, vector<int>(N, 0));
	rep(i, 0, N)G[i][i] = 1;
	rep(i, 0, M) {
		int x, y; cin >> x >> y;
		x--, y--;
		G[x][y] = G[y][x] = 1;
	}
	int ans(0);

	rep(bits, 0, (1 << N)) {
		int p = popcount(bits);

		bool f(true);
		rep(i, 0, N) {
			if (bits&(1 << i)) {
				rep(j, 0, N) {
					if (bits&(1 << j) && !G[i][j])f = false;
				}
			}
		}
		if (f) {
			chmax(ans, p);
			dump(p);
		}

	}
	cout << ans << endl;
	return 0;
}