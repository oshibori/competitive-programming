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
string timeout(int x) {
	int h = x / 60, m = x % 60;
	string ret;
	if (!(h / 10))ret += "0";
	ret += to_string(h);
	if (!(m / 10))ret += "0";
	ret += to_string(m);
	return ret;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<int>v(1500, 0);
	rep(i, 0, N) {
		string s; cin >> s;
		int sh = stoi(s.substr(0, 2)), sm = stoi(s.substr(2, 2)), eh = stoi(s.substr(5, 2)), em = stoi(s.substr(7, 2));
		sm -= sm % 5; em += (em % 5 ? 5 - em % 5 : 0);
		if (em == 60)em = 0, eh++;
		v[60 * sh + sm]++; v[60 * eh + em + 1]--;
	}
	rep(i, 1, 1500)v[i] += v[i - 1];
	bool f(false);
	rep(i, 0, 1500) {
		if (v[i]) {
			if (!f) {
				cout << timeout(i) << '-';
				f = true;
			}
		}
		else {
			if (f) {
				cout << timeout(i-1) << endl;
				f = false;
			}
		}
	}
	return 0;
}