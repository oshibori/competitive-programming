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
	int N, M; cin >> N >> M;
	vector<vector<int>>A(N, vector<int>(M));
	rep(i, 0, N)rep(j, 0, M)cin >> A[i][j];
	rep(i, 0, N)rep(j, 0, M)A[i][j]--;
	int ans(INF);
	dump(A);
	vector<int>v(N, 0);
	dump(v);
	int del(-1);
	vector<int>deleted(M, 0);
	while (true) {
		dump(ans);
		vector<int>cnt(M, 0);
		rep(i, 0, N) {
			dump(i, v[i]);
			if (v[i] >= M)goto here;
			cnt[A[i][v[i]]]++;
		}
		dump(ans);
		auto x = max_element(all(cnt));
		int dist = distance(cnt.begin(), x);
		if (deleted[dist] == 1)break;
		else deleted[dist] = 1;

		chmin(ans, *x);

		rep(i, 0, N) {
			if (A[i][v[i]] == dist)v[i]++;
		}

	}
	here:
	cout << ans << endl;
	return 0;
}