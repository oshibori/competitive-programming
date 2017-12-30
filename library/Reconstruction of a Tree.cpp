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
vector<int>pre, in, post;
int n, pos;
void rec(int l, int r) {
	if (!(l < r))return;
	int root = pre[pos++];
	int m = distance(in.begin(), find(in.begin(), in.end(), root));
	rec(l, m);
	rec(m + 1, r);
	post.push_back(root);
}
void solve() {
	pos = 0;
	rec(0, pre.size());
	for (int i = 0; i < n; i++) {
		if (i)cout << " ";
		cout << post[i];
	}
	cout << endl;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, 0, n) {
		int x; cin >> x;
		pre.push_back(x);
	}
	rep(i, 0, n) {
		int x; cin >> x;
		in.push_back(x);
	}
	solve();
	return 0;
}