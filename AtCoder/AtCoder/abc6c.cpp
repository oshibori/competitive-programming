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
	int N, M; cin >> N >> M;
	int x(-1), y(-1), z(-1);
	for (int yt = 0; yt <= M / 3; yt++) {
		int x_2z = M - 3 * yt;
		if (x_2z & 1)continue;
		x_2z /= 2;
		int zt = x_2z - (N - yt);
		int xt = N - yt - zt;
		dump(xt, yt, zt);
		if (2 * xt + 3 * yt + 4 * zt == M&&xt + yt + zt == N&&xt >= 0 && yt >= 0 && zt >= 0) {
			x = xt, y = yt, z = zt;
			break;
		}
	}
	printf("%d %d %d\n", x, y, z);
	return 0;
}