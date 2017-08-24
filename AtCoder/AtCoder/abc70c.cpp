#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int unsigned long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
//Å‘åŒö–ñ”
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
//Å¬Œö”{”
int lcm(int x, int y) { return x*y / gcd(x, y); }
//Å‘åŒö–ñ” •¡”ŒÂ
int gcd(const vector<int> &v) {
	int ret = v[0];
	for (int i = 1; i < v.size(); i++)
		ret = gcd(ret, v[i]);
	return ret;
}
//Å¬Œö”{” •¡”ŒÂ
int lcm(vector<int> &v) {
	int ret = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (ret%v[i] == 0)continue;
		bool f(false);
		int x = gcd(ret, v[i]);
		if (ret%x == 0)ret /= x, f = true;
		else if (v[i] % x == 0)v[i] /= x, f = true;

		if (f)ret = ret*v[i];
		else ret = ret*v[i] / x;
		
		dump(ret);
	}
	return ret;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<int> v(N); rep(i, 0, N) { cin >> v[i]; }
	sort(all(v), greater<int>());
	cout << lcm(v) << endl;
	return 0;
}