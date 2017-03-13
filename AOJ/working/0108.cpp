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
vector<int> next(vector<int>v) {
	
	vector<int>res;
	rep(i, 0, v.size()) {
		res.push_back(count(all(v), v[i]));
	}
	return res;
}
signed main() {
	int n; 
	while (cin >> n, n) {
		vector<int>w, v(n); rep(i, 0, n)cin >> v[i];
		int cnt(0);
		while (1) {
			w = v;
			v = next(v);
			if (v == w)break;
			cnt++;
		}
		cout << cnt << endl;
		rep(i, 0, v.size()) cout << v[i] << (i == v.size() - 1 ? '\n' : ' ');
	}
	return 0;
}