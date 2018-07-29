#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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
uint32_t x, y, z, w;
uint64_t seed;
void init() {
  x = seed;
  y = 1, z = 2, w = 3;
}
int32_t generate() {
  uint32_t t = (x ^ (x << 11));
  x = y;
  y = z;
  z = w;
  w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
  return w;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  cin >> seed;
  init();
  dump(generate());
  dump(generate());
  dump(generate());
  dump(generate());
  dump(generate());
  dump(generate());
  int l = 0, r = (1ll << 32);
  int A = 10000001;
  while (abs(r - l) > 1) {
    int m = (l + r) / 2;
    init();
    int c = 0;
    loop(A) {
      uint64_t g = generate();
      if (g < m)
        c++;
    }
    dump(l, r, m, c);

    if (c <= 5000000)
      l = m;
    else
      r = m;
  }
  cout << l << endl;

  return 0;
}
