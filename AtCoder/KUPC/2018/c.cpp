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
bool inrange(int x, int y) { return 0 <= x and x < 9 and 0 <= y and y < 9; }
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  vector<vector<int>> v(9, vector<int>(9, 0)), w(v), x(v);
  rep(i, 0, 9) rep(j, 0, 9) { v[i][j] =1;} //min(3, min(j + 1, 9 - j)); }

  rep(i, 0, 9) rep(j, 0, 9) { w[j][i] = 1;}//min(3, min(j + 1, 9 - j)); }

  rep(i, 0, 9) x[i][i] =1;// min(3, min(i + 1, 9 - i));
  rep(i, 1, 9) {
    if (9 - i >= 7) {
      rep(j, 0, 9 - i) {
        x[j][j + i] =1;// min(3 - i, min(j + 1, 9 - j - i));
        x[j + i][j] = x[j][j + i];
      }
    }
  }
  vector<vector<int>> y(x);
  rep(i, 0, 9) rep(j, 0, 9) { y[i][j] = x[i][8 - j]; }
  vector<vector<int>> z(9, vector<int>(9, 0));
  rep(i, 0, 9) {
    rep(j, 0, 9) { z[i][j] = v[i][j] + w[i][j] + x[i][j] + y[i][j]; }
  }
  printvv(z);

  int r, c;
  int dx[] = {1, -1, -1, 1}, dy[] = {1, 1, -1, -1};
  vector<pii> ans;
  int mode = 0;
  while (true) {
    r = 0, c = 0;
    rep(i, 0, 9) rep(j, 0, 9) {
      if (z[i][j] > z[r][c]) {
        r = i, c = j;
      }
    }
    dump(r, c, z[r][c]);

    if (z[r][c] == 0)
      break;

    ans.eb(r, c);
    rep(i, 0, 9) z[i][c] -= w[i][c], w[i][c] = 0;
    rep(i, 0, 9) { z[r][i] -= v[r][i], v[r][i] = 0; }
    z[r][c] -= x[r][c] + y[r][c];
    x[r][c] = y[r][c] = 0;
    rep(i, 0, 4) {
      int a = r + dx[i], b = c + dy[i];
      while (inrange(a, b)) {
        if (i == 0 or i == 2) {
          z[a][b] -= x[a][b];
          x[a][b] = 0;
        } else {
          z[a][b] -= y[a][b];
          y[a][b] = 0;
        }
        a += dx[i];
        b += dy[i];
      }
    }
    printvv(v);
    printvv(w);
    printvv(x);
    printvv(y);
    printvv(z);
  }
  dump(ans.size());
  dump(ans);

  return 0;
}
