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

//bitset<5010> left_field[5010], right_field[5010];
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, K; cin >> N >> K;
	vector<int>a(N); rep(i, 0, N)cin >> a[i];
	sort(all(a));
	int ans;

	//left_field[0][0] = right_field[0][0] = 1;
	//rep(i, 1, N + 1) {
	//	left_field[i] = left_field[i - 1];
	//	if (a[i] >= K)continue;
	//	rrep(j, 0, K - a[i]) {
	//		if (left_field[i][j]) {
	//			left_field[i][j + a[i]] = 1;
	//		}
	//	}
	//}
	//rep(i, 1, N + 1) {
	//	right_field[i] = right_field[i - 1];
	//	if (a[N + 1 - i] >= K)continue;
	//	rrep(j, 0, K - a[i]) {
	//		if (right_field[i][j]) {
	//			right_field[i][j + a[i]] = 1;
	//		}
	//	}
	//}

	//rep(i, 1, N + 1) {
	//	if (a[i] >= K) {
	//		ans--;
	//		continue;
	//	}
	//	// left_field[i-1]  right_field[N-i]
	//	rep(j, 0, K - a[i]) {
	//		// left_field[i-1][j] right_field[N-i][K-a[i]-j]
	//		bool f(false);
	//		rep(k, K - a[i] - j, K - j) {
	//			if (left_field[i - 1][j] && right_field[N - i][K - a[i] - j]) {
	//				f = true;
	//				break;
	//			}
	//		}
	//		if (f) {
	//			ans--;
	//			break;
	//		}
	//	}
	//}

	bool f[5010];
	int l(-1), r(N);
	while (r - l > 1) {
		int mid = (l + r) / 2;
		rep(i, 0, 5010)f[i] = 0;
		f[0] = true;
		if (a[mid] >= K) {
			r = mid;
			continue;
		}
		rep(j, 0, N) {
			if (mid == j)continue;
			rrep(k, a[j], K + 10) {
				f[k] = f[k - a[j]] || f[k];
			}
		}
		bool g(false);
		rep(k, K - a[mid], K)g = f[k] || g;

		if (g) r = mid;
		else l = mid;


		//rep(i, 0, K + 100)cout << i << (i == K + 100 - 1 ? '\n' : ' ');
		//rep(i, 0, K + 100)cout << f[i] << (i == K + 100 - 1 ? '\n' : ' ');
	}
	dump(l, r);
	cout << l+1  << endl;

	return 0;
}