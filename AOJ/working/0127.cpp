#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DBG 0
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
	vector<vector<char>>v(7, vector<char>(7));
	char a = 'a';
	rep(j, 1, 7) {
		rep(i, 1, 6) {
			v[i][j] = a++;
		}
	}

	v[2][6] = '.'; v[3][6] = '?'; v[4][6] = '!'; v[5][6] = ' ';
	rep(i, 0, 6)dumpc(v[i]);
	while (cin >> s) {
		string ans;
		if (s.size() & 1) {
			cout << "NA" << endl;
			continue;
		}
		bool f(false);
		rep(i, 0, s.size()) {
			if (!('1' <= s[i] && s[i] <= '6')) {
				cout << "NA" << endl;
				goto here;
			}
		
		}
		for (int i = 0; i + 1 < s.size(); i += 2) {
			if (s[i + 1] == '6') {
				cout << "NA" << endl;
				goto here;
			}
			ans += v[s[i + 1] - '0'][s[i] - '0'];
		}
		cout << ans << endl;
	here:
		;
	}
	return 0;
}