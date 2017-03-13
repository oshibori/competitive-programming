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
bool isMatch(const string &T, const string s) {
	return T == s.substr(0, T.size());
}
signed main() {
	int N, K; cin >> N >> K;
	vector<bool>result(N, false);
	rep(i, 0, K) {
		int a; cin >> a; a--; result[a] = true;
	}
	vector<string>S(N); rep(i, 0, N)cin >> S[i];
	string ans;

	if (N == K)goto here;

	for (int i = 0;; i++) {
		char c = '#';
		bool f = true;

		for (int j = 0; j < N; j++) {
			if (!result[j])continue;
			if (f) {

				if (j >= S[j].size()) {
					f = false;
					break;
				}

				if (c == '#')c = S[j][i];
				else {
					if (c != S[j][i]) {
						f = false;
						break;
					}
				}
			}
		}
		if (f)ans.push_back(c);
		else break;

		bool g = true;
		rep(i, 0, N) {
			if (result[i]^isMatch(ans, S[i]))g = false;
		}
		if (g)break;

	}


	rep(i, 0, N) {
		if (result[i]^isMatch(ans, S[i]))ans = "-1";
	}

here:;

	cout << ans << endl;

	return 0;
}