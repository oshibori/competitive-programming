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

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s, e;
	cin >> s >> e;
	int N; cin >> N;
	map<string, int>m, r;
	m["v"] = 0;
	m["<"] = 1;
	m["^"] = 2;
	m[">"] = 3;
	r["v"] = 0;
	r["<"] = 3;
	r["^"] = 2;
	r[">"] = 1;

	N %= 4;
	bool f = (m[s] + N) % 4 == m[e];
	bool g = (r[s] + N) % 4 == r[e];
	if (f&&g)cout << "undefined" << endl;
	else if (f)cout << "cw" << endl;
	else if (g)cout << "ccw" << endl;
	else cout << "undefined" << endl;
	return 0;
}