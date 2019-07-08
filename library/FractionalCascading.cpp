#include "bits/stdc++.h"
//https://ei1333.hateblo.jp/entry/2017/12/14/000000
//領域内の点の個数を数えるO(log n)
using namespace std;
struct SegmentTreeFractionalCascading
{
  vector< vector< int > > seg;
  vector< vector< int > > L, R;
  int sz;

  SegmentTreeFractionalCascading(vector< vector< int > > &array)
  {
    sz = 1;
    while(sz < array.size()) sz <<= 1;
    seg.resize(2 * sz - 1);
    L.resize(2 * sz - 1);
    R.resize(2 * sz - 1);
    for(int k = 0; k < array.size(); k++) {
      seg[k + sz - 1] = array[k];
      sort(begin(seg[k + sz - 1]), end(seg[k + sz - 1]));
    }
    for(int k = sz - 2; k >= 0; k--) {
      seg[k].resize(seg[2 * k + 1].size() + seg[2 * k + 2].size());
      L[k].resize(seg[k].size() + 1);
      R[k].resize(seg[k].size() + 1);
      merge(begin(seg[2 * k + 1]), end(seg[2 * k + 1]), begin(seg[2 * k + 2]), end(seg[2 * k + 2]), begin(seg[k]));
      int tail1 = 0, tail2 = 0;
      for(int i = 0; i < seg[k].size(); i++) {
        L[k][i] = tail1, R[k][i] = tail2;
        if(tail1 < seg[2 * k + 1].size() && seg[2 * k + 1][tail1] == seg[k][i]) {
          ++tail1;
        } else {
          ++tail2;
        }
      }
      L[k][seg[k].size()] = (int) seg[2 * k + 1].size();
      R[k][seg[k].size()] = (int) seg[2 * k + 2].size();
    }
  }

  int query(int a, int b, int lower, int upper, int k, int l, int r)
  {
    if(r <= a || b <= l) {
      return (0);
    } else if(a <= l && r <= b) {
      return (upper - lower);
    } else {
      return (query(a, b, L[k][lower], L[k][upper], 2 * k + 1, l, (l + r) >> 1) + query(a, b, R[k][lower], R[k][upper], 2 * k + 2, (l + r) >> 1, r));
    }
  }

  int query(int a, int b, int l, int r)
  {
    l = lower_bound(begin(seg[0]), end(seg[0]), l) - begin(seg[0]);
    r = lower_bound(begin(seg[0]), end(seg[0]), r) - begin(seg[0]);
    return (query(a, b, l, r, 0, 0, sz));
  }
};