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

int H, W;
bool inrange(int x, int y) { return 0 <= x and x < H and 0 <= y and y < W; }
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
bool check(vector<vector<int>> &v) {
  bool f = true;
  rep(i, 0, H * W - 1) {
    if (v[i / W][i % W] + 1 != v[(i + 1) / W][(i + 1) % W])
      f = false;
  }
  return f;
}
using node = vector<vector<int>>;
int h(vector<vector<int>> &v) {
  int ret = 0;
  rep(i, 0, v.size()) {
    rep(j, 0, v[i].size()) {
      if (not v[i][j])
        continue;
      int k = v[i][j] - 1;
      int x = k / W;
      int y = k % W;
      ret += abs(i - x) + abs(j - y);
    }
  }
  return ret;
}
int bfs(vector<vector<int>> v) {
  using state = tuple<int, node>;
  priority_queue<state, vector<state>, greater<state>> pq;
  pq.push(state(h(v), v));
  map<node, int> mp, color;
  mp[v] = 0;
  vector<vector<int>> w(H, vector<int>(W));
  rep(i, 0, H) rep(j, 0, W) w[i][j] = i * W + j + 1;
  w[H - 1][W - 1] = 0;
  while (pq.size()) {
    node u;
    int c;
    tie(c, u) = pq.top();
    pq.pop();
    if (u == w) {
      break;
    }
    rep(i, 0, u.size()) {
      rep(j, 0, u[i].size()) {
        if (u[i][j] == 0) {
          rep(k, 0, 4) {
            int a = i + dx[k], b = j + dy[k];
            if (inrange(a, b)) {
              auto nu = u;
              swap(nu[i][j], nu[a][b]);
              if (not mp.count(nu)) {
                mp[nu] = INF;
              }
              if (chmin(mp[nu], mp[u] + 1)) {
                if (mp[nu] + h(nu) < 24)
                  pq.push(state(mp[nu] + h(nu), nu));
              }
            }
          }
          goto here;
        }
      }
    }
  here:;
  }
  if (not mp.count(w))
    mp[w] = 24;
  return mp[w];
}

signed main(signed argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  cin >> H >> W;
  vector<vector<int>> v(H, vector<int>(W));
  rep(i, 0, H) rep(j, 0, W) { cin >> v[i][j]; }
  cout << bfs(v) << endl;

  return 0;
}
