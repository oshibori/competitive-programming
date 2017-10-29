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
	int N; cin >> N;
	vector<int> a(N); rep(i, 0, N) { cin >> a[i]; }
	int index = 0;
	int up = 0;
	while (index < N) {
		int k = 1;
		while (index + k + 1 < N&&a[index + k] < a[index + k + 1])k++;
		chmax(up, k);
		index += k;
	}
	dump(up);
	int down = 0;
	index = 0;
	while (index < N) {
		int k = 1;
		while (index + k + 1 < N&&a[index + k] > a[index + k + 1])k++;
		chmax(down, k);
		index += k;
	}
	dump(down);
	cout << max(up, down) << endl;

	//set<int>s;
	//s.insert(-1);
	//s.insert(INF);
	//int ans(1);
	//pair<int, int>cnt;
	//rep(i, 0, N - 1) {
	//	auto x = s.insert(a[i]);
	//	auto l = x.first, r = x.first;
	//	l--;
	//	r++;
	//	dump(*l, *x.first, *r);
	//	cnt.first = *l == -1;
	//	cnt.second = *r == INF;

	//	if (a[i] > a[i + 1] && cnt.first||a[i] < a[i + 1] && cnt.second)ans++;
	//	dump(ans);

	//}
	//cout << ans << endl;
	return 0;
}