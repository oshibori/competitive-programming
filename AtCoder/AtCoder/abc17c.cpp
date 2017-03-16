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
	int N, M; cin >> N >> M;
	vector<int>l(N), r(N), s(N);
	rep(i, 0, N)cin >> l[i] >> r[i] >> s[i];
	int ans = accumulate(all(s), 0);
	vector<int>v(M + 1, 0);
	rep(i, 0, N) {
		v[l[i] - 1] += s[i];
		v[r[i] - 1 + 1] -= s[i];
	}
	rep(i, 1, M)v[i] += v[i - 1];
	cout << ans - *min_element(v.begin(),v.end()-1) << endl;
	return 0;
}