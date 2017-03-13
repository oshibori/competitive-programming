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
int MOD = (int)(1e9 + 7);

int pow_mod(int a, int b) {
	int res(1);
	while (b > 0) {
		if (b & 1)res = (res*a) % MOD;
		a = a*a%MOD;
		b >>= 1;
	}
	return res;
}
vector<int>f((int)1e6 + 1, -1);
int fact(int n) {
	if (f[n] != -1)return f[n];
	if (n == 0)return 1;
	else return f[n] = n*fact(n - 1) % MOD;
}

int nCr_mod(int n, int r) {
	return (fact(n)*pow_mod(fact(r), MOD - 2) % MOD)*pow_mod(fact(n - r), MOD - 2) % MOD;
}
signed main() {
	int w, h; cin >> w >> h;
	cout << nCr_mod(w - 1 + h - 1, w - 1) << endl;


	return 0;
}