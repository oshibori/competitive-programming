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
vector<bool> eratos_thenes(int N) {
	vector<bool>p(N + 1, true); p[0] = p[1] = false;

	for (int i = 2; i*i <= N; i++)
		if (p[i])
			for (int j = i + i; j < N + 1; j += i)
				p[j] = false;

	return p;
}
bool isPrime(int x) {
	for (int i(2); i*i <= x; i++)if (x%i == 0)return false;
	return true;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	auto f = [&](int x) {
		int ret(0);
		while (x)ret += x % 10, x /= 10;
		return ret;
	};

	int N; cin >> N;

	if (N == 1)cout << "Not Prime" << endl;
	else if (isPrime(N))cout << "Prime" << endl;
	else {
		if (N % 2 != 0 && N % 10 != 5 && f(N) % 3 != 0)cout << "Prime" << endl;
		else cout << "Not Prime" << endl;
	}

	



	return 0;
}