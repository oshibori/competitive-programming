#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
vector<int>year(1, 0), month{ 0,0,31,28,31,30,31,30,31,31,30,31,30,31 }, day;
int YEAR(int n) {
	if (n < year.size())return year[n];

	int x = year.size() - 1;
	while (year.size() <= n) {
		if (x % 4 == 0 && (x % 100 != 0 || x % 400 == 0))year.push_back(year[x] + 366);
		else year.push_back(year[x] + 365);
		x++;
	}

	return year[n];
}
int Month(int y, int m) {
	int res = month[m];
	if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
		if(m>=3)res++;
	}
	return res;
}
signed main() {
	rep(i, 1, month.size())month[i] += month[i - 1];
	while (1) {
		int y1, y2, m1, m2, d1, d2;
		cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
		if (y1 < 0 || y2 < 0 || m1 < 0 || m2 < 0 || d1 < 0 || d2 < 0)break;

		cout << YEAR(y2) - YEAR(y1) + Month(y2, m2) - Month(y1, m1) + d2 - d1 << endl;;
	}
	return 0;
}