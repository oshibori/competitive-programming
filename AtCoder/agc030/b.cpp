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

int dp[2222][2222][2];
tuple<int, int, int> restoration[2222][2222][2];
int X[2222];
int L;
int N;
int dfs(int x, int y, int z) {
  int &ret = dp[x][y][z];
  if (ret >= 0)
    return ret;
  if (x == y) {
    return 0;
  }
  if (z == 0) {
    int a = dfs(x + 1, y, 0) + X[x + 1] - X[x];
    int b = dfs(x + 1, y, 1) + X[x] + L - X[y];
    if (a > b) {
      restoration[x][y][z] = make_tuple(x + 1, y, 0);
    } else
      restoration[x][y][z] = make_tuple(x + 1, y, 1);
  } else {
    int a = dfs(x, y - 1, 1) + X[y] - X[y - 1];
    int b = dfs(x, y - 1, 0) + X[x] + L - X[y];
    if (a > b) {
      restoration[x][y][z] = make_tuple(x, y - 1, 1);
    } else
      restoration[x][y][z] = make_tuple(x, y - 1, 0);
  }
  return ret;
}
signed main(signed argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  rep(i, 0, 2222) rep(j, 0, 2222) rep(k, 0, 2) dp[i][j][k] = -1;
  cin >> L;
  cin >> N;
  assert(N <= 2000);
  rep(i, 0, N) { cin >> X[i]; }
  int a = dfs(0, N - 1, 0) + X[0];
  int b = dfs(0, N - 1, 1) + L - X[N - 1];
  int ans = max(a, b);
  int x = 0, y = N - 1, z;
  if (a > b) {
    z = 0;
  } else {
    z = 1;
  }
  dump(x, y, z);
  while (x != y) {
    auto t = restoration[x][y][z];
    dump(t);
    int cur, nxt;
    if (z == 0) {
      cur = x;
    } else {
      cur = y;
    }
    tie(x, y, z) = t;
    if (z == 0) {
      nxt = x;
    } else {
      nxt = y;
    }
    dump(cur,nxt);
  }

  return 0;
}
