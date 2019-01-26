#include "bits/stdc++.h"

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define ll long long
#define ll1 1ll
#define ONE 1ll
#define DBG 1
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define loop(n) rep(loop, (0), (n))
#define all(c) begin(c), end(c)
const int INF =
sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
using pii = pair<int, int>;
// template<class T> ostream &operator<<(ostream &os,T &t){dump(t);return os;}
template <typename T, typename S>
istream &operator>>(istream &is, pair<T, S> &p) {
	is >> p.first >> p.second;
	return is;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, pair<T, S> &p) {
	os << p.first << " " << p.second;
	return os;
}

template <typename T> void printvv(const vector<vector<T>> &v) {
	cerr << endl;
	rep(i, 0, v.size()) rep(j, 0, v[i].size()) {
		if (typeid(v[i][j]).name() == typeid(INF).name() and v[i][j] == INF) {
			cerr << "INF";
		}
		else
			cerr << v[i][j];
		cerr << (j == v[i].size() - 1 ? '\n' : ' ');
	}
	cerr << endl;
}
/*
typedef __int128_t Int;
std::ostream &operator<<(std::ostream &dest, __int128_t value) {
std::ostream::sentry s(dest);
  if (s) {
	__uint128_t tmp = value < 0 ? -value : value;
	char buffer[128];
	char *d = std::end(buffer);
	do {
	  --d;
	  *d = "0123456789"[tmp % 10];
	  tmp /= 10;
	} while (tmp != 0);
	if (value < 0) {
	  --d;
	  *d = '-';
	}
	int len = std::end(buffer) - d;
	if (dest.rdbuf()->sputn(d, len) != len) {
	  dest.setstate(std::ios_base::badbit);
	}
  }
  return dest;
}

__int128 parse(string &s) {
  __int128 ret = 0;
  for (int i = 0; i < s.length(); i++)
	if ('0' <= s[i] && s[i] <= '9')
	  ret = 10 * ret + s[i] - '0';
  return ret;
}
*/

#ifndef _DEBUG
#define printvv(...)
#endif
void YES(bool f) { cout << (f ? "YES" : "NO") << endl; }
void Yes(bool f) { cout << (f ? "Yes" : "No") << endl; }
template <class T> bool chmax(T &a, const T &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
template <class T> bool chmin(T &a, const T &b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template< typename Monoid >
struct SegmentTree {
	using F = function< Monoid(Monoid, Monoid) >;

	int sz;
	vector< Monoid > seg;

	const F f;
	const Monoid e;

	SegmentTree(int n, const F f, const Monoid &e) : f(f), e(e) {
		sz = 1;
		while (sz < n) sz <<= 1;
		seg.assign(2 * sz, e);
	}
	// k:=[0,sz)
	void set(int k, const Monoid &x) {
		seg[k + sz] = x;
	}

	void build() {
		for (int k = sz - 1; k > 0; k--) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}
	// k:=[0,sz)
	void update(int k, const Monoid &x) {
		k += sz;
		seg[k] = x;
		while (k >>= 1) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}
	// [a,b)
	Monoid query(int a, int b) {
		Monoid L = e, R = e;
		for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if (a & 1) L = f(L, seg[a++]);
			if (b & 1) R = f(seg[--b], R);
		}
		return f(L, R);
	}
	// k:=[0,sz)
	Monoid operator[](const int &k) const {
		return seg[k + sz];
	}
};
struct DisjointSet {
	// ２つのグループを１つにまとめる　と　2つの要素が同じグループに所属しているかどうかを判定する
	vector<int> rank, p, S; // p->parent  S[findSet(v)] ->連結成分の大きさ
	DisjointSet() {}
	DisjointSet(int size) {
		S.resize(size, 1);
		rank.resize(size, 0);
		p.resize(size, 0);
		rep(i, 0, size) makeSet(i);
	}
	void makeSet(int x) {
		p[x] = x;
		rank[x] = 0;
	}
	bool same(int x, int y) { // 判定する
		return findSet(x) == findSet(y);
	}
	void unite(int x, int y) { // 連結するときにはこれを使う
		if (same(x, y))
			return;
		link(findSet(x), findSet(y));
	}
	void link(int x, int y) {
		if (rank[x] > rank[y]) {
			p[y] = x;
		}
		else {
			p[x] = y;
			if (rank[x] == rank[y]) {
				rank[y]++;
			}
		}

		S[x] = S[y] = S[x] + S[y];
	}
	int findSet(int x) {
		if (x != p[x]) {
			p[x] = findSet(p[x]); // path compression
		}
		return p[x];
	}
	int connectedComponentSize(int x) { return S[findSet(x)]; }
};

struct Edge {
	int source, target, cost;
	Edge(int source = 0, int target = 0, int cost = 0)
		: source(source), target(target), cost(cost) {};

	bool operator<(const Edge &e) const { return cost < e.cost; }
};

int kruskal(int N, vector<Edge> &edges) {
	int totalCost = 0;
	sort(all(edges));
	DisjointSet dset(N);
	rep(i, 0, edges.size()) {
		Edge e = edges[i];
		if (!dset.same(e.source, e.target)) {
			// MST.push_back(e);
			totalCost += e.cost;
			dset.unite(e.source, e.target);
		}
	}
	return totalCost;
}

signed main(signed argc, char *argv[]) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(12);

	int N, D; cin >> N >> D;
	vector<int>A(N); rep(i, 0, N) { cin >> A[i]; }
	vector<pii>B(N); rep(i, 0, N) { B[i] = pii(A[i], i); }
	sort(all(B));
	SegmentTree<pii> segL(N, [](pii x, pii y) {return min(x, y); }, pii(INF, INF));
	SegmentTree<pii> segR(N, [](pii x, pii y) {return min(x, y); }, pii(INF, INF));
	vector<Edge>edges;
	rep(i, 0, N) {
		pii p = B[i];
		if (i > 0) {
			int x = segL.query(0, p.second).second;
			int y = segR.query(p.second, N).second;
			if (x != INF) {
				edges.eb(p.second, x, A[p.second] + A[x] + (p.second - x)*D);
			}
			if (y != INF) {
				edges.eb(p.second, y, A[p.second] + A[y] + (y - p.second)*D);
			}
		}
		segL.update(p.second, pii(A[p.second] - p.second * D,p.second));
		segR.update(p.second, pii(A[p.second] + p.second * D,p.second));
	}
	cout << kruskal(N, edges) << endl;
	
	return 0;
}
