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

void change(string &s, char x, char c) {
	rep(i, 0, s.size()) {
		if (s[i] == x)s[i] = c;
	}
}
int eval(string &s, int &k) {
	if (s[k] == 'T')return 1;
	else if (s[k] == 'F')return 0;
	else if (s[k] == '-') {
		k++;
		int res = eval(s, k);
		return (1 - res);
	}
	else if (s[k] == '(') {
		k++;
		int a = eval(s, k);
		k++;
		char op = s[k];
		k++;
		int b = eval(s, k);
		k++;
		int r;
		if (op == '+')r = a | b;
		else if (op == '*')r = a&b;
		else if (op == '>')r = (a == 1 && b == 0) ? 0 : 1;
		return r;
	}
}
signed main() {
	string s;
	while (cin >> s, s != "#") {
		string str;
		for (int i = 0; i < s.size(); i++) {
			if (i == s.size() - 1)str.push_back(s[i]);
			else if (s[i] == '-'&&s[i + 1] == '>') {
				str.push_back('>');
				i++;
			}
			else str.push_back(s[i]);
		}

		string ex1, ex2; bool f(false);
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '=')f = true;
			else if (f)ex2.push_back(str[i]);
			else ex1.push_back(str[i]);
		}

		int c[256]; memset(c, 0, sizeof(c));
		rep(i, 0, str.size())c[str[i]] = 1;
		vector<char>vc;
		for (char x = 'a'; x <= 'k'; x++)if (c[x])vc.push_back(x);
		int N = vc.size();

		bool ans = true;
		for (int bits = 0; bits < (1 << N); bits++) {
			string ex1_(ex1), ex2_(ex2);
			rep(i, 0, N) {
				if (bits&(1 << i)) {
					change(ex1_, vc[i], 'T');
					change(ex2_, vc[i], 'T');
				}
				else {
					change(ex1_, vc[i], 'F');
					change(ex2_, vc[i], 'F');
				}
			}
			int t(0);
			int a = eval(ex1_, t);
			t = 0;
			int b = eval(ex2_, t);
			if (a != b) {
				ans = false;
				break;
			}
		}
		if (ans)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}