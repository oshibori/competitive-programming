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
	int N, K; cin >> N >> K;
	vector<int> a(N + 1); rep(i, 1, N + 1) { cin >> a[i]; }
	int m(0);
	rep(i, 1, N + 1)if (a[i] > 0)m += a[i];

	int l = 0, over0 = 0, sum = 0;
	rep(i, 0, K) {
		if (a[i] > 0)
			over0 += a[i];

		sum += a[i];

	}
	dump(m, l, over0, sum);
	int ans(0);
	rep(i, K, N + 1) {
		if (a[i] > 0)over0 += a[i];
		if (a[l] > 0)over0 -= a[l];
		sum = sum + a[i] - a[l++];

		int x = m - over0;

		chmax(ans, max(x, x + sum));
	}

	cout << ans << endl;
	return 0;
}