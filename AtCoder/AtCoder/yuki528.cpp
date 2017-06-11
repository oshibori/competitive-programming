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
	string in; cin >> in;
	int mod1((int)(1e9));
	dump(mod1, MOD);
	vector<int>s1(in.size()), s2(in.size());
	s1[0] = s2[0] = 0;
	int x1(1), x2(1);
	rep(i, 1, in.size()) {
		s1[i] = (s1[i - 1] + (9 * x1) % mod1) % mod1;
		s2[i] = (s2[i - 1] + (9 * x2) % MOD) % MOD;
		if (!(i & 1))(x1 *= 10) %= mod1, (x2 *= 10) %= MOD;
		dump(s1[i], s2[i]);

	}
	int a1(1), a2(1);
	for (int i = 0; (in.size() & 1 ? i <= in.size() / 2 : i < in.size() / 2); i++) {
		if (i) {
			(a1 *= 1+min(in[i] - '0', in[in.size() - 1 - i] - '0')) %= mod1;
			(a2 *= 1+min(in[i] - '0', in[in.size() - 1 - i] - '0')) %= MOD;

		}
		else {
			(a1 *= min(in[i] - '0', in[in.size() - 1 - i] - '0')) %= mod1;
			(a2 *= min(in[i] - '0', in[in.size() - 1 - i] - '0')) %= MOD;


		}


	}
	cout << (a1 + s1.back()) % mod1 << endl;
	cout << (a2 + s2.back()) % MOD << endl;
	return 0;
}