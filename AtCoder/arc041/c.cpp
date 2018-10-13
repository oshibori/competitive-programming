#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
typedef __int128_t Int;
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
template <typename T> void printvv(const vector<vector<T>> &v) {
  cerr << endl;
  rep(i, 0, v.size()) rep(j, 0, v[i].size()) {
    if (typeid(v[i][j]) == typeid(INF) and v[i][j] == INF) {
      cerr << "INF";
    } else
      cerr << v[i][j];
    cerr << (j == v[i].size() - 1 ? '\n' : ' ');
  }
  cerr << endl;
}
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

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, M;
  cin >> N >> M;
  vector<int> x;
  x.eb(0);
  vector<char> d;
  d.eb('R');
  loop(N) {
    int a;
    char b;
    cin >> a >> b;
    x.eb(a);
    d.eb(b);
  }
  x.eb(M + 1);
  d.eb('L');

  dump(x);
  dump(d);

  int ans = 0;
  rrep(i, 2, x.size()) {
    if (d[i] == d[i - 1] and d[i] == 'R') {
      ans += x[i] - x[i - 1] - 1;
      x[i - 1] = x[i] - 1;
    }
  }
  rep(i, 0, x.size() - 2) {
    if (d[i] == d[i + 1] and d[i] == 'L') {
      ans += x[i + 1] - x[i] - 1;
      x[i + 1] = x[i] + 1;
    }
  }
  vector<int> L(N + 2, 0), R(L);
  rep(i, 1, x.size() - 1) {
    if (d[i] == 'L')
      R[i] = 0;
    else if (d[i] == 'R')
      R[i] = R[i - 1] + 1;
  }
  rrep(i, 1, x.size() - 1) {
    if (d[i] == 'R')
      L[i] = 0;
    else if (d[i] == 'L')
      L[i] = L[i + 1] + 1;
  }
  dump(L);
  dump(R);

  rep(i, 1, x.size()) {
    if (d[i - 1] == 'R' and d[i] == 'L') {
      ans += max(R[i - 1], L[i]) * (x[i] - x[i - 1] - 1);
    }
  }
  cout << ans << endl;

  return 0;
}
