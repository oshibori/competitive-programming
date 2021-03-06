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
	int N, x; cin >> N >> x;
	if (x == 1 || x == 2 * N - 1)cout << "No" << endl;
	else {
		cout << "Yes" << endl;
		if (N == 2) {
			cout << 1 << endl << 2 << endl << 3 << endl;
		}
		else {

			for (int i = 1; i <= 2 * N - 1; i++) {
				cout << (x + N - i + 2 * N - 1 - 1) % (2 * N - 1) + 1 << endl;
			}

		}
	}
	return 0;
}