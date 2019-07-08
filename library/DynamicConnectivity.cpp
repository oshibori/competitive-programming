#include "bits/stdc++.h"
//http://codeforces.com/gym/100551
//https://ei1333.hateblo.jp/entry/2017/12/14/000000
using edge = pair< int, int >;

struct UnionFind
{
  vector< int > data;
  stack< pair< int, int > > st;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  bool unite(int x, int y)
  {
    x = find(x), y = find(y);
    st.emplace(x, data[x]);
    st.emplace(y, data[y]);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k)
  {
    if(data[k] < 0) return (k);
    return (find(data[k]));
  }

  int size(int k)
  {
    return (-data[find(k)]);
  }

  void undo()
  {
    data[st.top().first] = st.top().second;
    st.pop();
    data[st.top().first] = st.top().second;
    st.pop();
  }
};


struct Dynamic_connectivity
{
  UnionFind uf;
  int n, sz;
  vector< vector< edge > > edges;

  vector< pair< pair< int, int >, edge > > pending;
  map< edge, int > cnt, appear;

  Dynamic_connectivity(int n, int q) : n(q), uf(n) // (2018-03-21修正)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    edges.resize(2 * sz - 1);
  }

  void insert(int idx, edge e)
  {
    if(e.first > e.second) swap(e.first, e.second);
    if(cnt[e]++ == 0) appear[e] = idx;
  }

  void erase(int idx, edge e)
  {
    if(e.first > e.second) swap(e.first, e.second);
    if(--cnt[e] == 0) pending.emplace_back(make_pair(appear[e], idx), e);
  }

  void add(int a, int b, const edge &e, int k, int l, int r)
  {
    if(r <= a || b <= l) return;
    if(a <= l && r <= b) {
      edges[k].emplace_back(e);
      return;
    }
    add(a, b, e, 2 * k + 1, l, (l + r) >> 1);
    add(a, b, e, 2 * k + 2, (l + r) >> 1, r);
  }

  void add(int a, int b, const edge &e)
  {
    add(a, b, e, 0, 0, sz);
  }

  void build()
  {
    for(auto &p : cnt) {
      if(p.second > 0) pending.emplace_back(make_pair(appear[p.first], sz), p.first);
    }
    for(auto &s : pending) {
      add(s.first.first, s.first.second, s.second);
    }
  }

  void execute(const function< void(int) > &f, int k = 0)
  {
    for(auto &e : edges[k]) {
      int a, b;
      tie(a, b) = e;
      uf.unite(a, b);
    }
    if(k < sz - 1) {
      execute(f, 2 * k + 1);
      execute(f, 2 * k + 2);
    } else if(k - (sz - 1) < n) {
      int query_index = k - (sz - 1);
      f(query_index);
    }
    for(auto &e : edges[k]) {
      uf.undo();
    }
  }
};