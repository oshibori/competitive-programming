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
	int N(10010000);
	vector<bool>p(N, true); p[0] = p[1] = false;
	for (int i = 2; i*i <= N; i++) {
		if (p[i]) {
			for (int j = i + i; j < N; j += i)p[j] = false;
		}
	}
	int n;
	while (cin >> n, n) {
		for (int i = n; i >= 13; i--) {
			if (p[i] && p[i - 2] && p[i - 6] && p[i - 8]) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}