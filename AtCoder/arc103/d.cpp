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

  int N;
  cin >> N;
  vector<int> x(N), y(N);
  rep(i, 0, N) { cin >> x[i] >> y[i]; }

  vector<int> possible(N);
  bool result = true;
  rep(i, 0, N) {
    int a = x[i] & 1, b = y[i] & 1;
    possible[i] = a ^ b;
    if (i > 0) {
      result &= possible[i] == possible[i - 1];
    }
  }
  if (not result) {
    cout << -1 << endl;
    return 0;
  }

  vector<int> u(N), v(N);
  rep(i, 0, N) {
    u[i] = x[i] + y[i];
    v[i] = x[i] - y[i];
  }

  vector<int> d(31);
  rep(i, 0, d.size()) { d[i] = 1ll << i; }
  if (possible[0] == 0) {
    d.eb(1);
  }
  int m = d.size();
  int dsum = accumulate(all(d), 0ll);
  cout << m << endl;
  rep(i, 0, m) { cout << d[i] << (i == m - 1 ? '\n' : ' '); }

  rep(i, 0, N) {
    string w;
    bitset<32> s = (u[i] + dsum) / 2;
    bitset<32> t = (v[i] + dsum) / 2;
    rep(j, 0, m) {
      int h = (s[j] << 1) | (t[j]);
      if (h == 0) {
        w += "L";
      } else if (h == 1) {
        w += "D";
      } else if (h == 2) {
        w += "U";
      } else {
        w += "R";
      }
    }
    cout << w << endl;
#ifdef _DEBUG
    int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    map<char, int> mp;
    mp['R'] = 0;
    mp['U'] = 1;
    mp['L'] = 2;
    mp['D'] = 3;
    int a = 0, b = 0;
    rep(j, 0, m) {
      int idx = mp[w[j]];
      a += dx[idx] * d[j];
      b += dy[idx] * d[j];
    }
    assert(x[i] == a and y[i] == b);
#endif
  }

  return 0;
}
