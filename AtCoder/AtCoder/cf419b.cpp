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
	int n, k, q; cin >> n >> k >> q;
	vector<int>imos(2 * 100000 + 10, 0);
	rep(i, 0, n) {
		int a, b; cin >> a >> b;
		imos[a]++; imos[b + 1]--;
	}
	rep(i, 1, imos.size())imos[i] += imos[i - 1];
	rep(i, 0, imos.size())imos[i] = imos[i] >= k;
	rep(i, 1, imos.size())imos[i] += imos[i - 1];
	rep(i, 0, q) {
		int a, b; cin >> a >> b;
		cout << imos[b] - imos[a - 1] << endl;
	}











	return 0;
}