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

	int R, C, K; cin >> R >> C >> K;
	int N; cin >> N;
	vector<int>nr(R, 0), nc(C, 0), r, c;
	rep(i, 0, N) {
		int a, b; cin >> a >> b;
		b--, a--;
		r.emplace_back(a); c.emplace_back(b);
		nr[a]++; nc[b]++;
	}
	//vector<int>t((int)(1e5) + 10, 0);
	int t[100100]; memset(t, 0, sizeof(t));
	//vector<int>y(t);
	int y[100100]; memset(y, 0, sizeof(y));

	rep(i, 0, R)t[nr[i]]++;
	rep(i, 0, C)y[nc[i]]++;
	long long ans(0);

	rep(i, 0, K + 1)ans += t[i] * y[K - i];
	rep(i, 0, N) {
		if (nr[r[i]] + nc[c[i]] == K)ans--;
		else if (nr[r[i]] + nc[c[i]] == K + 1)ans++;
	}

	cout << ans << endl;

	return 0;
}