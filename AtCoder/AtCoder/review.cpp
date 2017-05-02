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
template<typename T>
struct BinaryIndexedTree {
	int n;
	vector<int>d;
	BinaryIndexedTree(int m) :n(m) {
		d.assign(n + 1, 0);
	}
	void add(int i, T x) {
		for (int j = i; j <= n; j += j&(-j))d[j] += x;
	}
	T sum(int i) {
		T ret(0);
		for (int j = i; j > 0; j -= j&(-j))ret += d[j];
		return ret;
	}
	T sum(int s, int t) {
		return sum(t) - sum(s - 1);
	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, q; cin >> n >> q;
	BinaryIndexedTree<int> bit(n);
	rep(i, 0, q) {
		int com, x, y; cin >> com >> x >> y;
		if (com)cout << bit.sum(x, y) << endl;
		else bit.add(x, y);
	}
	return 0;
}