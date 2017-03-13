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
string out(int x) {
	string res = to_string(x);
	while (res.size() < 2)res = "0" + res;
	return res;
}
string output(int sum) {
	string ans;
	ans += out(sum / 3600);
	ans += ":";
	sum %= 3600;
	ans += out(sum / 60);
	ans += ":";
	sum %= 60;
	ans += out(sum);
	return ans;
}
signed main() {
	int t, h, s;
	while (cin >> t >> h >> s, t != -1) {
		int sum = 120*60;
		sum -= 60 * 60 * t + 60 * h + s;
		cout << output(sum) << endl;
		cout << output(sum * 3) << endl;
	}
	return 0;
}