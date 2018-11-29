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
int visited[101010] = {};
void dfs(int p, int v, bool odd, int a, vector<vector<pii>> &g,
         vector<vector<pii>> &constraint) {
  if (visited[v])
    return;
  visited[v] = true;

  for (pii x : g[v]) {
    if (x.fi == p)
      continue;
    constraint[x.fi].eb(x.se - a, !odd);
    dfs(v, x.fi, !odd, x.se - a, g, constraint);
  }
}
signed main(signed argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, M;
  cin >> N >> M;
  vector<vector<pii>> g(N), constraint(N);
  loop(M) {
    int u, v, s;
    cin >> u >> v >> s;
    u--, v--;
    g[u].eb(v, s);
    g[v].eb(u, s);
  }
  dfs(-1, 0, 0, 0, g, constraint);
  dump(constraint);
  pii ans(1, INF);

  for (auto &x : constraint) {
    vector<int> a, b;
    for (auto &y : x) {
      if (y.se) {
        b.eb(y.fi);
      } else {
        a.eb(y.fi);
      }
    }
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    sort(all(b));
    b.erase(unique(all(b)), b.end());

    if (a.size() > 1 or b.size() > 1) {
      ans.fi = INF;
      ans.se = -INF;
      break;
    } else if (a.size() == 1 and b.size() == 1) {
      // a+t == b-t => 2t == b-a
      int t = (b[0] - a[0]) / 2;
      if ((b[0] - a[0]) % 2 == 0 and t > 0) {
        chmax(ans.fi, t);
        chmin(ans.se, t + 1);
      }
    } else {
      for (auto &y : x) {
        dump(y);
        if (y.se) {
          chmin(ans.se, y.fi);
        } else {
          chmax(ans.fi, 1 - y.fi);
        }
        dump(ans);
      }
    }
  }

  cout << max(0ll, ans.se - ans.fi) << endl;

  return 0;
}
