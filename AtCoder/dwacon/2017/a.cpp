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

pii dp[55][55][55];
int N = 55;
string S;
pii dfs(int l, int r, int k) {
  dump(l, r, k);
  pii &ret = dp[l][r][k];
  if (ret != pii(INF, -INF))
    return ret;

  if (r - l == 1) {
    if (isdigit(S[l]))
      ret.fi = ret.se = S[l] - '0';
    if (k > 0) {
      ret.fi = 0, ret.se = 9;
    }
    return ret;
  }

  rep(i, l + 1, r - 1) {
    int nk = k - (S[r - 1] != '+');
    rep(j, 0, nk + 1) {
      pii op1 = dfs(l, i, j);
      pii op2 = dfs(i, r - 1, nk - j);
      if (op1.fi >= INF or op2.fi >= INF)
        continue;
      chmin(ret.fi, op1.fi + op2.fi);
      chmax(ret.se, op1.se + op2.se);
      dump(op1, op2);
    }
    nk = k - (S[r - 1] != '-');
    rep(j, 0, nk + 1) {
      pii op3 = dfs(l, i, j);
      pii op4 = dfs(i, r - 1, nk - j);
      if (op3.fi >= INF or op4.fi >= INF)
        continue;
      chmin(ret.fi, op3.fi - op4.se);
      chmax(ret.se, op3.se - op4.fi);
      dump(op3, op4);
    }
  }
  if (ret.fi == INF)
    ret.fi++;
  if (ret.se == -INF)
    ret.se--;
  return ret;
}
signed main(signed argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int K;
  cin >> K;
  cin >> S;
  rep(i, 0, N) rep(j, 0, N) rep(k, 0, N) { dp[i][j][k] = pii(INF, -INF); }
  int ans = dfs(0, S.size(), K).se;
  if (ans <= -INF) {
    cout << "NG" << endl;
  } else {
    cout << "OK" << endl << ans << endl;
  }

  return 0;
}
