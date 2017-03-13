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
void change(string &s, char x, char b) {
	rep(i, 0, s.size()) {
		if (s[i] == x) {
			s[i] = b;
		}
	}
}
vector<vector<int>>AND({ { 0,0,0 }, { 0,1,1 }, { 0,1,2 } }), OR({ {0,1,2},{1,1,2},{2,2,2} });
vector<int>NOT({ 2,1,0 });
vector<char>vc{ 'P', 'Q', 'R' };

int eval(string &s, int &k) {
	dump(s.substr(k));
	dump(k);
	if (isdigit(s[k])) {
		return s[k] - '0';
	}
	else if (s[k] == '-') {
		return NOT[eval(s, ++k)];
	}
	else if (s[k] == '(') {
		k++;
		int a = eval(s, k);
		dump(a);
		k++;
		char op = s[k];
		dump(op);
		k++;
		int b = eval(s, k);
		k++;
		dump(b);
		if (op == '*') return AND[a][b];
		else if (op == '+')return OR[a][b];
	}
}

signed main() {
	string s;
	while (cin >> s, s != ".") {
		int cnt(0);
		for (char P = '0'; P <= '2'; P++) {
			for (char Q = '0'; Q <= '2'; Q++) {
				for (char R = '0'; R <= '2'; R++) {
					string ex(s);

					change(ex, 'P', P);
					change(ex, 'Q', Q);
					change(ex, 'R', R);

					int k(0);
					if (eval(ex, k) == 2)cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}