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

signed main() {
	string S; cin >> S;
	int n(0), s(0),w(0),e(0);
	rep(i, 0, S.length()) {
		if (S[i] == 'N')n++;
		else if (S[i] == 'S')s++;
		else if (S[i] == 'W')w++;
		else if (S[i] == 'E')e++;
	}
	bool x(false), y(false);
	if ((n == 0 && s == 0) || (n > 0 && s > 0)) {
		x = true;
	}
	if ((e == 0 && w == 0) || (e > 0 && w > 0)) {
		y = true;
	}
	if (x&&y)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}