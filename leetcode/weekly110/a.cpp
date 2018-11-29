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
struct Log {
  string s;
  vector<string> v;
  bool is_letter_log;
  int order;
  Log(const string s, const int order) : s(s), order(order) {
    stringstream ss(s);
    string tmp;
    while (ss >> tmp) {
      v.eb(tmp);
    }
    is_letter_log = true;
    rep(i, 1, v.size()) {
      for (char c : v[i]) {
        if (isdigit(c))
          is_letter_log = false;
      }
    }
    dump(s, v, is_letter_log);
  }
  bool operator<(Log x) {
    if (is_letter_log ^ x.is_letter_log) {
      return is_letter_log;
    } else {
      if (!is_letter_log) {
        return order < x.order;
      } else {
        int k = min(v.size(), x.v.size());
        int i = 1;
        while (i < k and v[i] == x.v[i])
          i++;
        if (i == k) {
          return v.size() < x.v.size();
        } else {
          return v[i] < x.v[i];
        }
      }
    }
  }
};
class Solution {
public:
  vector<string> reorderLogFiles(vector<string> &logs) {
    vector<Log> v;
    rep(i, 0, logs.size()) { v.eb(Log(logs[i], i)); }
    sort(all(v));
    vector<string> ret;
    rep(i, 0, v.size()) { ret.eb(v[i].s); }
    dump(ret);
    return ret;
  }
};
signed main(signed argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  vector<string> input{"a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog",
                       "a8 act zoo"};
  Solution().reorderLogFiles(input);

  return 0;
}
