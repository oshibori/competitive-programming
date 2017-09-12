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
	int N; cin >> N;
	vector<int> p(N + 1), pos(N + 1); rep(i, 1, N + 1) { cin >> p[i]; pos[p[i]] = i; }
	vector<int>a(N + 1), b(N + 1);
	rep(i, 1, N + 1) {
		a[i] = i*(N); b[i] = (N + 1 - i)*(N);
	}
	dump(a);
	dump(b);
	rep(i, 1, N + 1) {
		// -:i, +:N+1-i
		
		a[p[i]] += i - 1;
	}
	rep(i, 1, N + 1)cout << a[i] << (i == N ? '\n' : ' ');

	rep(i, 1, N + 1)cout << b[i] << (i == N ? '\n' : ' ');

	return 0;
}