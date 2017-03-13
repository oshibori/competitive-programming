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
	string y, m, d;
	while (cin >> y >> m >> d) {
		//if (y <= 1868 && m <= 9 && d < 8)cout << "pre-meiji" << endl;
		//else if (y <= 1912 && m <= 7 && d < 30)cout << "meiji" << endl;
		//else if (y <= 1926 && m <= 12 && d < 25)cout << "taisho" << endl;
		//else if (y <= 1989 && m <= 1 && d < 8)cout << "showa" << endl;
		//else cout << "heisei" << endl;
		while (y.size() < 4)y = "0" + y;
		while (m.size() < 2)m = "0" + m;
		while (d.size() < 2)d = "0" + d;

		string s = y + m + d;

		if (s < "18680908")cout << "pre-meiji" << endl;
		else if (s < "19120730")cout << "meiji" << " " << stoi(y) - 1868 + 1 << " " << stoi(m) << " " << stoi(d) << endl;
		else if (s < "19261225")cout << "taisho" << " " << stoi(y) - 1912 + 1 << " " << stoi(m) << " " << stoi(d) << endl;
		else if (s < "19890108")cout << "showa" << " " << stoi(y) - 1926 + 1 << " " << stoi(m) << " " << stoi(d) << endl;
		else cout << "heisei" << " " << stoi(y) - 1989 + 1 << " " << stoi(m) << " " << stoi(d) << endl;

	}
	return 0;
}