//#include <bits/stdc++.h>
// utility
#include <bitset>
#include <tuple>
#include <typeinfo>
// error handling
#include <cassert>
// string
#include <cctype>
#include <cstring>
#include <string>
// container
#include <array>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// algorithm
#include <algorithm>
// iterator
#include <iterator>
// math
#include <cmath>
#include <complex>
#include <numeric>
#include <random>
// i/o
#include <cstdio>
#include <iomanip>
#include <iostream>

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
template <typename T> struct BinaryIndexedTree {
  // 内部では1-indexed
  int n;
  vector<T> d;
  // d[x] が管理する区間の長さは，x の最も下の立っているビット(x&-x)
  BinaryIndexedTree(int m) : n(m) {
    // 0 以外の値で初期化をするとき
    // ・add を 𝑁 回呼び出せば 𝑂(𝑁 log 𝑁)
    // ・𝑣𝑥 = 1 で初期化するなら bit[x] = x & -x; (x&-x は区間の長さ)
    // ・一般には bit[x] を 𝑣𝑥 で初期化したのち
    //   for (int x = 1; x < N; ++x) bit[x + (x & -x)] += bit[x];
    d.assign(m + 1, 0);
  }
  T sum(int a, int b) { return sum(b) - sum(a - 1); }
  T sum(int i) {
    // iから0にiの最も下の立っているbitを使って到達する最短距離
    // 次に足すべき区間は，番号から区間の長さを引くと求まる
    i++;
    T ret(0);
    for (int j = i; j > 0; j -= j & (-j))
      ret += d[j];
    return ret;
  }
  void add(int i, T x) {
    // iからnにiの最も下の立っているbitを使って到達する最短距離
    // 次に更新すべき区間は，番号に区間の長さを足すと求まる
    i++;
    for (int j = i; j <= n; j += j & (-j))
      d[j] += x;
  }
  int lower_bound(T w) {
    // 二分木の分かれ方に従って二分探索する
    // 左の子に進むか右の子に進むかを知るためには，左の子の範囲の和がわかればよい
    // (index/2)
    // ちょうど BIT がもっている情報，𝑂(1) 時間で得られる
    //
    if (w <= 0)
      return 0;
    int x(0), y;
    for (y = 1; 2 * y <= n; y <<= 1)
      ;
    for (int k = y; k > 0; k >>= 1) {
      if (x + k <= n && d[x + k] < w) {
        w -= d[x + k];
        x += k;
      }
    }
    return x + 1;
  }
};

template <typename T> vector<T> compress(vector<T> &a) {
  // 座標圧縮
  vector<T> ret;
  ret.insert(ret.end(), all(a));
  sort(all(ret));
  ret.erase(unique(all(ret)), ret.end());
  rep(i, 0, a.size()) a[i] = distance(ret.begin(), lower_bound(all(ret), a[i]));
  return ret;
}

int theNunberOfInversion(vector<int> &a) {
  compress(a);
  BinaryIndexedTree<int> bit(a.size());

  int ans(0);
  rep(i, 0, a.size()) {
    ans += bit.sum(a[i]);
    bit.add(a[i], 1);
  }
  return ans;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  vector<int> v(N);
  rep(i, 0, N) { cin >> v[i]; }
  int l = 0, r = *max_element(all(v)) + 1;
  auto f = [&](int m) {
    vector<int> a(N + 1);
    rep(i, 1, N + 1) a[i] = (v[i - 1] >= m ? 1 : -1) + a[i - 1];
    int x = theNunberOfInversion(a);
    int len = (N + 1) * N / 2;
    return x >= (len + 1) / 2;
  };
  while (r - l > 1) {
    int m = (r + l) / 2;
    dump(m);
    if (f(m))
      l = m;
    else
      r = m;
  }
  cout << l << endl;

  return 0;
}
