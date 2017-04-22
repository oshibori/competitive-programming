#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

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
	int M, N; cin >> M >> N;
	vector<int>s(M), p(N);
	rep(i, 0, M)cin >> s[i]; rep(i, 0, N)cin >> p[i];
	vector<int>v(N*(N+1)/2, INF); int c(0);
	rep(i, 0, N)rep(j, i, N)v[c++]=(p[i] * p[j]);
	sort(all(v));
	rep(i, 0, M) {
		cout << *lower_bound(all(v), s[i]) - s[i] << endl;
	}
	return 0;
}