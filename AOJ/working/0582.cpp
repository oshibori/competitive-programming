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

signed main() {
	vector<int>v(3, 0);
	int sankaku(0), chokkaku(0), eikaku(0), donkaku(0);
	while (cin >> v[0] >> v[1] >> v[2]) {
		sort(all(v));
		if (v[0] + v[1] > v[2]) {
			sankaku++;
			if (v[0] * v[0] + v[1] * v[1] == v[2] * v[2])chokkaku++;
			else if (v[0] * v[0] + v[1] * v[1] < v[2] * v[2])donkaku++;
			else eikaku++;
		}
		else break;
		//cout << sankaku << " " << chokkaku << " " << eikaku << " " << donkaku << endl;

	}
	cout << sankaku << " " << chokkaku << " " << eikaku << " " << donkaku << endl;
	return 0;
}