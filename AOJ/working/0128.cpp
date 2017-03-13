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

signed main() {
	string s; int cnt(0);
	while (cin >> s) {
		while (s.size() < 5)s = "0" + s;
		vector<string>v(8, "     ");
		v[2] = "=====";
		rep(i, 0, 5) {
			rep(j, 0, 8) {
				switch (j)
				{
				case 0:
					if ('0' <= s[i] && s[i] <= '4')v[j][i] = '*';
					break;
				case 1:
					if ('5' <= s[i] && s[i] <= '9')v[j][i] = '*';
					break;
				case 2:
					break;
				case 3:
					if (s[i] != '0'&&s[i] != '5')v[j][i] = '*';
					break;
				case 4:
					if (s[i] != '1'&&s[i] != '6')v[j][i] = '*';
					break;
				case 5:
					if (s[i] != '2'&&s[i] != '7')v[j][i] = '*';
					break;
				case 6:
					if (s[i] != '3'&&s[i] != '8')v[j][i] = '*';
					break;
				case 7:
					if (s[i] != '4'&&s[i] != '9')v[j][i] = '*';
					break;
				default:
					break;
				}
			}
		}
		if (cnt++)cout << endl;
		rep(i, 0, 8)cout << v[i] << endl;
	}
	return 0;
}