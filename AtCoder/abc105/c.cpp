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

#define int long long
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
int f(int x) {
  int ret = 0, i = 0;
  int base = 1;
  while (x) {
    if (x & 1) {
      ret += (i & 1 ? -1 : 1) * base;
    }
    x >>= 1;
    base <<= 1;
    i++;
  }
  return ret;
}

string out(int x) {
  string ret = "";
  while (x) {
    if (x & 1) {
      ret += "1";
    } else {
      ret += "0";
    }
    x >>= 1;
  }
  reverse(all(ret));
  return ret;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;

  if (N > 0) {
    int x = 0;
    int i = 0;
    while (x < N) {
      x |= (1ll << i);
      i += 2;
    }
    i -= 3;

    while (i >= 0) {
      int diff = f(x) - N;
      if (diff >= (1 << i)) {
        x ^= (1ll << i);
      }
      i--;
    }
    assert(f(x) == N);
    cout << out(x) << endl;

  } else if (N == 0) {
    cout << 0 << endl;
  } else {
    int x = 0;
    int i = 1;
    while (f(x) > N) {
      x |= (1ll << i);
      i += 2;
    }
    i -= 3;

    while (i >= 0) {
      int diff = -f(x) + N;
      if (diff >= (1 << i)) {
        x ^= (1ll << i);
      }
      i--;
    }
    assert(f(x) == N);
    cout << out(x) << endl;
  }

  return 0;
}
