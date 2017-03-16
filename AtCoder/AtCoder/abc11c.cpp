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

	int N; cin >> N;
	vector<int>NG(3); rep(i, 0, 3)cin >> NG[i];

	int M(N);
	int n1, n2, n3;

	n3 = N / 3; N -= n3 * 3;
	n2 = N / 2; N -= n2 * 2;
	n1 = N / 1; N -= n1 * 1;

	int cnt(100);

	if (find(all(NG), M) != NG.end()) {
		cout << "NO" << endl;
		goto here;
	}

	while (M > 0) {
		if (find(all(NG), M - 3) == NG.end() && cnt)M -= 3, cnt--;
		else if (find(all(NG), M - 2) == NG.end() && cnt)M -= 2, cnt--;
		else if (find(all(NG), M - 1) == NG.end() && cnt)M -= 1, cnt--;
		else {
			cout << "NO" << endl;
			goto here;
		}
	}
	cout << "YES" << endl;
here:;

	return 0;
}