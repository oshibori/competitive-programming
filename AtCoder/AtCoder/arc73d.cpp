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
	int N, W; cin >> N >> W;
	vector<int> w(N), v(N); rep(i, 0, N) { cin >> w[i] >> v[i]; }
	vector<vector<int>>x(4, vector<int>(1, 0));
	rep(i, 0, N)x[w[i] - w[0]].emplace_back(v[i]);
	rep(i, 0, 4) {
		sort(1 + all(x[i]), greater<int>());
		rep(j, 1, x[i].size())x[i][j] += x[i][j - 1];
	}
	int ans(0);
	rep(i, 0, x[0].size()) {
		rep(j, 0, x[1].size()) {
			rep(k, 0, x[2].size()) {
				rep(l, 0, x[3].size()) {
					if (i*w[0] + j*(w[0] + 1) + k*(w[0] + 2) + l*(w[0] + 3) <= W)chmax(ans, x[0][i] + x[1][j] + x[2][k] + x[3][l]);
				}
			}
		}
	}
	cout << ans << endl;

	return 0;
}