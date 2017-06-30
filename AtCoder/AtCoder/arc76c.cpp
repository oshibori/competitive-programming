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
	int N, M; cin >> N >> M;
	if (abs(N - M) >= 2)cout << 0 << endl;
	else {
		vector<int>v(N + M + 1);
		v[0] = 1;
		rep(i, 1, v.size())v[i] = (v[i - 1] * i) % MOD;
		int a = max(N, M);
		int b = min(N, M);
		if (abs(N - M) == 0) {
			cout << v[N] * (v[N] + v[N]) % MOD << endl;
		}
		else {
			cout << v[N] * v[M] % MOD << endl;
		}
	}
	return 0;
}