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
bool is_leapYear(int year) {
  return (year % 4 == 0) and (year % 100 != 0 or year % 400 == 0);
}
vector<int> genearate_month(int year) {
  return vector<int>{
      0, 31, 28 + is_leapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int y, m, d;
  char c;
  cin >> y >> c >> m >> c >> d;
  auto month = genearate_month(y);
  while (y % (m * d) != 0) {
    if (d == month[m]) {
      d = 1;
      m++;
      if (m == 13) {
        m = 1;
        y++;
        month = genearate_month(y);
      }
    } else
      d++;
  }
  cout << y << c << (m < 10 ? "0" : "") << m << c << (d < 10 ? "0" : "") << d
       << endl;

  return 0;
}
