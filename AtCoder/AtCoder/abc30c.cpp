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
	int N, M, X, Y; cin >> N >> M >> X >> Y;
	vector<int>a(N), b(M);
	rep(i, 0, N)cin >> a[i]; rep(i, 0, M)cin >> b[i];

	int ans(0), time(0);

	int i(0), j(0);
	while (1) {

		if (ans & 1) {
			auto x=lower_bound(all(b), time);
			if (x == b.end())break;
			time = *x + Y;
			ans++;
		}
		else {
			auto x = lower_bound(all(a), time);
			if (x == a.end())break;
			time = *x + X;
			ans++;
		}


	}
	cout << ans / 2 << endl;
	return 0;
}