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

signed main() {
	int a, b, cnt(0);
	while (cin >> a >> b, a || b) {
		bool f(false);
		if(cnt++)cout << endl;
		for (int i = a; i <= b; i++) {
			if ((i % 4 == 0) && ((!(i % 100 == 0)) || (i % 400 == 0))) {
				cout << i << endl;
				f = true;
			}
		}
		if (f == false)cout << "NA" << endl;
	}
	return 0;
}