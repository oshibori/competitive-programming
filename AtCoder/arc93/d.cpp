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

  int A, B;
  cin >> A >> B;
  int k = 50;
  vector<string> v(2 * k);
  string b, w;
  loop(2 * k) {
    b += "#";
    w += ".";
  }
  rep(i, 0, k) {
    v[i] = b;
    v[i + k] = w;
  }
  auto inrange = [&](int x, int y) {
    return 0 <= x and x < 2*k and 0 <= y and y < 2 * k;
  };

  int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
  mt19937 rnd(0);

  int cnt = 0;
  while (cnt < A - 1) {
    int x = rnd() % (k), y = rnd() % (2 * k);

    if (v[x][y] == '.')
      continue;

    bool f = true;
    rep(k, 0, 4) {
      int X = x + dx[k], Y = y + dy[k];
      if (inrange(X, Y)) {
        f &= (v[X][Y] == v[x][y]);
      }
    }

    if (f)
      v[x][y] = '.', cnt++;
  }

  cnt = 0;
  while (cnt < B - 1) {
    int x = rnd() % (k) + k, y = rnd() % (2 * k);

    if (v[x][y] == '#')
      continue;
    bool f = true;
    rep(k, 0, 4) {
      int X = x + dx[k], Y = y + dy[k];
      if (inrange(X, Y)) {
        f &= (v[X][Y] == v[x][y]);
      }
    }

    if (f)
      v[x][y] = '#', cnt++;
  }

  cout << 2 * k << " " << 2 * k << endl;
  rep(i, 0, v.size()) cout << v[i] << endl;

  return 0;
}
