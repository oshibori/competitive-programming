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
	int N; cin >> N;
	set<string>s;
	int t(0);
	rep(i, 0, N) {
		int a; cin >> a;
		if (a < 400)s.insert("gray");
		else if (a < 800)s.insert("brawn");
		else if (a < 1200)s.insert("green");
		else if (a < 1600)s.insert("sky");
		else if (a < 2000)s.insert("blue");
		else if (a < 2400)s.insert("yellow");
		else if (a < 2800)s.insert("orange");
		else if (a < 3200)s.insert("red");
		else t++;
	}
	cout << s.size() + (s.size()?0:1) << " " << s.size() + t << endl;
	return 0;
}