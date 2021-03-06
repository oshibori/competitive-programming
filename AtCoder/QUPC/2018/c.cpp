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
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int H, W, X;
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  cin >> H >> W >> X;
  vector<string> s(H);
  rep(i, 0, H) { cin >> s[i]; }

  vector<vector<int>> v(H, vector<int>(W, INF));
  vector<vector<int>> danger(H, vector<int>(W, 0));
  vector<vector<int>> color(H, vector<int>(W, 0));
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      pq;
  int sx, sy, gx, gy;
  rep(i, 0, H) {
    rep(j, 0, W) {
      if (s[i][j] == '@') {
        pq.push(make_tuple(0, i, j));
      } else if (s[i][j] == 'S') {
        sx = i, sy = j;
      } else if (s[i][j] == 'G') {
        gx = i, gy = j;
      }
    }
  }
  int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
  auto inrange = [&](int x, int y) {
    return 0 <= x and x < H and 0 <= y and y < W;
  };
  while (pq.size()) {
    int c, i, j;
    tie(c, i, j) = pq.top();
    pq.pop();
    if (c == X + 1 or danger[i][j])
      continue;
    danger[i][j] = 1;
    rep(k, 0, 4) {
      int x = i + dx[k], y = j + dy[k];
      if (inrange(x, y) and s[x][y] != '#') {
        pq.push(make_tuple(c + 1, x, y));
      }
    }
  }
  printvv(danger);

  pq.push(make_tuple(0, sx, sy));
  v[sx][sy] = 0;
  while (pq.size()) {
    int c, i, j;
    tie(c, i, j) = pq.top();
    pq.pop();
    if (v[i][j] < c)
      continue;
    color[i][j] = 1;
    rep(k, 0, 4) {
      int x = i + dx[k], y = j + dy[k];
      if (inrange(x, y) and s[x][y] != '#' and !danger[x][y] and
          !color[x][y] and chmin(v[x][y], c + 1)) {
        pq.push(make_tuple(c + 1, x, y));
      }
    }
  }

  if (v[gx][gy] != INF) {
    cout << v[gx][gy] << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
