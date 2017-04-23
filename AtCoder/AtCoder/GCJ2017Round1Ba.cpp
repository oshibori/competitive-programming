#include "bits/stdc++.h"
#include<iterator>
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
	int T; cin >> T;
	rep(t, 0, T) {
		int D, N; cin >> D >> N;
		vector<double>v(N);
		rep(i, 0, N) {
			int K, S; cin >> K >> S;
			v[i] = 1.0*(D - K) / S;
		}
		double x = *max_element(all(v));

		cout << "Case #" << t + 1 << ": " << fixed << setprecision(6) << D / x << endl;
	}
	return 0;
}