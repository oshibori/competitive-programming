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
void goahead(char &x, int i) {
	rep(j, 0, i) {
		if (x == 'z')x = 'a';
		else x++;
	}
}
signed main() {
	int n;
	while (cin >> n, n) {
		string mes; cin >> mes;
		vector<int>a(n), b(n);
		rep(i, 0, n)cin >> a[i] >> b[i];
		rrep(i, 0, n) {
			a[i]--; b[i]--;
			goahead(mes[a[i]], abs(a[i] - b[i]));
			goahead(mes[b[i]], abs(a[i] - b[i]));
			swap(mes[a[i]], mes[b[i]]);
		}
		cout << mes << endl;
	}
	return 0;
}