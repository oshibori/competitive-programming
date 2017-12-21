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
struct Node { int p, l, r; };
const int MAX = 100005;
const int NIL = -1;
Node T[MAX];
int n, D[MAX];
void print(int u) {
	int i, c;
	cout << "node " << u << ": ";
	cout << "parent = " << T[u].p << ", ";
	cout << "depth = " << D[u] << ", ";
	if (T[u].p == NIL)cout << "root, ";
	else if (T[u].l == NIL)cout << "leaf, ";
	else cout << "internal node, ";
	cout << "[";
	for (i = 0, c = T[u].l; c != NIL; i++, c = T[c].r) {
		if (i)cout << ", ";
		cout << c;
	}
	cout << "]" << endl;
}
void rec(int u, int p) {
	D[u] = p;
	if (T[u].r != NIL)rec(T[u].r, p);
	if (T[u].l != NIL)rec(T[u].l, p + 1);
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int i, j, d, v, c, l, r;
	cin >> n;
	for (i = 0; i < n; i++)T[i].p = T[i].l = T[i].r = NIL;
	for (i = 0; i < n; i++) {
		cin >> v >> d;
		for (j = 0; j < d; j++) {
			cin >> c;
			if (j == 0)T[v].l = c;
			else T[l].r = c;
			l = c;
			T[c].p = v;
		}
	}
	for (i = 0; i < n; i++) {
		if (T[i].p == NIL)r = i;
	}
	rec(r, 0);
	for (i = 0; i < n; i++)print(i);
	return 0;
}