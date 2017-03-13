#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long
#define DBG 0
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);

signed main() {
	int n; cin >> n; vector<int>a(n), b(n);
	rep(i, 0, n)cin >> a[i] >> b[i];
	int ans = 0;
	rrep(i, 0, n) {
		
		ans += (b[i] - ((a[i]+ans) % b[i]))%b[i];
		dump(ans);
	}
	cout << ans << endl;




	return 0;
}