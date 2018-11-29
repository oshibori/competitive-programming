#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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
    } else
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
// source http://satanic0258.hatenablog.com/entry/2016/08/16/181331
// https://yukicoder.me/problems/no/703
// addの直線の傾きの単調性が保証されている
class ConvexHullTrick {
public:
  deque<pair<int, int>> lines;
  // queryのxの単調性が保証されているとき、true
  bool isMonotonic = true;
  function<bool(int, int)> comp = [](int l, int r) {
    return l >= r; // min
    // return l <= r; // max
  };

  // l1,l2,l3のうち、l2が不必要であるかどうか
  bool check(pair<int, int> l1, pair<int, int> l2, pair<int, int> l3) {
    if (l1 < l3)
      swap(l1, l3);
    int a1 = l1.first, b1 = l1.second;
    int a2 = l2.first, b2 = l2.second;
    int a3 = l3.first, b3 = l3.second;
    return (a2 - a3) * (b1 - b2) <= (a1 - a2) * (b2 - b3);
  }
  void add(int a, int b) {
    pair<int, int> line(a, b);
    while (lines.size() >= 2 and
           check(lines[lines.size() - 2], lines[lines.size() - 1], line)) {
      lines.pop_back();
    }
    lines.emplace_back(line);
  }
  int f(int j, int x) { return lines[j].first * x + lines[j].second; }

  int query(int x) {
    if (isMonotonic) {
      while (lines.size() >= 2 and comp(f(0, x), f(1, x))) {
        lines.pop_front();
      }
      return f(0, x);
    } else {
      int l = 0, r = lines.size();
      while (r - l > 1) {
        int m = (l + r) / 2;
        if (comp(f(m - 1, x), f(m, x))) {
          l = m;
        } else {
          r = m;
        }
      }
      return f(l, x);
    }
  }
};

signed main(signed argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  vector<int> a(N + 1);
  ConvexHullTrick cht;
  rep(i, 1, N + 1) {
    cin >> a[i];
    cht.add(-2 * i, a[i] + i * i);
  }
  rep(i, 1, N + 1) { cout << cht.query(i)+i*i << endl; }

  return 0;
}
