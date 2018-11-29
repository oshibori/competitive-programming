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
int x[101010], y[101010], u[101010], v[101010];
int N;
int a, b;
int D;
using Point = tuple<int, int, int>;
set<Point> stx, sty;
set<int> s;

void dfs(int p) {
  dump(p);
  s.insert(p);
  stx.erase(Point(u[p], v[p], p));
  sty.erase(Point(v[p], u[p], p));

  Point aa(u[p] - D, v[p] - D, N);
  Point bb(u[p] - D, v[p] + D, N);
  Point cc(u[p] + D, v[p] + D, N);
  Point dd(u[p] + D, v[p] - D, N);

  auto ld = stx.lower_bound(aa);
  while (ld != stx.end() and *ld <= bb) {
    int idx = get<2>(*ld);
    dfs(idx);
    ld++;
  }
  ld = sty.lower_bound(Point(get<1>(bb), get<0>(bb), get<2>(bb)));
  while (ld != sty.end() and *ld <= Point(get<1>(cc), get<0>(cc), get<2>(cc))) {
    int idx = get<2>(*ld);
    dfs(idx);
    ld++;
  }
  ld = stx.lower_bound(dd);
  while (stx.end() != ld and *ld <= cc) {
    int idx = get<2>(*ld);
    dfs(idx);
    ld++;
  }
  ld = sty.lower_bound(Point(get<1>(aa), get<0>(aa), get<2>(aa)));
  while (ld != sty.end() and *ld <= Point(get<1>(dd), get<0>(dd), get<2>(dd))) {
    int idx = get<2>(*ld);
    dfs(idx);
    ld++;
  }
}
signed main(signed argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  cin >> N;
  cin >> a >> b;
  a--, b--;
  rep(i, 0, N) {
    cin >> x[i] >> y[i];
    u[i] = x[i] - y[i];
    v[i] = x[i] + y[i];
    stx.insert(Point(u[i], v[i], i));
    sty.insert(Point(v[i], u[i], i));
  }
  D = max(abs(u[a] - u[b]), abs(v[a] - v[b]));
  dump(stx, sty);
  dfs(a);
  dump(s);
  vector<Point> xx, yy;
  for (auto i : s) {
    xx.eb(Point(u[i], v[i], i));
    yy.eb(Point(v[i], u[i], i));
  }
  sort(all(xx));
  sort(all(yy));
  int ans = 0;
  rep(i, 0, N) {
    Point aa(u[i] - D, v[i] - D, N);
    Point bb(u[i] - D, v[i] + D, N);
    auto lb = lower_bound(all(xx), aa);
    if (*lb == aa)
      ans--;
    auto ub = upper_bound(all(xx), bb);
    ans += ub - lb;

    bb = Point(v[i] + D, u[i] - D, N);
    lb = lower_bound(all(yy), bb);
    if (*lb == bb)
      ans--;
    Point cc(v[i] + D, u[i] + D, N);
    ub = upper_bound(all(yy), cc);
    ans += ub - lb;

    cc = Point(u[i] + D, v[i] + D, N);
    Point dd(u[i] + D, v[i] - D, N);
    lb = lower_bound(all(xx), dd);
    if (*lb == dd)
      ans--;
    ub = upper_bound(all(xx), cc);
    ans += ub - lb;

    aa = Point(v[i] - D, u[i] - D, N);
    dd = Point(v[i] - D, u[i] + D, N);
    lb = lower_bound(all(yy), aa);
    if (*lb == aa)
      ans--;
    ub = upper_bound(all(yy), dd);
    ans += ub - lb;
  }
  cout<<ans/2<<endl;

  return 0;
}
