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
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K; cin >> N >> K;
	vector<int> v(N); rep(i, 0, N) { cin >> v[i]; }
	int M = *max_element(all(v));
	if (N == 1) {
		if (v[0] == K)cout << "POSSIBLE" << endl;
		else cout << "IMPOSSIBLE" << endl;
	}
	else {
		if (M < K) {
			cout << "IMPOSSIBLE" << endl;
		}
		else if (M == K)cout << "POSSIBLE" << endl;
		else {
			M = *min_element(all(v));
			bool f(true);
			rep(i, 0, N) {
				if (gcd(M, v[i]) == 1)f = false;
			}
			if (f) {
				sort(all(v));
				bool g(false);
				rep(i, 1, N) {
					if (v[i] >= K&&K%gcd(v[0], v[i]) == 0)g = true;
				}
				if (g)cout << "POSSIBLE" << endl;
				else cout << "IMPOSSIBLE" << endl;
			}
			else cout << "POSSIBLE" << endl;
		}
	}
	return 0;
}