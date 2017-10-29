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
	int N, K; cin >> N >> K;
	vector<int> v(N); rep(i, 0, N) { cin >> v[i]; }
	if (K == 1) {
		cout << *min_element(all(v)) << endl;
	}
	else if (K == 2) {
		vector<int>min_l, min_r;
		min_l.push_back(v[0]);
		min_r.push_back(v.back());
		rep(i, 1, N) {
			min_l.push_back(min(v[i], min_l.back()));
		}
		rrep(i, 0, N - 1) {
			min_r.push_back(min(v[i], min_r.back()));
		}
		int ans(-INF);
		rep(i, 0, N - 1) {
			chmax(ans, max(min_l[i], min_r[N - 2 - i]));
		}
		cout << ans << endl;
		dump(min_l.size(), min_r.size());
		dump(min_l);
		dump(min_r);
	}
	else {
		cout << *max_element(all(v)) << endl;
	}
	return 0;
}