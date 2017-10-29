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
	int H, W; cin >> H >> W;
	vector<string>v(H);
	rep(i, 0, H)cin >> v[i];
	map<char, int>m;
	rep(i, 0, H)rep(j, 0, W) {
		m[v[i][j]]++;
	}

	bool f(H % 2 == 0), g(W % 2 == 0);
	bool h = true;
	if (f&&g) {

		for (auto &x : m)if (x.second % 4 != 0)h = false;
	}
	else if (f || g) {
		int sum(0);
		for (auto &x : m) {
			sum += x.second % 4;
			if (x.second % 2 == 1)h = false;
		}
		if (sum > H&&f)h = false;
		else if (sum > W&&g)h = false;
	}
	else {
		int sum(0);
		int cnt(0);
		for (auto &x : m) {
			sum += x.second % 4;
			if (x.second % 2 == 1)cnt++;
		}
		if (cnt != 1 || sum > H + W - 1)h = false;
	}

	cout << (h ? "Yes" : "No") << endl;
	return 0;
}