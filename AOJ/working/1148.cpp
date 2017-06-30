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
	int N, M;
	while (cin >> N >> M, N&&M) {
		int r; cin >> r;
		vector<vector<int>>v(M, vector<int>(1300, 0));
		rep(i, 0, r) {
			int t, n, m, s; cin >> t >> n >> m >> s;
			m--;
			if (s) {
				v[m][t]++;
			}
			else {
				v[m][t]--;
			}
		}
		rep(i, 0, M) {
			rep(j, 1, v[i].size())v[i][j] += v[i][j - 1];
			rep(j, 0, v[i].size())v[i][j] = v[i][j] > 0;
			rep(j, 1, v[i].size())v[i][j] += v[i][j - 1];
		}

		int q; cin >> q;
		rep(i, 0, q) {
			int ts, te, m; cin >> ts >> te >> m;
			m--;
			//rep(i, ts-1, te + 1)cout << v[m][i] << (i == te + 9 ? '\n':  ' ');
			cout << v[m][te-1] - v[m][ts-1] << endl;

		}
	}
	return 0;
}