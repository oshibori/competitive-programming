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
	int n, S;
	while (cin >> n >> S) {
		dump(n, S);
		vector<int>a(n), sum(n + 1, 0);
		rep(i, 0, n)cin >> a[i];

		rep(i, 0, n)sum[i + 1] = sum[i] + a[i];

		if (sum[n] < S) {
			cout << "0" << endl;
			continue;
		}

		int res(n);
		dump(a);
		dump(sum);
		for (int s = 0; sum[s] + S <= sum[n]; s++) {
			int t = distance(sum.begin(),lower_bound(sum.begin()+ s, sum.end(), sum[s] + S));
			chmin(res, t - s);
		}
		cout << res << endl;

	}

	return 0;
}