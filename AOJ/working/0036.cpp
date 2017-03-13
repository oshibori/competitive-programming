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
	string s;
	while (cin >> s) {
		vector<string>v;
		v.push_back(s);
		rep(i, 0, 7) {
			string t; cin >> t;
			v.push_back(t);
		}
		char ans;
		rep(i, 0, 8) {
			rep(j, 0, 8) {
				if (v[i][j] == '1') {
					if (j + 1 < 8 && i + 1 < 8 && v[i][j + 1] == '1'&&v[i + 1][j] == '1'&&v[i + 1][j + 1] == '1')ans = 'A';
					else if (i + 3 < 8 && v[i + 1][j] == '1'&&v[i + 2][j] == '1'&&v[i + 3][j] == '1')ans = 'B';
					else if (j + 3 < 8 && v[i][j + 1] == '1'&&v[i][j + 2] == '1'&&v[i][j + 3] == '1')ans = 'C';
					else if (i + 1 < 8 && j + 2 < 8 && v[i][j + 1] == '1'&&v[i + 1][j + 1] == '1'&&v[i + 1][j + 2] == '1')ans = 'E';
					else if (i + 2 < 8 && j + 1 < 8 && v[i + 1][j] == '1'&&v[i + 1][j + 1] == '1'&&v[i + 2][j + 1] == '1')ans = 'F';
					else if (i + 2 < 8 && j - 1 >= 0 && v[i + 1][j] == '1'&&v[i + 1][j - 1] == '1'&&v[i + 2][j - 1] == '1')ans = 'D';
					else if (j - 1 >= 0 && j + 1 < 8 && i + 1 < 8 && v[i][j + 1] == '1'&&v[i + 1][j] == '1'&&v[i + 1][j - 1] == '1')ans = 'G';
					goto here;
				}
			}
		}
	here:;
		cout << ans << endl;
	}
	return 0;
}