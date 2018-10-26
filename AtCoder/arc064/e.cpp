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
using pii = pair<int, int>;
// template<class T> ostream &operator<<(ostream &os,T &t){dump(t);return os;}
template <typename T, typename S>
istream &operator>>(istream &is, pair<T, S> &p) {
  is >> p.first >> p.second;
  return is;
}
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
#define fi first
#define se second
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;
  int N;
  cin >> N;
  vector<int> x(N + 2), y(N + 2), r(N + 2);
  x[0] = xs, y[0] = ys, r[0] = 0;
  rep(i, 1, N + 1) { cin >> x[i] >> y[i] >> r[i]; }
  x[N + 1] = xt, y[N + 1] = yt, r[N + 1] = 0;
  dump(x);
  dump(y);
  dump(r);

  auto d = [&](int a, int b) {
    double aa = abs(x[a] - x[b]);
    double bb = abs(y[a] - y[b]);
    double dd = sqrt(aa * aa + bb * bb);
    return max(0.0, dd - r[a] - r[b]);
  };
  vector<int> color(N + 2, 0);
  vector<double> dist(N + 2, 1e30);
  using pdi = pair<double, int>;
  priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
  dist[0] = 0;
  pq.push(pdi(0, 0));
  while (pq.size()) {
    pdi a = pq.top();
    pq.pop();
    if (a.fi > dist[a.se])
      continue;

    color[a.se] = 1;
    rep(i, 0, N + 2) {
      if (i == a.se or color[i])
        continue;
      if (chmin(dist[i], dist[a.se] + d(a.se, i))) {
        pq.push(pdi(dist[i], i));
      }
    }
  }
  cout << dist[N + 1] << endl;

  return 0;
}
