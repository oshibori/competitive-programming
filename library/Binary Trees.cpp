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
const int NIL = -1;
struct Node { int p, l, r; };
const int MAX = 10000;
Node T[MAX];
int n, D[MAX], H[MAX];
void setDepth(int u, int d) {
	if (u == NIL)return;
	D[u] = d;
	setDepth(T[u].l, d + 1);
	setDepth(T[u].r, d + 1);
}
int setHeight(int u) {
	int h1(0), h2(0);
	if (T[u].l != NIL)h1 = setHeight(T[u].l) + 1;
	if (T[u].r != NIL)h2 = setHeight(T[u].r) + 1;
	return H[u] = max(h1, h2);
}
int getSibling(int u) {
	if (T[u].p == NIL)return NIL;
	if (T[T[u].p].l != u && T[T[u].p].l != NIL)return T[T[u].p].l;
	if (T[T[u].p].r != u && T[T[u].p].r != NIL)return T[T[u].p].r;
	return NIL;
}
void print(int u) {
	printf("node %d: ", u);
	printf("parent = %d, ", T[u].p);
	printf("sibling = %d, ", getSibling(u));
	int deg = 0;
	if (T[u].l != NIL)deg++;
	if (T[u].r != NIL)deg++;
	printf("degree = %d, ", deg);
	printf("depth = %d, ", D[u]);
	printf("height = %d, ", H[u]);
	if (T[u].p == NIL)printf("root\n");
	else if (T[u].l == NIL&&T[u].r == NIL)printf("leaf\n");
	else printf("internal node\n");
}
signed main() {
	int v, l, r, root = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)T[i].p = NIL;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &v, &l, &r);
		T[v].l = l;
		T[v].r = r;
		if (l != NIL)T[l].p = v;
		if (r != NIL)T[r].p = v;
	}
	for (int i = 0; i < n; i++)if (T[i].p == NIL)root = i;
	setDepth(root, 0);
	setHeight(root);
	for (int i = 0; i < n; i++)print(i);
	return 0;
}