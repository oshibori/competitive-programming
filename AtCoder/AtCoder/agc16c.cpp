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
	int H, W, h, w; cin >> H >> W >> h >> w;
	if (H%h == 0 || W%w == 0) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
		vector<int>v(W + 1);
		v[0] = 0; v[W] = 1;
		rep(i, 1, w)v[i] = 11111600;
		rep(i, 0, W - w + 1)v[i + w] = v[i] - 1;
		vector<int>a(W);
		rep(i, 0, W)a[i] = v[i + 1] - v[i];
		rep(i, 0, H)rep(j, 0, W)cout << a[j] << (j == W-1 ? '\n' : ' ');
	}
	return 0;
}