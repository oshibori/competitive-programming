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
int binstring_to_int(string s) {
	int x = 1;
	int res = 0;
	rrep(i, 0, s.size()) {
		if (s[i] == '1')res |= x;
		x <<= 1;
	}

	return res;
}
char crypt(string s) {
	int x = binstring_to_int(s);
	if (x == 26)return ' ';
	else if (x == 27)return '.';
	else if (x == 28)return ',';
	else if (x == 29)return '-';
	else if (x == 30)return '\'';
	else if (x == 31)return '?';
	else {
		return 'A' + (char)x;
	}
}
signed main() {
	map<char, string>m;
	m[' '] = "101";
	m['\''] = "000000";
	m[','] = "000011";
	m['-'] = "10010001";
	m['.'] = "010001";
	m['?'] = "000001";
	m['A'] = "100101";
	m['B'] = "10011010";
	m['C'] = "0101";
	m['D'] = "0001";
	m['E'] = "110";
	m['F'] = "01001";
	m['G'] = "10011011";
	m['H'] = "010000";
	m['I'] = "0111";
	m['J'] = "10011000";
	m['K'] = "0110";
	m['L'] = "00100";
	m['M'] = "10011001";
	m['N'] = "10011110";
	m['O'] = "00101";
	m['P'] = "111";
	m['Q'] = "10011111";
	m['R'] = "1000";
	m['S'] = "00110";
	m['T'] = "00111";
	m['U'] = "10011100";
	m['V'] = "10011101";
	m['W'] = "000010";
	m['X'] = "10010010";
	m['Y'] = "10010011";
	m['Z'] = "10010000";

	string s;
	while (getline(cin, s)) {
		string ans;

		rep(i, 0, s.size()) {
			ans += m[s[i]];
		}
		string cry;
		string t;
		rep(i, 0, ans.size()) {
			t.push_back(ans[i]);
			if (t.size() == 5) {
				cry += crypt(t);
				t.clear();
			}
		}
		if (t.size()) {
			while (t.size() < 5)t = t + "0";
			cry += crypt(t);
		}

		cout << cry << endl;
	}
	return 0;
}