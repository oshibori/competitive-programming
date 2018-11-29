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
using pii = pair<int, int>;
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

  int K;
  cin >> K;
  int dx[] = {0, 1, 0, 1}, dy[] = {0, 0, 1, 1};

  auto f = [&](int X) {

    auto dist = [&](double x, double y) {
      return sqrt(abs(x - X / 2) * abs(x - X / 2) +
                  abs(y - X / 2) * abs(y - X / 2));

    };
    int ret = 0;
    rep(i, 0, X / K) {
      rep(j, 0, X / K) {
        double px = i * K, py = j * K;
        bool f = true;
        rep(l, 0, 4) { f &= dist(px + dx[l] * K, py + dy[l]*K) <= X / 2; }
        ret += f;
      }
    }
    return ret;
  };

  cout << f(200) << " " << f(300) << endl;

  return 0;
}
