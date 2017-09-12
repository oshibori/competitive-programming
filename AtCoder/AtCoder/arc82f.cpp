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
	int X; cin >> X;
	int K; cin >> K;
	vector<int> r(K + 1, 0); rep(i, 1, K + 1) { cin >> r[i]; }
	int Q; cin >> Q;


	vector<int>d; d.emplace_back(0);
	rep(i, 1, K + 1) {
		d.emplace_back(r[i] - r[i - 1]);
	}
	dump(d);
	rep(i, 0, d.size()) {
		if (i & 1)d[i] *= -1;
	}
	dump(d);
//	rep(i, 1, d.size())d[i] += d[i - 1];
	dump(r);
	dump(d);

	auto rel = [&](int &z) {
		if (z < 0)z = 0;
		if (z > X)z = X;
	};

	rep(i, 0, Q) {
		int index(0);
		int t, a; cin >> t >> a;
		while (index < r.size() && r[index] <= t) {
			a += d[index];
			rel(a);
			//dump(a);
			index++;
		}
//		a += d[index];
//		rel(a);
		a += (t - r[index-1])*(index % 2 == 0 ? 1 : -1);
		rel(a);
		cout << a << endl;
	}
	return 0;
}