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
int A[101010], B[101010];
int V[101010], P[101010];
int N;
int K;
int f[101010], h[101010];
vector<int> G[101010];
map<int, int> mp[101010], fixed_[101010];
int dist[101010];
void dfs(int p, int v, int d) {
  dist[v] = d;

  for (int x : G[v]) {
    if (x == p)
      continue;
    dfs(v, x, d + 1);
  }
}
map<int, pii> range;
pii rec(int p, int v) {

  pii ret;
  ret = pii(-INF, INF);
  dump(p, v, ret);

  for (int x : G[v]) {
    if (x == p)
      continue;
    pii r = rec(v, x);
    dump(x, r);
    r.fi--,r.se++;
    chmax(ret.fi, r.fi);
    chmin(ret.se, r.se);
    dump(v, ret);
  }
  if (ret.fi > ret.se) {
    ret.fi = INF;
    ret.se = -INF;
    dump(p, v, ret);
    return ret;
  } else if (f[v] != INF) {
    if (ret.fi <= f[v] and f[v] <= ret.se) {
      range[v] = pii(f[v], f[v]);
      dump(p, v, ret);
      return range[v];
    } else {
      dump(p, v, ret);
      return pii(INF, -INF);
    }
  }
  dump(p, v, ret);
  return range[v] = ret;
}
void restore(int p, int v, int w) {

  h[v] = w;

  for (int x : G[v]) {
    if (x == p)
      continue;

    if (range[x].fi <= w - 1 and w - 1 <= range[x].se) {
      restore(v, x, w - 1);
    } else {
      restore(v, x, w + 1);
    }
  }
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  cin >> N;
  rep(i, 0, N - 1) {
    cin >> A[i] >> B[i];
    A[i]--, B[i]--;
    G[A[i]].eb(B[i]);
    G[B[i]].eb(A[i]);
  }
  memset(f, 0x3f, sizeof(f));
  cin >> K;
  rep(i, 0, K) {
    cin >> V[i] >> P[i];
    V[i]--;
    f[V[i]] = P[i];
    h[V[i]] = P[i];
  }
  dfs(-1, V[0], 0);

  rep(i, 0, N) {
    if (f[i] != INF and abs(f[i] - P[0]) % 2 != dist[i] % 2) {
      Yes(0);
      dump("aaa");
      return 0;
    }
  }

  auto ret = rec(-1, V[0]);
  if (ret.fi == ret.se and ret.fi == P[0]) {
    Yes(1);
    restore(-1, V[0], P[0]);
    rep(i, 0, N) { cout << h[i] << endl; }

  } else {
    Yes(0);
    dump("bbb");
//    assert(1 == 2);
    rep(i, 0, N) { dump(range[i]); }
  }

  return 0;
}
