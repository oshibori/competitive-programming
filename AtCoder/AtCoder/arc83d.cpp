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
	vector<vector<int>>A(N, vector<int>(N, INF));
	vector<vector<int>>B(A);
	rep(i, 0, N)rep(j, 0, N) { cin >> A[i][j]; }
	int n = N;
	//	M = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());


	rep(i, 0, N)rep(j, 0, N)rep(k, 0, N) {
		if (A[i][j] + A[j][k] == A[i][k]) {
			//dump(i, j, k);
			//dump(A[i][j], A[j][k], A[i][k]);
			//M[i].emplace_back(make_pair(j, A[i][j]));
			//M[j].emplace_back(make_pair(i, A[i][j]));
			//M[j].emplace_back(make_pair(k, A[j][k]));
			//M[k].emplace_back(make_pair(j, A[j][k]));
			chmin(B[i][j], A[i][j]);
			chmin(B[j][i], A[j][i]);
			chmin(B[j][k], A[j][k]);
			chmin(B[k][j], A[k][j]);

		}
	}
	rep(k, 0, n) {
		rep(i, 0, n) {
			if (B[i][k] == INF)continue;
			rep(j, 0, n) {
				if (B[k][j] == INF)continue;
				B[i][j] = min(B[i][j], B[i][k] + B[k][j]);
			}
		}
	}

	if (A != B)cout << -1 << endl;
	else {
		rep(i, 0, N)rep(j, 0, N)rep(k, 0, N) {
			if (i == j || j == k || i == k)continue;
			if (A[i][j] + A[j][k] == A[i][k]) {
				B[i][k] = B[k][i] = 0;
			}
		}

		int sum(0);
		rep(i, 0, N)rep(j, i, N)sum += B[i][j];
		dump(B);
		cout << sum << endl;
	}
	return 0;
}