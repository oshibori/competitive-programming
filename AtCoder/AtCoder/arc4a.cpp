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
	double ans(0);
	int N; cin >> N;
	vector<double> a(N), b(N); rep(i, 0, N) { cin >> a[i] >> b[i]; }
	rep(i, 0, N)rep(j, i + 1, N)chmax(ans, sqrt((a[i] - a[j])*(a[i] - a[j]) + (b[i] - b[j])*(b[i] - b[j])));
	cout << ans << endl;
	return 0;
}