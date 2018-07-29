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
struct Cake {
  int x, y, z;
  int value() { return (x) + (y) + (z); }
  Cake() { x = y = z = 0; }
};
bool operator<(Cake a, Cake b) { return a.value() < b.value(); }
Cake operator+(Cake a, Cake b) {
  Cake c;
  c.x = a.x + b.x;
  c.y = a.y + b.y;
  c.z = a.z + b.z;
  return c;
}
Cake operator-(Cake a) {
  a.x = -a.x;
  a.y = -a.y;
  a.z = -a.z;
  return a;
}
istream &operator>>(istream &is, Cake &a) {
  is >> a.x >> a.y >> a.z;
  return is;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, M;
  cin >> N >> M;
  vector<Cake> v(N);
  rep(i, 0, N) { cin >> v[i]; }

  vector<Cake> ans;
  rep(bits, 0, 8) {
    sort(all(v), [&](Cake a, Cake b) {
      if (bits & 1) {
        a.x = -a.x;
        b.x = -b.x;
      }
      if ((bits >> 1) & 1) {
        a.y = -a.y;
        b.y = -b.y;
      }
      if ((bits >> 2) & 1) {
        a.z = -a.z;
        b.z = -b.z;
      }
      return a.value() < b.value();
    });

    Cake x;
    rep(i, N - M, N) x = x + v[i];
    ans.push_back(x);
  }
  cout << (*max_element(all(ans))).value() << endl;
  /*
    vector<Cake> ans(6);
    sort(all(v), [](Cake a, Cake b) { return abs(a.x) < abs(b.x); });
    rep(i, 0, M) ans[0] = ans[0] + v[i];
    rep(i, N - M, N) ans[1] = ans[1] + v[i];
    sort(all(v), [](Cake a, Cake b) { return abs(a.y) < abs(b.y); });
    rep(i, 0, M) ans[2] = ans[2] + v[i];
    rep(i, N - M, N) ans[3] = ans[3] + v[i];
    sort(all(v), [](Cake a, Cake b) { return abs(a.z) < abs(b.z); });
    rep(i, 0, M) ans[4] = ans[4] + v[i];
    rep(i, N - M, N) ans[5] = ans[5] + v[i];
    cout << (*max_element(all(ans))).value() << endl;
  */
  return 0;
}
