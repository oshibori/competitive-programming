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
	vector<string>v;
	rep(i, 0, 8) {
		string s; cin >> s; v.push_back(s);
	}

	cout << 90 << endl;
	rep(j, 0, 8) {
		rrep(i, 0, 8) {
			cout << v[i][j];
		}
		cout << endl;
	}

	cout << 180 << endl;
	rrep(i, 0, 8) {
		rrep(j, 0, 8) {
			cout << v[i][j];
		}
		cout << endl;
	}

	cout << 270 << endl;
	rrep(j, 0, 8) {
		rep(i, 0, 8) {
			cout << v[i][j];
		}
		cout << endl;
	}

	return 0;
}