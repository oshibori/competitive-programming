#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

//#define int long long
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
int fact(int n) {
	if (n == 1)return 1;
	else return n*fact(n - 1);
}
signed main() {

	int N; cin >> N; vector<int>C(N); rep(i, 0, N)cin >> C[i];
	double ans(0);

	rep(i, 0, N) {
		int c(C[i]), s(0);
		rep(j, 0, N) {
			if (i == j)continue;

			if (c%C[j] == 0)s++;
		}

		if (s & 1)ans += 0.5;
		else ans += (double)(s + 2) / (2 * s + 2);
	}

	cout << fixed << setprecision(6) << ans << endl;
























	//int N; cin >> N;
	//if (N >= 9)return 0;
	//vector<int>C(N), v(N);
	//rep(i, 0, N) {
	//	cin >> C[i];
	//	v[i] = i;
	//}
	//double ans(0);
	//do {
	//	vector<int>c(N);
	//	vector<bool>f(N, true);

	//	rep(i, 0, N) {
	//		c[i] = C[v[i]];
	//	}

	//	rep(i, 0, N) {
	//		rep(j, i + 1, N) {
	//			if (c[j] % c[i] == 0)f[j] = !f[j];
	//		}
	//	}

	//	ans += accumulate(all(f), 0);

	//} while (next_permutation(all(v)));

	//cout << fixed << setprecision(6) << ans / fact(N) << endl;

	return 0;
}