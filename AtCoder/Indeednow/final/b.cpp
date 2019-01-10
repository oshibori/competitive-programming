#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define ll long long
#define ll1 1ll
#define ONE 1ll
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

signed main(signed argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int R, C;
  cin >> R >> C;
  vector<vector<int>> v(R, vector<int>(C));
  pii s, t;
  rep(i, 0, R) rep(j, 0, C) {
    char c;
    cin >> c;
    if (c == 's') {
      s = pii(i, j);
    } else if (c == 't') {
      t = pii(i, j);
    } else {
      v[i][j] = c - '0';
    }
  }
  using State = tuple<int, int, int>;
  priority_queue<State, vector<State>, greater<State>> pq;
  pq.push(State(0, s.fi, s.se));
  map<pii, int> mp;
  mp[s] = 0;
  int dx[] = {0, 1, 1, 0, -1, -1},
      dy[][6] = {{1, 0, -1, -1, -1, 0}, {1, 1, 0, -1, 0, 1}};
  auto inrange = [&](int x, int y) {
    return 0 <= x and x < R and 0 <= y and y < C;
  };
  while (pq.size()) {
    int cost, x, y;
    tie(cost, x, y) = pq.top();
    pq.pop();
    if (cost > mp[pii(x, y)])
      continue;

    rep(i, 0, 6) {
      int a = x + dx[i], b = y + dy[x % 2][i];
      if (inrange(a, b)) {
        if (not mp.count(pii(a, b))) {
          mp[pii(a, b)] = INF;
        }
        if (chmin(mp[pii(a, b)], cost + v[a][b])) {
          pq.push(State(mp[pii(a, b)], a, b));
        }
      }
    }
  }
  cout << mp[t] << endl;

  return 0;
}
