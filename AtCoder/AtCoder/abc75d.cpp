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
const int NIL = -1;
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
struct Point {
	int x, y, id;
	Point() {}
	Point(int x, int y, int id = 0) :id(id), x(x), y(y) {}
	bool operator<(const Point &p)const {
		return (x == p.x ? y < p.y : x < p.x);
	}
	void print() { printf("%d\n", id); }
};
bool lessX(const Point &p1, const Point &p2) { return (p1.x == p2.x) ? (p1.y < p2.y) : (p1.x < p2.x); }
bool lessY(const Point &p1, const Point &p2) { return (p1.y == p2.y) ? (p1.x < p2.x) : (p1.y < p2.y); }

struct KDTree {
	// —Ìˆæ’Tõ
	struct Node {
		int index, l, r;
		Node() :index(NIL), l(NIL), r(NIL) {}
	};
	int n, np, root; vector<Point>points; vector<Node>nodes;

	bool inrange(const Point &p, const Point &s, const Point &t) {
		return (s.x <= p.x&&p.x <= t.x) && (s.y <= p.y&&p.y <= t.y);
	}
	KDTree(const vector<Point>ps) :points(ps), n(ps.size()), np(0), nodes(n) {
		root = makeKDTree(0, n, true);
	}
	int makeKDTree(int l, int r, bool is_x_base) {
		if (!(l < r))return NIL;
		int mid = (l + r) / 2;
		int t = np++;
		vector<Point>::iterator first = points.begin() + l,
			nth = points.begin() + mid, last = points.begin() + r;
		if (is_x_base)nth_element(first, nth, last, lessX);
		else nth_element(first, nth, last, lessY);
		nodes[t].index = mid;
		nodes[t].l = makeKDTree(l, mid, !is_x_base);
		nodes[t].r = makeKDTree(mid + 1, r, !is_x_base);
		return t;
	}
	vector<Point>ret;
	vector<Point> find(Point s, Point t) {
		ret.clear();
		return find(s, t, root, true);
	}
	vector<Point> find(Point s, Point t, int v, bool is_x_base = true) {
		auto p = points[nodes[v].index];
		if (inrange(p, s, t))ret.emplace_back(p);
		if (is_x_base) {
			if (nodes[v].l != NIL && s.x <= p.x)find(s, t, nodes[v].l, !is_x_base);
			if (nodes[v].r != NIL && p.x <= t.x)find(s, t, nodes[v].r, !is_x_base);
		}
		else {
			if (nodes[v].l != NIL && s.y <= p.y)find(s, t, nodes[v].l, !is_x_base);
			if (nodes[v].r != NIL && p.y <= t.y)find(s, t, nodes[v].r, !is_x_base);
		}
		return ret;
	}

};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K; cin >> N >> K;
	vector<Point>p;
	vector<int>x, y;
	rep(i, 0, N) {
		int x_, y_; cin >> x_ >> y_;
		x.emplace_back(x_);
		y.emplace_back(y_);
		
		p.emplace_back(Point(x_, y_));
	}
	sort(all(p));
	KDTree tree(p);
	int ans(INF);
	dump(ans);


	rep(i, 0, N)rep(j, i + 1, N)rep(k,0,N)rep(l,k+1,N) {
		int x1 = min(x[i], x[j]);
		int x2 = max(x[i], x[j]);
		int y1 = min(y[k], y[l]);
		int y2 = max(y[k], y[l]);

		auto a1 = Point(x1, y1);
		auto a2 = Point(x2, y2);

		dump(a1.x, a1.y);
		dump(a2.x, a2.y);
		auto x=	tree.find(a1,a2);
		dump(x.size())
		if (x.size() >= K) {
			chmin(ans, abs(x2 - x1)*abs(y2 - y1));
		}
	}
	cout << ans << endl;
	
	return 0;
}