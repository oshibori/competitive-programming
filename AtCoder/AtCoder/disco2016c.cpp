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

int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K; cin >> N >> K;
	vector<int> A(N); rep(i, 0, N) { cin >> A[i]; }


	map<int, int>m;
	rep(i, 0, N) {
		m[gcd(A[i], K)]++;
	}
	int ans(0);
	for (auto x : m)for (auto y : m) {
		if (x.first*y.first%K == 0) {
			if (x.first == y.first)ans += x.second*(y.second - 1);
			else ans += x.second*y.second;
		}
	}
	cout << ans/2 << endl;
	return 0;
}