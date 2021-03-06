#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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
	int N, x; cin >> N >> x;
	vector<int> a(N); rep(i, 0, N) { cin >> a[i]; }
	vector<vector<int>>b(N, vector<int>(N, INF));
	rep(i, 0, N)b[i][0] = a[i];
	
	int ans(INF);
	rep(k, 0, N) {
		int tmp(k*x);
		rep(i, 0, N) {
			if (k == 0)b[i][k] = a[i];
			else b[i][k] = min(b[i][k - 1], a[(i - k + N) % N]);
			tmp += b[i][k];
		}
		chmin(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}