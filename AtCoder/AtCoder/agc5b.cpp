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

int allmin(vector<int>&v, int l, int r) {
	// [l,r)
	if (!(l < r))return 0;

	int x = distance(v.begin(), min_element(v.begin() + l, v.begin() + r));

	return (x - l + 1)*(r - x)*v[x] + allmin(v, l, x) + allmin(v, x + 1, r);
}


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<int> v(N), pos(N); rep(i, 0, N) {
		cin >> v[i];
		v[i]--;
		pos[v[i]] = i;
	}
	int ans(0);
	set<int>s;
	s.insert(-1);
	s.insert(N);
	rep(i, 0, N) {
		auto x = s.insert(pos[i]);
		set<int>::iterator l, r;
		l = r = x.first;
		l--, r++;

		ans += (i + 1)*(pos[i] - *l)*(*r - pos[i]);
	}
	cout << ans << endl;

	return 0;
}