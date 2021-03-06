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
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N; vector<double>a(N); rep(i, 0, N)cin >> a[i];

	map<double, int>m;

	rep(i, 0, N) {
		m[a[i]]++;
	}
	for (auto it = next(m.begin()); it != m.end(); it++) {
		it->second += prev(it)->second;
	}

	rep(i, 0, N) {
		auto it = m.find(a[i]);
		int sum(0);
		if (it != m.begin())sum += prev(it)->second * 3;
		if (it != m.begin()) {
			sum += (it->second - prev(it)->second - 1);
		}
		else {
			sum += it->second - 1;
		}
		cout << sum << endl;

	}

	return 0;
}