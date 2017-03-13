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
const double EPS = 1e-10;
string to_binstring(int v) {
	string res;
	rep(i, 0, 5) {
		if (v & 1)res = "1" + res;
		else res = "0" + res;
		v >>= 1;
	}
	return res;
}
string first(char c) {
	if (c == '?')return to_binstring(31);
	else if (c == '\'')return to_binstring(30);
	else if (c == '-')return to_binstring(29);
	else if (c == ',')return to_binstring(28);
	else if (c == '.')return to_binstring(27);
	else if (c == ' ')return to_binstring(26);
	else return to_binstring(c - 'A');
}

signed main() {
	map<string, char>m;

	m["101"] = ' ';
	m["000000"] = '\'';
	m["000011"] = ',';
	m["10010001"] = '-';
	m["010001"] = '.';
	m["000001"] = '?';
	m["100101"] = 'A';
	m["10011010"] = 'B';
	m["0101"] = 'C';
	m["0001"] = 'D';
	m["110"] = 'E';
	m["01001"] = 'F';
	m["10011011"] = 'G';
	m["010000"] = 'H';
	m["0111"] = 'I';
	m["10011000"] = 'J';
	m["0110"] = 'K';
	m["00100"] = 'L';
	m["10011001"] = 'M';
	m["10011110"] = 'N';
	m["00101"] = 'O';
	m["111"] = 'P';
	m["10011111"] = 'Q';
	m["1000"] = 'R';
	m["00110"] = 'S';
	m["00111"] = 'T';
	m["10011100"] = 'U';
	m["10011101"] = 'V';
	m["000010"] = 'W';
	m["10010010"] = 'X';
	m["10010011"] = 'Y';
	m["10010000"] = 'Z';
	string s;
	while (getline(cin, s)) {
		string t;
		rep(i, 0, s.size())t += first(s[i]);
		dump(t);
		dump(t.size());
		string ans;

		for (int i = 0; i < t.size();i++) {
			dump(i); dump(ans);
			for (int j = 1; j<=8; j++) {
				if (m.find(t.substr(i, j)) != m.end()) {
					ans += m[t.substr(i, j)];
					i += j-1;
					break;
				}
			}
		}

		cout << ans << endl;



	}
	return 0;
}