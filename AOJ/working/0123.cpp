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
	double m5, m10;
	while (cin >> m5 >> m10) {
		if (m5 < 35.50&&m10 < 71)cout << "AAA" << endl;
		else if (m5 < 37.50&&m10 < 77)cout << "AA" << endl;
		else if (m5 < 40 && m10 < 83)cout << "A" << endl;
		else if (m5 < 43 && m10 < 89)cout << "B" << endl;
		else if (m5 < 50 && m10 < 105)cout << "C" << endl;
		else if (m5 < 55 && m10 < 116)cout << "D" << endl;
		else if (m5 < 70 && m10 < 148)cout << "E" << endl;
		else cout << "NA" << endl;
	}
	return 0;
}