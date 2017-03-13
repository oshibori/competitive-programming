#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define DBG 0
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const double EPS = 1e-10;
string LLtoString(int x) {
	dump(x);
	if (x == 0)return "0";
	string s;
	while (x > 0) {
		s.push_back((x % 10) + '0');
		dump(s);
		x /= 10;
	}
	dump(s);
	reverse(all(s));

	return s;
}
signed main() {
	string A, B; cin >> A >> B;
	A = LLtoString(stoll(A) - 1);
	dump(A); dump(B);
	int n(B.size());
	int dp[20][2][2][2];
	memset(dp, 0, sizeof(dp));
	dp[0][0][0][0] = 1;
	rep(i, 0, n)rep(j, 0, 2)rep(k, 0, 2)rep(l, 0, 2) {
		int D(B[i] - '0');

		for (int d = 0; d <= (j ? 9 : D); d++)
			dp[i + 1][j || d < D][k || d == 4][l || d == 9] += dp[i][j][k][l];

	}

	int ansB(0);
	rep(j, 0, 2)rep(k, 0, 2)rep(l, 0, 2) {
		if (k == 1 || l == 1)ansB += dp[n][j][k][l];
	}

	n = A.size();
	memset(dp, 0, sizeof(dp));
	dp[0][0][0][0] = 1;

	rep(i, 0, n)rep(j, 0, 2)rep(k, 0, 2)rep(l, 0, 2) {
		int D(A[i] - '0');

		for (int d = 0; d <= (j ? 9 : D); d++)
			dp[i + 1][j || d < D][k || d == 4][l || d == 9] += dp[i][j][k][l];

	}

	int ansA(0);
	rep(j, 0, 2)rep(k, 0, 2)rep(l, 0, 2) {
		if (k == 1 || l == 1)ansA += dp[n][j][k][l];
	}


	cout << ansB - ansA << endl;

	return 0;
}