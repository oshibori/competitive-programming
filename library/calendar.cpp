#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
// typedef __int128_t Int;
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

bool is_leapYear(int year) {
  return (year % 4 == 0) and (year % 100 != 0 or year % 400 == 0);
}
vector<int> genearate_month(int year) {
  return vector<int>{
      0, 31, 28 + is_leapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
}
// zeller's congruence で曜日を求める
string zellers_congruence(int y, int m, int d) {
  if (m < 3) {
    y--;
    m += 12;
  }
  vector<string> s{"Sunday",   "Monday", "Tuesday", "Wednesday",
                   "Thursday", "Friday", "Saturday"};

  int idx = (y + y / 4 - y / 100 + y / 400 + (13 * m + 8) / 5 + d) % 7;
  return s[idx];
}
