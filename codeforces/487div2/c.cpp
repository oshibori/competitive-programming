#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
// typedef __int128_t Int;
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

  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int n = 50, m = 50;
  vector<string> v(n);
  string s, t, p, q;
  rep(i, 0, n / 2) {
    s += "A";
    t += "B";
    p += "C";
    q += "D";
  }
  s += t;
  p += q;

  rep(i, 0, n / 2) {
    v[i] = s;
    v[i + n / 2] = p;
  }

  for (int cnt = 0, x = 0, y = 0; cnt < d - 1;) {
    if (0 <= x and x < n / 2 and 0 <= y and y < n / 2) {
      v[x][y] = 'D';
      cnt++;
      y+=2;
    } else {
      x+=2;
      y = 0;
    }
  }
  for (int cnt = 0, x = 0, y = n / 2; cnt < c - 1;) {
    if (0 <= x and x < n / 2 and n / 2 <= y and y < n) {
      v[x][y] = 'C';
      cnt++;
      y+=2;
    } else {
      x+=2;
      y = n / 2;
    }
  }
  for (int cnt = 0, x = n / 2, y = 0; cnt < b - 1;) {
    if (n / 2 <= x and x < n and 0 <= y and y < n / 2) {
      v[x][y] = 'B';
      cnt++;
      y+=2;
    } else {
      x+=2;
      y = 0;
    }
  }
  for (int cnt = 0, x = n / 2, y = n / 2; cnt < a - 1;) {
    if (n / 2 <= x and x < n and n / 2 <= y and y < n) {
      v[x][y] = 'A';
      cnt++;
      y+=2;
    } else {
      x+=2;
      y = n / 2;
    }
  }

  cout << n << " " << m << endl;
  rep(i, 0, n) cout << v[i] << endl;

  return 0;
}
