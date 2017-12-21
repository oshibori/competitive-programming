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
struct Item {
	int v, w;
	Item() :v(0), w(0) {}
	Item(int v, int w) :v(v), w(w) {}
	Item &operator+=(const Item &p) {
		v += p.v;
		w += p.w;
		return *this;
	}
	Item operator+(const Item &p) {
		return Item(this->v + p.v, this->w + p.w);
	}
	bool operator<(const Item &p)const {
		return (w == p.w) ? (v < p.v) : (w < p.w);
	}
	bool operator>(const Item &p)const {
		return (w == p.w) ? (v > p.v) : (w > p.w);
	}
};
istream &operator >> (istream &is, Item &p) {
	is >> p.v >> p.w;
	return is;
}
ostream &operator<<(ostream &os, Item &p) {
	os << p.v << " " << p.w;
	return os;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, W; cin >> N >> W;
	vector<Item>items(N);
	rep(i, 0, N)cin >> items[i];
	vector<Item>a, b;
	int n1 = N / 2, n2 = N - n1;
	rep(i, 0, 1 << n1) {
		Item x;
		rep(j, 0, n1)if (i & (1 << j))x += items[j];
		a.push_back(x);
	}
	rep(i, 0, 1 << n2) {
		Item x;
		rep(j, 0, n2)if (i & (1 << j))x += items[n1 + j];
		b.push_back(x);
	}
	sort(all(b));
	rep(i, 0, b.size())cout << b[i] << ",";
	int m(1);
	rep(i, 1, b.size()) {
		if (b[m - 1].v < b[i].v)b[m++] = b[i];
	}
	//rep(i, 1, b.size())chmax(b[i], b[i - 1]);
	
	int ans(0);
	rep(i, 0, a.size()) {
		if (a[i].w > W)continue;
		//chmax(ans, a[i].v + (upper_bound(all(b), Item(INF, W - a[i].w))-1)->v);
		int l(0), r(m);
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (b[mid].w + a[i].w <= W)l = mid;
			else r = mid;
		}
		chmax(ans, b[l].v + a[i].v);
	}
	cout << ans << endl;
	return 0;
}