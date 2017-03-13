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
int N = 10005;
signed main() {
	vector<bool>p(N, true);
	p[0] = p[1] = false;
	rep(i, 2, sqrt(N)) {
		if (p[i]) {
			for (int j = i + i; j < N; j += i) {
				p[j] = false;
			}
		}
	}
	int n;
	while (cin >> n, n) {
		int a, b;
		for (int i = n; i >= 0; i--) {
			if (p[i] && p[i - 2]) {
				cout << i - 2 << " " << i << endl;
				break;
			}
		}
	}
	return 0;
}