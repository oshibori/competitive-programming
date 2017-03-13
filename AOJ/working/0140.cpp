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
string str = "6 7 8 9 5 4 3 2 1 0 1 2 3 4 5 6 7 8 9";
string getstr(char s, char g) {
	int i, j;
	for (i = 0; str[i] != s; i++);
	for (j = i; str[j] != g; j++)if (str[j] == s)i = j;
	return str.substr(i, j - i + 1);
}
signed main() {
	int n; cin >> n;
	while (n--) {
		char a, b; cin >> a >> b;
		cout << getstr(a, b) << endl;
	}
	return 0;
}