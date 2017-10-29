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
	int A, B, C, D, E, F;
	cin >> A >> B >> C >> D >> E >> F;

	int A_max = F / (100 * A);
	int B_max = F / (100 * B);
	set<int>water;
	water.insert(0);
	for (int i = 0; i <= A_max; i++)for (int j = 0; j <= B_max; j++) {
		if (100 * A*i + 100 * B*j <= F)water.insert(100 * A*i + B*j * 100);
	}

	set<double>sugar;
	sugar.insert(0);
	int C_max = F / (C);
	int D_max = F / (D);
	for (int i = 0; i <= C_max; i++)for (int j = 0; j <= C_max; j++) {
		if (C*i + D*j <= F)sugar.insert(C*i + D*j);
	}
	pair<int, int>ans;
	ans.first = 100 * A;
	ans.second = 0;
	double t = 0;
	for (auto &g : water) {
		double x = min(g / 100 * E, F - g);
		auto y = prev(upper_bound(all(sugar), x));

		double tmp = 100.0**y / (g + *y);

		if (g + *y <= F&&tmp > t&&tmp <= 100) {
			t = tmp;
			ans.first = g;
			ans.second = *y;
		}
	}
	dump(A_max, B_max, C_max, D_max);
	dump(sugar);
	dump(water);
	dump(t);
	cout << ans.first + ans.second << " " << ans.second << endl;
	return 0;
}