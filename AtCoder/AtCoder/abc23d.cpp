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

template<class F>
int binary_search_(int l, int r, F f) {
	if (f(l))return l; //exception f(l):true
	while (l + 1 < r) {
		int m = (l + r) / 2;
		if (f(m))
			r = m;
		else
			l = m;
	}
	//f(l):false, f(r):true
	return r;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N; cin >> N;
	vector<int>H(N), S(N);
	rep(i, 0, N)cin >> H[i] >> S[i];
	int l = 0, r = INF;

	auto f = [&](int x) {
		vector<int>t(N);
		rep(i, 0, N) {
			if (x - H[i] < 0)return false;
			t[i] = (x - H[i]) / S[i];
		}
		sort(all(t));
		rep(i, 0, N) {
			if (i > t[i])return false;
		}
		return true;
	};
	cout << binary_search_(l, r, f) << endl;

	return 0;
}