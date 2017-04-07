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

bool f(int x) {
	int a = x % 10;
	x /= 10;
	while (x) {
		if (x % 10 != a)return false;
		x /= 10;
	}
	return true;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;

	vector<int>v;
	for (int i(1); v.size() < N; i++) {
		if (f(i))v.push_back(i);
	}
	cout << v[N - 1] << endl;

	return 0;
}