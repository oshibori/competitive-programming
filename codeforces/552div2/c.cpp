#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
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
bool f(vector<int> a, vector<int> b) {
  rep(i, 0, a.size() - 1) {
    if (a[i] < a[i + 1]) {
      if (b[i] >= b[i + 1])
        return false;
    } else if (a[i] > a[i + 1]) {
      if (b[i] <= b[i + 1])
        return false;
    } else {
      if (b[i] == b[i + 1])
        return false;
    }
  }
  return true;
}
signed main(signed argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  vector<int> a(N), b(N);
  rep(i, 0, N) { cin >> a[i]; }
  if (N == 1) {
    cout << 1 << endl;
    return 0;
  }
  int i = 0;
  auto check = [&](int x) {
    if (x < 1 or 5 < x) {
      cout << -1 << endl;
      exit(0);
    }
    return;
  };
  while (i + 1 < N) {
    while (i + 1 < N and a[i] < a[i + 1]) {
      if (i == 0 or a[i - 1] > a[i])
        b[i] = 1;
      else if (a[i - 1] < a[i])
        b[i] = b[i - 1] + 1;
      else {
        if (b[i - 1] == 1)
          b[i] = 2;
        else
          b[i] = 1;
      }
      check(b[i]);
      i++;
    }
    b[i] = 5;
    while (i + 1 < N and a[i] > a[i + 1]) {
      if (i == 0 or a[i - 1] < a[i])
        b[i] = 5;
      else if (a[i - 1] < a[i])
        b[i] = b[i - 1] - 1;
      else {
        if (b[i - 1] == 5)
          b[i] = 4;
        else
          b[i] = 5;
      }
      check(b[i]);
      i++;
    }
    b[i] = 1;
    while (i + 1 < N and a[i] == a[i + 1]) {
      if (i == 0 or a[i - 1] != a[i]) {
        b[i] = 3;
      } else if (i - 2 >= 0)
        b[i] = b[i - 2];
      else
        b[i] = 2;
      check(b[i]);
      i++;
    }
  }
  if (a[i - 1] < a[i])
    b[i] = b[i - 1] + 1;
  else if (a[i - 1] > a[i])
    b[i] = b[i - 1] - 1;
  else {
    if (i - 2 >= 0)
      b[i] = b[i - 2];
    else
      b[i] = (b[i - 1] == 5 ? 1 : b[i - 1] + 1);
  }
  check(b[i]);

  assert(f(a,b));
  rep(i, 0, N) { cout << b[i] << (i == N - 1 ? '\n' : ' '); }

  return 0;
}
