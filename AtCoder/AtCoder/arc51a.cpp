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
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	vector<int>x(4), y(4);
	int r, a, b;
	cin >> a >> b >> r;
	rep(i, 0, 2) {
		cin >> x[i] >> y[i];
	}
	x[2] = x[0]; x[3] = x[1];
	y[2] = y[1]; y[3] = y[0];
	string red, blue;

	int f(0);
	rep(i, 0, 4)if ((x[i] - a)*(x[i] - a) + (y[i] - b)*(y[i] - b) > r*r)f++;
	if (f == 0)red = "YES", blue = "NO";
	else if (f == 4) {
		int dx[]{ r,0,-r,0 }, dy[]{ 0,r,0,-r };
		bool g(true);
		rep(i, 0, 4) {
			int X = a + dx[i], Y = b + dy[i];
			if (!(x[0] <= X&&X <= x[1] && y[0] <= Y&&Y <= y[1]))g = false;
		}
		if (g)red = "NO", blue = "YES";
		else red = "YES", blue = "YES";
	}
	else red = "YES", blue = "YES";

	cout << red << endl << blue << endl;


	return 0;
}