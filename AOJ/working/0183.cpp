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
bool check(vector<string>v, char x) {
	rep(i, 0, 3)if (v[i][0] == x&&v[i][1] == x&&v[i][2] == x || v[0][i] == x&&v[1][i] == x&&v[2][i] == x)return true;
	if (v[0][0] == x&&v[1][1] == x&&v[2][2] == x || v[0][2] == x&&v[1][1] == x&&v[2][0] == x)return true;
	return false;
}
signed main() {
	vector<string>v(3);
	while (cin >> v[0], v[0] != "0") {
		cin >> v[1] >> v[2];
		if (check(v, 'b'))cout << 'b' << endl;
		else if (check(v, 'w'))cout << "w" << endl;
		else cout << "NA" << endl;
	}
	return 0;
}