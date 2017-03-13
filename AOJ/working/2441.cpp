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
int cntNum(int l, int r, int div) {
	return (r - 1) / div - (l - 1) / div;
}
int calc(int x) {
	int p = 1;
	int np = 10 * p;
	int ans = 0;
	int cnt(1);
	while (np < x) {
		int fizzbuzz = cntNum(p, np, 15);
		int fizz = cntNum(p, np, 3) - fizzbuzz;
		int buzz = cntNum(p, np, 5) - fizzbuzz;
		int other = (np - p) - (fizzbuzz + fizz + buzz);
		ans += fizzbuzz * 8 + (fizz + buzz) * 4 + other*cnt;
		cnt++;
		p = np;
		np *= 10;
	}
	int fizzbuzz = cntNum(p, x + 1, 15);
	int fizz = cntNum(p, x + 1, 3) - fizzbuzz;
	int buzz = cntNum(p, x + 1, 5) - fizzbuzz;
	int other = (x + 1 - p) - (fizzbuzz + buzz + fizz);
	ans += fizzbuzz * 8 + (fizz + buzz) * 4 + other*cnt;
	return ans;
}
string number = "0123456789";
string trans(int x) {
	if (x % 15 == 0)return "FizzBuzz";
	else if (x % 5 == 0)return "Buzz";
	else if (x % 3 == 0)return "Fizz";
	string ret;
	while (x) {
		ret += number[(int)(x % 10)];
		x /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
signed main() {
	int n; cin >> n;
	int low(0), high(1ll << 60);
	while (low + 1 < high) {
		int mid = (low + high) / 2;
		if (calc(mid) >= n)high = mid;
		else low = mid;
	}
	n -= calc(low);
	string ans;
	//cout << n << endl;
	rep(i, 0, 20) {
		low++;
		if (low % 15 == 0)ans += "FizzBuzz";
		else if (low % 5 == 0)ans += "Buzz";
		else if (low % 3 == 0)ans += "Fizz";
		else ans += trans(low);
	}
	//cout << ans << endl;
	cout << ans.substr(n-1, 20) << endl;
	return 0;
}