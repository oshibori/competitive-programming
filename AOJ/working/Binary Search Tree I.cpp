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
struct BinarySearchTree {
	struct Node {
		T key;
		Node *l, *r, *p;
		Node() {}
		Node(T key) :key(key) {}
		Node(T key, Node *l, Node *r) :key(key), l(l), r(r) {}
		bool operator<(Node &other) {
			return key < other.key;
		}
		bool operator>(Node &other) {
			return key > other.key;
		}
	};
	Node *root = nullptr, *NIL = nullptr;
	void insert(T key) {
		Node *x = root, *y = NIL;
		while (x != NIL) {
			y = x;
			if (key < x->key)x = x->l;
			else x = x->r;
		}
		dump(y);
		Node *z = (Node*)malloc(sizeof(Node));
		z->l = z->r = NIL;
		z->key = key;
		z->p = y;
		if (y == NIL)root = z;
		else {
			if (key < y->key)y->l = z;
			else y->r = z;
		}
	}
	void inorder() {
		inorder(root);
		puts("");
	}
	void inorder(Node *u) {
		if (u == NIL)return;
		inorder(u->l);
		printf(" %d", u->key);
		inorder(u->r);
	}
	void preorder() {
		preorder(root);
		puts("");
	}
	void preorder(Node *u) {
		if (u == NIL)return;
		printf(" %d", u->key);
		preorder(u->l);
		preorder(u->r);
	}
};
signed main() {
	int n; scanf("%d", &n);
	BinarySearchTree<int>bst;
	rep(i, 0, n) {
		string com;
		cin >> com;
		if (com == "insert") {
			int x; scanf("%d", &x);
			bst.insert(x);
		}
		else if (com == "print") {
			bst.inorder();
			bst.preorder();
		}
	}
	return 0;
}