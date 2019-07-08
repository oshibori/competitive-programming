#include "bits/stdc++.h"
using namespace std;

//https://atcoder.jp/contests/cf17-tournament-round1-open/submissions/2859012

//https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
template< typename Monoid >
struct SegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;
 
  int sz;
  vector< Monoid > seg;
 
  const F f;
  const Monoid e;
 
  SegmentTree(int n, const F f, const Monoid &e) : f(f), e(e) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, e);
  }
  // k:=[0,sz)
  void set(int k, const Monoid &x) {
    seg[k + sz] = x;
  }
 
  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
  // k:=[0,sz)
  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
  // [a,b)
  Monoid query(int a, int b) {
    Monoid L = e, R = e;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }
  // k:=[0,sz)
  const Monoid &operator[](const int &k) const {
    return seg[k + sz];
  }
	Monoid &operator[](const int &k){
    return seg[k + sz];
  }
};




struct RangeMinimumQuery {
	// 1-indexed
	int n;
	vector<int> d;
	RangeMinimumQuery(int m) {
		for (n = 1; n < m; n *= 2);
		d.assign(n * 2, INF);
	}
	void update(int i, int x) {
		d[n + i] = x;
		for (int j = (n + i) / 2; j > 0; j >>= 1)
			d[j] = min(d[j * 2], d[j * 2 + 1]);
	}
	//[l, r)
	int query(int l, int r) {
		int mi = get(l);
		for (; l && l + (l&-l) <= r; l += l&-l)
			mi = min(mi, d[(n + l) / (l&-l)]);
		for (; l < r; r -= r&-r)
			mi = min(mi, d[(n + r) / (r&-r) - 1]);
		return mi;
	}
	int get(int i) { return d[n + i]; }
};

struct RangeSumQuery {
	int n;
	vector<int> d;
	RangeSumQuery(int m) {
		for (n = 1; n < m; n *= 2);
		d.assign(n * 2, 0);
	}
	void add(int i, int x) {
		d[n + i] += x;
		for (int j = (n + i) / 2; j > 0; j >>= 1)
			d[j] = d[j * 2] + d[j * 2 + 1];
	}
	//[l, r)
	int query(int l, int r) {
		int sum = 0;
		for (; l && l + (l&-l) <= r; l += l&-l)
			sum += d[(n + l) / (l&-l)];
		for (; l < r; r -= r&-r)
			sum += d[(n + r) / (r&-r) - 1];
		return sum;
	}
	int get(int i) { return d[n + i]; }
};

//Å“K‚©•s–¾
struct RangeUpdateQuery {
	int n;
	vector<int> d;
	vector<int> timestamp;
	int time;
	RangeUpdateQuery(int m) {
		for (n = 1; n < m; n *= 2);
		d.assign(n * 2, INF);
		time = 0;
		timestamp.assign(n * 2, 0);
	}
	//[l, r)
	void update(int l, int r, int x) {
		time++;
		for (; l && l + (l&-l) <= r; l += l&-l) {
			d[(n + l) / (l&-l)] = x;
			timestamp[(n + l) / (l&-l)] = time;
		}
		for (; l < r; r -= r&-r) {
			d[(n + r) / (r&-r) - 1] = x;
			timestamp[(n + r) / (r&-r) - 1] = time;
		}
	}
	int get(int i) {
		int ret = d[n + i];
		int max_time = timestamp[n + i];
		for (int j = (n + i) / 2; j > 0; j >>= 1) {
			if (max_time > timestamp[j])continue;
			max_time = timestamp[j];
			ret = d[j];
		}
		return ret;
	}
};

//Å“K‚©•s–¾
struct RangeAddQuery {
	int n;
	vector<int> d;
	int time;
	RangeAddQuery(int m) {
		for (n = 1; n < m; n *= 2);
		d.assign(n * 2, 0);
	}
	//[l, r)
	void add(int l, int r, int x) {
		for (; l && l + (l&-l) <= r; l += l&-l)
			d[(n + l) / (l&-l)] += x;
		for (; l < r; r -= r&-r)
			d[(n + r) / (r&-r) - 1] += x;
	}
	int get(int i) {
		int ret = d[n + i];
		for (int j = (n + i) / 2; j > 0; j >>= 1)
			ret += d[j];
		return ret;
	}
};