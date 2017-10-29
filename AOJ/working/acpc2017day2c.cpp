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
	int N, L; cin >> N >> L;
	vector<string>v(N);
	rep(i, 0, N) {
		cin >> v[i];
	}
	vector<string>ans;
	vector<int>used(N, 0);
	rep(i, 0, N)rep(j, i + 1, N) {
		if (used[i] || used[j])continue;
		auto x = v[i];
		auto y = v[j];
		reverse(all(x));
		if (x == y) {
			if (v[i] < v[j])ans.push_back(v[i]);
			else ans.push_back(v[j]);
			used[i] = used[j] = 1;
		}

	}
	sort(all(ans));
	vector<string>center;
	rep(i, 0, N) {
		if (used[i])continue;
		auto x = v[i];
		reverse(all(x));
		if (v[i] == x) {
			center.push_back(v[i]);
		}
	}
	sort(all(center));
	string re;
	rep(i, 0, ans.size()) {
		re += ans[i];
	}
	if (center.size())re += center[0];
	rrep(i, 0, ans.size()) {
		auto x = ans[i];
		reverse(all(x));
		re += x;
	}
	cout << re << endl;
	return 0;
}