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

int doubling[101010][35];
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  vector<int> x(N);
  rep(i, 0, N) { cin >> x[i]; }
  int L;
  cin >> L;
  int Q;
  cin >> Q;
  vector<int> a(Q), b(Q);
  rep(i, 0, Q) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
    if (a[i] > b[i])
      swap(a[i], b[i]);
  }
  memset(doubling, 0xff, sizeof(doubling));
  rep(i, 0, N) {
    int idx = upper_bound(x.begin() + i, x.end(), x[i] + L) - x.begin();
    idx--;
    doubling[i][0] = (idx == i ? INF : idx);
    dump(i, doubling[i][0]);
  }
  rep(n, 1, 35) {
    rep(i, 0, N) {
      if (doubling[i][n - 1] == INF) {
        doubling[i][n] = INF;
      } else
        doubling[i][n] = doubling[doubling[i][n - 1]][n - 1];
    }
  }

  int powtwo[35];
  powtwo[0] = 1;
  rep(i, 1, 35) powtwo[i] = 2 * powtwo[i - 1];

  rep(i, 0, Q) {
    int ans = INF;
    int cnt = 0;
    int s = a[i], t = b[i];
    dump(s,t);
    rrep(j, 0, log2(N)+1) {
      dump(s,j,doubling[s][j]);
      if (doubling[s][j] >= t) {
        chmin(ans, cnt + powtwo[j]);
      }
      if (doubling[s][j] < t) {
        s = doubling[s][j];
        cnt += powtwo[j];
      }
    }
    // assert(s == t);
    cout << ans << endl;
  }

  return 0;
}
