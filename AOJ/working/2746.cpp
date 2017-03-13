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
	string s;
	while (cin >> s, s != "#") {
		int a, b, c, d; cin >> a >> b >> c >> d; a--; b--; c--; d--;
		int size(1); rep(i, 0, s.size())if (s[i] == '/')size++;
		vector<string>v;
		string t;
		rep(i, 0, s.size()) {
			if (s[i] == 'b') {
				t.push_back(s[i]);
			}
			else if (isdigit(s[i])) {
				rep(j, 0, s[i] - '0')t.push_back('.');
			}
			else if (s[i] == '/') {
				v.push_back(t);
				t.clear();
			}
		}
		v.push_back(t);
		swap(v[a][b], v[c][d]);
		string ans;
		rep(i, 0, v.size()) {
			int j(0); string t;
			if (i)t += "/";
			while (j < v[i].size()) {
				if (v[i][j] == 'b') {
					t.push_back('b');
					j++;
				}
				else if (v[i][j] == '.') {
					int cnt(0);
					while (v[i][j] == '.'&&j < v[i].size()) {
						cnt++; j++;
					}
					t.push_back(cnt + '0');
				}
			}
			ans += t;
		}
		cout << ans << endl;
	}
	return 0;
}