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
//高速累乗 繰り返し自乗法
//オーバーフローする可能性があれば掛け算にmodmul()を使う
double modpow(double base, long long exponent) {
  double res = 1;
  while (exponent > 0) {
    if (exponent & 1)
      res = res * base;
    base = base * base;
    exponent >>= 1;
  }
  return res;
}
double dp[50][50];
int A[50][50];
vector<pii> order;
int N;
double p, q;
double dfs(int idx = 0, int v = N-1) {
  dump(idx,v);
  double &ret = dp[idx][v];
  if (ret >= 0)
    return ret;
  if (idx == N) {
    return ret = 1;
  }

  int person = order[idx].se;
  vector<vector<double>> nCr(N + 1, vector<double>(N + 1, 0));
  vector<int> result;
  rep(i, 0, N) {
    if (i == person)
      continue;
    result.eb(A[person][i]);
  }
  nCr[0][0] = 1;
  rep(i, 1, N) {
    double win = (result[i - 1] ? p : q);
    double lose = 1 - win;
    rep(j, 0, i + 1) {
      if (j == 0) {
        nCr[i][j] = nCr[i - 1][j] * lose;
      } else if (j == i) {
        nCr[i][j] = nCr[i - 1][j - 1] * win;
      } else {
        nCr[i][j] = nCr[i - 1][j - 1] * win + nCr[i - 1][j] * lose;
      }
    }
  }
  ret = 0;
  rep(i, 0, v + 1) {
    if (i == v) {
      if (idx == 0 or order[idx - 1].se < order[idx].se)
        ret += dfs(idx + 1, i) * nCr[N - 1][i];
    } else
      ret += dfs(idx + 1, i) * nCr[N - 1][i];
  }
  return ret;
}
signed main(signed argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  cin >> N;
  char c;
  double a, b;
  cin >> a >> c >> b;
  rep(i, 0, N) rep(j, 0, N) { cin >> A[i][j]; }
  p = a / b, q = 1 - p;
  /*
    nCr.resize(n + 1, vector<int>(n + 1));
    nCr[0][0] = 1;
    nCr[1][0] = 1, nCr[1][1] = 1;
    rep(i, 2, nCr.size()) {
      rep(j, 0, i + 1) {
        if (j == 0) {
          nCr[i][j] = nCr[i - 1][j] * 1;
        } else if (j == i) {
          nCr[i][j] = nCr[i - 1][j - 1] * 1;
        } else {
          nCr[i][j] = nCr[i - 1][j - 1] * 1 + nCr[i - 1][j] * 1;
        }
      }
    }
    */

  rep(i, 0, N) {
    int cnt = 0;
    rep(j, 0, N) { cnt += A[i][j]; }
    order.eb(cnt, i);
  }
  sort(all(order),
       [](pii a, pii b) { return (a.fi == b.fi ? a.se < b.se : a.fi > b.fi); });

  dump(order);
  rep(i, 0, 50) rep(j, 0, 50) dp[i][j] = -1;
  cout << dfs() << endl;

  return 0;
}
