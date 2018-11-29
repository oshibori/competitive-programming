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
class Solution {
public:
  // https://leetcode.com/contest/weekly-contest-111/problems/find-the-shortest-superstring/
  string dp[1 << 12][12];
  // dp[S][i] :=
  // Sの要素のなかで、ith_stringが最後にくるときのShortestSuperString
  int f(string a, string b) {
    int ret = 0;
    int idx = 0;
    while (idx < min(a.size(), b.size())) {
      if (a.substr(a.size() - 1 - idx) == b.substr(0, idx + 1))
        chmax(ret, idx + 1);
      idx++;
    }
    return ret;
  }
  string shortestSuperstring(vector<string> &A) {
    int n = A.size();
    rep(i, 0, 1 << 12) rep(j, 0, 12) dp[i][j] = string(1, '?');
    rep(i, 0, n) dp[0][i] = "";
    rep(bits, 1, 1 << n) {
      rep(i, 0, n) {
        if (!(bits >> i & 1))
          continue;
        rep(j, 0, n) {
          string &x = dp[bits][i], y = dp[bits ^ (1 << i)][j], z = A[i];
          if (y == "?")
            continue;
          int k = f(y, z);
          y += z.substr(k);
          if (x.size() > y.size() or x == "?")
            x = y;
        }
        //        dump(bitset<12>(bits), i, dp[bits][i]);
      }
    }
    string ans(250, '?');
    rep(i, 0, n) {
      //     dump(dp[(1 << n) - 1][i], ans);
      if (ans.size() >= dp[(1 << n) - 1][i].size())
        ans = dp[(1 << n) - 1][i];
    }
    dump(ans);
    return ans;
  }
};

signed main(signed argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  vector<string> input = {"alex", "loves", "leetcode"};
  vector<string> input2 = {"catg", "ctaagt", "gcta", "ttca", "atgcatc"};
  vector<string> input3 = {"pqtifawzoessrpjwnjf", "wnjfjehefpipubizjx",
                           "vpmafqkvixcumugp",    "tzucldkoizjhyat",
                           "umugpqtifawzoes",     "zjxtifiolejwstzuc",
                           "pjwnjfjehefpipub",    "ifiolejwstzucldko"};

  vector<string> input4 = {
      "qrwpawefqzfjsan",     "jsanzdukfkdlmyox",    "neaxnkedjxbpgsyq",
      "nqjvzryhfjdsxmwolwo", "hfjdsxmwolwomeeewvi", "lmyoxbpvkneaxnkedjxb",
      "qbhpqrwpawefqzfjsa",  "pawefqzfjsanzdukfk",  "bqbhpqrwpawefqzfj",
      "dlmyoxbpvkneaxnk",    "xnkedjxbpgsyqovvh"};
  Solution().shortestSuperstring(input4);
  return 0;
}
