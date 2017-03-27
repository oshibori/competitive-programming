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
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, A, B; cin >> N >> A >> B;
	vector<int>v(N);
	rep(i, 0, N)cin >> v[i];
	sort(all(v), greater<int>());
	double maxave(0.0);
	rep(i, 0, A)maxave += v[i];
	maxave /= A;

	int nCr[51][51];
	rep(i, 0, N + 1)rep(j, 0, i + 1) {
		if (j == 0 || j == i)nCr[i][j] = 1;
		else nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
	}

	int ans(0);
	if (v[0] == v[A - 1]) {
		int cnt = count(all(v), v[0]);
		rep(i, A, B + 1)ans += nCr[cnt][i];
	}
	else {
		int r(0);
		rep(i, 0, A)r += v[i] == v[A - 1];
		int n = count(v.begin(), v.end(), v[A - 1]);
		ans = nCr[n][r];
	}

	cout << fixed << setprecision(8) << maxave << endl << ans << endl;











	//vector<vector<map<int, int>>>dp(N + 1, vector<map<int, int>>(N + 1));

	//function<int(int, int, int)> dfs = [&](int n, int k, int s) {
	//	//dump(n, k, s);
	//	if (dp[n][k].count(s))return dp[n][k][s];

	//	if (n == N) {
	//		if (A <= k&&k <= B) {
	//			//dump(maxave - 1.0*s / k);
	//			//dump(abs(maxave - 1.0*s / k));
	//			//dump(1.0*s / k, maxave, (abs(maxave - 1.0*s / 1.0*k)));
	//			return dp[n][k][s] = (abs(maxave - 1.0*s / k) <= EPS);
	//		}
	//		else return dp[n][k][s] = 0;
	//	}
	//	int ret(0);
	//	ret += dfs(n + 1, k, s);

	//	ret += dfs(n + 1, k + 1, s + v[n]);

	//	return dp[n][k][s] = ret;
	//};

	//cout <<fixed<<setprecision(8)<< maxave << endl << dfs(0, 0, 0) << endl;












	//vector<vector<int>>dp(N + 1, vector<int>(N + 1, -INF));
	//dp[0][0] = 0;
	//rep(i, 0, N)rep(j, 0, i + 1) {
	//	chmax(dp[i + 1][j], dp[i][j]);
	//	chmax(dp[i + 1][j + 1], dp[i][j] + v[i + 1]);
	//}

	//map<double, int>m;
	//double mxx(-INF);
	//for (int i = A; i <= B; i++) {
	//	rep(j, 0, N + 1) {
	//		if (dp[j][i] != -INF) {
	//			m[(double)dp[j][i] / (double)i]++;
	//			chmax(mxx, (double)dp[j][i] / (double)i);
	//		}
	//	}
	//}
	//dump(m);
	//auto aaa = m.find(mxx);
	//cout <<fixed<<setprecision(8)<< aaa->first << endl << aaa->second << endl;

	return 0;
}