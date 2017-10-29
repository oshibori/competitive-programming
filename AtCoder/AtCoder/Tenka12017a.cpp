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
	int N; cin >> N;
	vector<int>v;

	rep(n, 1, 3501)rep(h, 1, 3501) {
		int a = -N*h*n;
		int b = N*(n + h) - 4 * h*n;
		if (b == 0)continue;
		if (a%b == 0 && a / b > 0) {
			v.push_back(h);
			v.push_back(n);
			v.push_back(a / b);
			goto here;
		}
	}
	dump(v);
	here:
	rep(i, 0, v.size()) {
		cout << v[i] << (i == v.size() - 1 ? '\n' : ' ');
	}
	return 0;
}