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
	vector<int> a(M), b(M); rep(i, 0, M) { cin >> a[i] >> b[i]; }
	
	int Q; cin >> Q;

	rep(i, 0, Q) {
		int c, d; cin >> c >> d;
		int cx(c), dx(d);
		bool f(true);
		rep(j, 0, M) {
			if (c<=a[j]&&b[j]<=d||
				a[j]<=c&&d<=b[j]||
				a[j]<=c&&c<=b[j]||
				a[j]<=d&&d<=b[j]
				)f = false;
		}
		dump(f);
		if (f) {
			cout << "OK" << endl;
			a.push_back(c); b.push_back(d); M++;
		}
		else cout << "NG" << endl;
	}

	return 0;
}