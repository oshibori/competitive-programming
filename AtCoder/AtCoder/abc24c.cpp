#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const double EPS = 1e-10;

signed main() {
	int N, D, K; cin >> N >> D >> K;
	vector<int>L(D), R(D), S(K), T(K); vector<bool> B;

	rep(i, 0, D)cin >> L[i] >> R[i];
	rep(i, 0, K)cin >> S[i] >> T[i];
	rep(i, 0, K)B.push_back(S[i] < T[i]);
	vector<int>ans(K, -1);
	rep(i, 0, D) {
		rep(j, 0, K) {
			if (ans[j] != -1)continue;

			if (L[i] <= S[j] && S[j] <= R[i]) {
				if (B[j])S[j] = R[i];
				else S[j] = L[i];
			}

			if (B[j] && S[j] >= T[j] || !B[j]&&S[j]<=T[j])ans[j] = i+1;
		}
	}
	rep(i, 0, K)cout << ans[i] << endl;
	return 0;
}