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
bool check(char x) {
	set<char>s;
	s.insert('a');
	s.insert('t');
	s.insert('c');
	s.insert('o');
	s.insert('d');
	s.insert('e');
	s.insert('r');
	if (s.find(x) == s.end())return false;
	else return true;
}
signed main() {
	string s, t; cin >> s >> t;
	rep(i, 0, s.length()) {
		if (s[i] == t[i])continue;
		else {
			if ((s[i] == '@'&&check(t[i])) || (t[i] == '@'&&check(s[i])))continue;
			else {
				dump(i);
				cout << "You will lose" << endl;
				return 0;
			}
		}
	}
	cout << "You can win" << endl;
	return 0;
}