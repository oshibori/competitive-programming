#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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

  int N, K;
  cin >> N >> K;
  vector<int> a(N + 1);
  rep(i, 1, N + 1) {
    cin >> a[i];
    a[i] += a[i - 1];
  }

  vector<vector<int>> v(64);
  rep(i, 0, N + 1) {
    rep(j, i + 1, N + 1) {
      int x = a[j] - a[i];
      rrep(k, 0, 64) {
        if ((x >> k) & 1) {
          v[k].eb(x);
        }
      }
    }
  }
  dump(v);

  int ans = 0;
  rrep(i, 0, 64) {
    if (v[i].size() >= K) {
      int tmp = 1 << i;
      dump(i, v[i]);
      rrep(j, 0, i) {
        dump(j, v[i]);
        int cnt = 0;
        vector<int> w;
        rep(k, 0, v[i].size()) {
          if ((v[i][k] >> j) & 1) {
            cnt++;
            w.eb(v[i][k]);
          }
        }
        if (cnt >= K) {
          tmp += 1 << j;
          dump(tmp, j, cnt);
          v[i] = w;
          //v[i].clear();
          //v[i].insert(v[i].end(), all(w));
        }
      }
      ans = tmp;
      break;
    }
  }
  cout << ans << endl;

  return 0;
}
