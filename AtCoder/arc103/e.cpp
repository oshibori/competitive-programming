#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
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

  string s;
  cin >> s;
  int n = s.size();
  dump(n);
  vector<int> v;
  string t = s.substr(0, n - 1);
  string t2(t);
  reverse(all(t2));
  if (t != t2 or s[0] == '0' or s[n - 1] == '1' or s[n - 2] == '0') {
    cout << -1 << endl;
    return 0;
  }

  if (n <= 4) {
    if (n >= 2) {
      cout << 1 << " " << 2 << endl;
    }
    if (n >= 3) {
      cout << 2 << " " << 3 << endl;
    }
    if (n >= 4) {
      if (s[1] == '0') {
        cout << 2 << " " << 4 << endl;
      } else {
        cout << 3 << " " << 4 << endl;
      }
    }
    return 0;
  }

  rep(i, 1, n - 2) {
    if (s[i] == '1' and i < (n + 1) / 2)
      v.eb(i + 1);
  }
  if (v.empty())
    v.eb(1);
  v.eb(n - v.back());
  dump(v);
  rrep(i, 1, v.size() - 1) { v[i] -= v[i - 1]; }
  dump(v);
  int a = 1;
  vector<int> w;
  rep(i, 0, v.size()) {
    int x = a++;
    loop(v[i] - 1) {
      int y = a++;
      cout << x << " " << y << endl;
    }
    if (i > 0) {
      cout << x << " " << w.back() << endl;
    }
    w.eb(x);
  }

  return 0;
}
