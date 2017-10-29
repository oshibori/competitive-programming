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
	string T, P; cin >> T >> P;
	int index(0);
	set<int>f, b;

	for (int i = 0; i < T.size() && index < P.size(); i++) {
		if (T[i] == P[index]) {
			f.insert(i);
			index++;
		}
	}
	bool h(index == P.size());

	index = P.size() - 1;
	for (int i = T.size() - 1; i >= 0 && index >= 0; i--) {
		if (T[i] == P[index]) {
			b.insert(i);
			index--;
		}
	}
	bool g(index == -1);
	if (h&&g&&b == f)cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}