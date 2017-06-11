#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
int cov(char c) {
	if (c == 'I')return 1;
	else if (c == 'V')return 5;
	else if (c == 'X')return 10;
	else if (c == 'L')return 50;
	else if (c == 'C')return 100;
	else if (c == 'D')return 500;
	else return 1000;
}
int arab(string s) {
	int ret(0);
	rep(i, 0, s.size() - 1) {
		if (cov(s[i]) < cov(s[i + 1]))ret -= cov(s[i]);
		else ret += cov(s[i]);
	}
	ret += cov(s.back());
	return ret;
}
string rome(int a) {
	if (a > 3999)return "ERROR";
	string ret;
	int x = a / 1000;
	while (x--)ret += "M";
	a %= 1000;
	if (a / 100 * 100 == 900)ret += "CM", a -= 900;
	else if (a / 100 * 100 == 400)ret += "CD", a -= 400;
	else {
		if (a >= 500)ret += "D", a -= 500;
		int y = a / 100;
		while (y--)ret += "C", a -= 100;
	}
	if (a / 10 * 10 == 90)ret += "XC", a -= 90;
	else if (a / 10 * 10 == 40)ret += "XL", a -= 40;
	else {
		if (a >= 50)ret += "L", a -= 50;
		int c = a / 10;
		while (c--)ret += "X", a -= 10;
	}
	if (a == 9)ret += "IX", a -= 9;
	else if (a == 4)ret += "IV", a -= 4;
	else {
		if (a >= 5)ret += "V", a -= 5;
		while (a--)ret += "I";
	}
	return ret;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<string>v(N); rep(i, 0, N)cin >> v[i];
	int sum(0);
	rep(i, 0, v.size())sum += arab(v[i]);
	cout << rome(sum) << endl;
	return 0;
}