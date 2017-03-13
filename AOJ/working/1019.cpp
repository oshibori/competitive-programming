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
	int n, k;
	while (cin >> n >> k, n || k) {
		vector<int>s(k, 0);
		vector<vector<int>>b(k, vector<int>(n));
		rep(i, 0, k)cin >> s[i];
		rep(i, 0, n) rep(j, 0, k)cin >> b[j][i];
		rep(j, 0, k) {
			if (accumulate(all(b[j]), 0) > s[j]) {
				cout << "No" << endl;
				goto here;
			}
		}
		cout << "Yes" << endl;
	here:;
	}
	return 0;
}