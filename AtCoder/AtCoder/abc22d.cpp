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
	vector<int>Ax(N), Ay(N); rep(i, 0, N)cin >> Ax[i] >> Ay[i];
	vector<int>Bx(N), By(N); rep(i, 0, N)cin >> Bx[i] >> By[i];

	double g1x = accumulate(all(Ax), 0.0) / N, g1y = accumulate(all(Ay), 0.0) / N;
	double g2x = accumulate(all(Bx), 0.0) / N, g2y = accumulate(all(By), 0.0) / N;

	double l1(-INF), l2(-INF);
	rep(i, 0, N) {
		chmax(l1, sqrt(abs(Ax[i] - g1x)*abs(Ax[i] - g1x) + abs(Ay[i] - g1y)*abs(Ay[i] - g1y)));
		chmax(l2, sqrt(abs(Bx[i] - g2x)*abs(Bx[i] - g2x) + abs(By[i] - g2y)*abs(By[i] - g2y)));
	}
	cout << fixed << setprecision(8) << l2 / l1 << endl;

	return 0;
}