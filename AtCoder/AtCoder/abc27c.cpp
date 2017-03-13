#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);

signed main() {
	int n; cin >> n;
	int x = 1;
	int depth = log2(n) + 1;
	int cnt(1);
	if (depth & 1) {
		while (x <= n) {
			if (cnt & 1)x = x * 2 + 1;
			else x *= 2;
			cnt++;
		}
	}
	else {
		while (x <= n) {
			if (cnt & 1)x *= 2;
			else x = x*2+1;
			cnt++;
		}
	}

	if (cnt & 1)cout << "Takahashi" << endl;
	else cout << "Aoki" << endl;
	return 0;
}