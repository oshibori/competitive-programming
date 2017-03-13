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
	int n, m; cin >> n >> m; vector<int>v, result(n, 0);
	rep(i, 0, m) {
		int a; cin >> a; v.push_back(--a);
	}

	rep(i, 0, m) {
		vector<int>vote;
		int x(0);
		rep(j, 0, n) {
			int b; cin >> b; vote.push_back(--b);
			if (vote[j] == v[i]) {
				result[j]++;
			}
			else x++;
		}
		result[v[i]] += x;

	}
	rep(i, 0, n)cout << result[i] << endl;
	return 0;
}