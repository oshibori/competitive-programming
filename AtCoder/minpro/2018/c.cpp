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
typedef pair<int, int> P;
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  vector<int> x(N);
  rep(i, 0, N) { cin >> x[i]; }
  vector<int> c(N);
  rep(i, 0, N) { cin >> c[i]; }
  vector<int> v(N);
  rep(i, 0, N) { cin >> v[i]; }
  rep(i, 1, N) x[i] += x[i - 1];

  vector<pair<int, int>> p,b;
  for (int bits = 0; bits < (1 << N); bits++) {
    int cost = 0, value = 0;
    rep(i, 0, N) {
      if ((bits >> i) & 1) {
        cost += c[i];
        value += v[i];
      }
    }
    p.push_back(make_pair(cost, value));
  }
  sort(all(p));




  int ans = 0;
  rep(i, 0, N) {
    auto u = upper_bound(all(p), P(x[i], INF));
    dump(*u);
    int d = u - p.begin();
    dump(d);
    int index = max(0ll, d - i - 1-1);
    dump(index);
    chmax(ans, p[index].second);
  }
  cout << ans << endl;

  return 0;
}
