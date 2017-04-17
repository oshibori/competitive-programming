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

bool check(int x) {
	string s = to_string(x);
	bool f(true);
	rep(i, 1, s.size()) {
		if (s[i - 1] > s[i])f = false;
	}
	return f;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int T; cin >> T;
	rep(i, 0, T) {
		int N; cin >> N;
		while (!check(N))N--;
		cout << "Case #" << i + 1 << ": " << N << endl;
	}

	return 0;
}