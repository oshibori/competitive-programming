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

	int T; cin >> T;
	rep(t, 0, T) {
		int N, K; cin >> N >> K;
		//vector<int>stall(N + 2, 1); stall[0] = stall[N + 1] = 0;

		//vector<int>L(N + 2, 0), R(N + 2, 0), M(N + 2, 0), m(N + 2, 0);
		int index(1);
		priority_queue<int>pq; pq.push(N);
		rep(i, 0, K-1) {
			int n = pq.top(); pq.pop();
			pq.push((n - 1) / 2);
			pq.push((n - 1) - (n - 1) / 2);
			//rep(j, 1, N + 1) {
			//	if (stall[j] == 0)L[j] = 0;
			//	else if (stall[j - 1])L[j] = L[j - 1] + 1;
			//	else L[j] = 0;
			//}
			//rrep(j, 1, N + 1) {
			//	if (stall[j] == 0)R[j] = 0;
			//	else if (stall[j + 1])R[j] = R[j + 1] + 1;
			//	else R[j] = 0;
			//}
			//rep(j, 1, N + 1) {
			//	M[j] = max(L[j], R[j]);
			//	m[j] = min(L[j], R[j]);
			//}
			//index = 1;
			//rep(j, 1, N + 1) {
			//	if (m[index] <= m[j]) {
			//		if (m[index] == m[j] && M[index] < M[j]) {
			//			index = j;
			//		}
			//		else if (m[index] < m[j])index = j;
			//	}
			//}
			//stall[index] = 0;
			////dump(L); dump(R); dump(M); dump(m); dump(stall);
		}
		int x = pq.top();
		int M = (x - 1) / 2, m = (x - 1) - (x - 1) / 2;
		cout << "Case #" << t + 1 << ": " << m << " " << M << endl;

	}
	return 0;
}