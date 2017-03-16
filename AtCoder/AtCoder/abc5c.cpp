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
	int T; cin >> T;
	int N; cin >> N;
	vector<int>A(N); rep(i, 0, N)cin >> A[i];
	int M; cin >> M;
	vector<int>B(M); rep(i, 0, M)cin >> B[i];

	bool f(true);

	rep(i, 0, M) {
		bool g(false);
		rep(j, 0, N) {
			if (A[j] <= B[i] && B[i] <= A[j] + T) {
				A[j] = INF;
				g = true;
				break;
			}
		}
		f = g;
		if (!f)break;
	}

	cout << (f ? "yes" : "no") << endl;

	return 0;
}