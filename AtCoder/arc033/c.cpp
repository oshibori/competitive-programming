#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
typedef __int128_t Int;
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
#define eb emplace_back
using pii = pair<int, int>;
// template<class T> ostream &operator<<(ostream &os,T &t){dump(t);return os;}
template <typename T, typename S>
istream &operator>>(istream &is, pair<T, S> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T> void printvv(const vector<vector<T>> &v) {
  cerr << endl;
  rep(i, 0, v.size()) rep(j, 0, v[i].size()) {
    if (typeid(v[i][j]) == typeid(INF) and v[i][j] == INF) {
      cerr << "INF";
    } else
      cerr << v[i][j];
    cerr << (j == v[i].size() - 1 ? '\n' : ' ');
  }
  cerr << endl;
}

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
template <typename T> struct RangeSumQuery {
  // SegmentTree (1-indexed)
  int n;
  vector<T> d;
  RangeSumQuery(int m) {
    for (n = 1; n < m; n <<= 1)
      ;
    d.assign(2 * n, 0);
  }
  RangeSumQuery(vector<T> &v) {
    for (n = 1; n < v.size(); n <<= 1)
      ;
    d.assign(2 * n, 0);
    for (int i = 0; i < v.size(); i++)
      d[n + i] = v[i];
    for (int i = d.size() - 1; i > 0; i--) {
      d[i / 2] += d[i];
    }
  }
  void add(int i, T x) {
    d[n + i] += x;
    for (int j = (n + i) / 2; j > 0; j >>= 1) {
      d[j] += x;
    }
  }
  T sum(int a, int b) { return sum(a, b, 1, 0, n); }
  T sum(int a, int b, int k, int l, int r) {
    // [a,b) [l,r)
    if (r <= a || b <= l)
      return 0;
    else if (a <= l && r <= b)
      return d[k];
    else {
      T vl, vr;
      vl = sum(a, b, k * 2, l, (l + r) / 2);
      vr = sum(a, b, k * 2 + 1, (l + r) / 2, r);
      return (vl + vr);
    }
  }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int Q;
  cin >> Q;
  RangeSumQuery<int>rsq(200001);
  rep(i,0,Q){
    int t, x; cin >> t >> x;
    if(t==1){
      rsq.add(x,1);
    }
    else{
      int l=0,r=200001;
      while(r-l>1){
        int m=(l+r)/2;
        int sum=rsq.sum(0,m+1);
        dump(m,sum);
        if(sum>=x){r=m;}
        else l=m;
      }
      cout<<r<<endl;

      rsq.add(r,-1);

    }
  }

  return 0;
}
