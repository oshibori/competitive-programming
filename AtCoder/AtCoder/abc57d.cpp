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
	int N, A, B; cin >> N >> A >> B;
	vector<vector<int>>nCr(N + 1, vector<int>(N + 1, 0));
	nCr[0][0] = 1;
	rep(i, 1, N + 1)rep(j, 0, i + 1) {
		if (j == 0 || j == i)nCr[i][j] = 1;
		else nCr[i][j] = nCr[i - 1][j] + nCr[i - 1][j - 1];
	}
	map<int, int>mp;
	vector<int> v(N); rep(i, 0, N) { cin >> v[i]; mp[v[i]]++; }
	sort(all(v), greater<int>());

	if (v[0] == v[A - 1]) {
		cout << fixed << setprecision(6) << v[0] << endl;
		int ans(0);
		rep(i, A, B + 1)ans += nCr[mp[v[0]]][i];
		cout << ans << endl;
	}
	else {
		cout << fixed << setprecision(6) << accumulate(v.begin(), v.begin() + A, 0.0) / A << endl;
		int x(0);
		rep(i, 0, A)x += (v[A - 1] == v[i]);
		cout << nCr[mp[v[A - 1]]][x] << endl;
	}
	return 0;
}