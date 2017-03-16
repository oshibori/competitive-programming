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
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, H; cin >> N >> H;
	int A, B, C, D, E; cin >> A >> B >> C >> D >> E;


	int ans(INF);

	rep(x, 0, N + 1) {
		int y = (E*(N - x) - H - B*x) / (D + E) + 1;
		if ((E*(N - x) - H - B*x) <= 0)y = 0;
		chmin(ans, A*x + C*y);
	}

	cout << (ans) << endl;
	return 0;
}