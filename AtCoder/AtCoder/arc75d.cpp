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
	int N, A, B; cin >> N >> A >> B;
	vector<int> h(N); rep(i, 0, N) { cin >> h[i]; }
	auto f = [&](int k) {
		vector<int>v(h);
		int c(0);
		rep(i, 0, N) {
			v[i] -= B*k;
			if (v[i] > 0) {
				c += (v[i] + (A - B - 1)) / (A - B);
			}
			if (c > k)return false;
		}
		return true;
	};
	int l(0), r(1e9);
	while (r - l > 1) {
		dump(l, r);
		int mid = (l + r) / 2;
		if (f(mid))r = mid;
		else l = mid;
	}
	dump(l, r);
	cout << r << endl;
	return 0;
}