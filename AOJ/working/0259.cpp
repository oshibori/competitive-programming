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
bool NA(string s) {
	if (s == "1111" || s == "2222" || s == "3333" || s == "4444" || s == "5555" || s == "6666" || s == "7777" || s == "8888" || s == "9999")return true;
	else return false;
}
signed main() {
	string s;
	while (cin >> s, s != "0000") {
		int ans(0);
		while (s != "6174") {
			if (NA(s)) {
				cout << "NA" << endl;
				goto here;
			}
			string big(s), small(s);
			sort(all(small));
			sort(all(big), greater<char>());
			s = to_string(stoi(big) - stoi(small));
			while (s.size() < 4)s = "0" + s;
			ans++;
		}
		cout << ans << endl;
	here:;

	}
	return 0;
}