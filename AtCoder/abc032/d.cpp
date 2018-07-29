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

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, W;
  cin >> N >> W;
  vector<int> v(N), w(N);
  rep(i, 0, N) { cin >> v[i] >> w[i]; }
  if (N <= 30) {

    dump(1);
    int n = N / 2, m = N - n;
    vector<pair<int, int>> x, y;
    for (int bits = 0; bits < (1 << n); bits++) {
      pair<int, int> p;
      rep(i, 0, n) {
        if ((bits >> i) & 1) {
          p.second += v[i];
          p.first += w[i];
        }
      }
      x.push_back(p);
    }
    for (int bits = 0; bits < (1 << m); bits++) {
      pair<int, int> p;
      rep(i, 0, m) {
        if ((bits >> i) & 1) {
          p.second += v[n + i];
          p.first += w[n + i];
        }
      }
      y.push_back(p);
    }
    y.push_back(make_pair(INF,INF));
    sort(all(y));
    dump(x,y);
    int b = 0;
    rep(i, 1, y.size()) {
      if (y[b].second <= y[i].second)
        y[++b] = y[i];
    }
    dump(y);

    int ans = 0;
    rep(i, 0, x.size()) {
      if (W - x[i].first >= 0) {
        auto p = *prev(upper_bound(y.begin(), y.begin() + b,
                                   make_pair(W - x[i].first, INF)));

        dump(x[i],p);
        chmax(ans, x[i].second + p.second);
      }
    }
    cout << ans << endl;

  } else if (*max_element(all(w)) <= 1000) {
    dump(2);
    chmin(W, accumulate(all(w), 0ll));
    vector<int> dp(W + 1);
    dp[0] = 0;
    rep(i, 0, N) {
      rrep(j, w[i], W + 1) { chmax(dp[j], dp[j - w[i]] + v[i]); }
    }
    cout << dp[W] << endl;

  } else {
    dump(3);
    int V = accumulate(all(v), 0ll);
    vector<int> dp(V + 1, INF);
    dp[0] = 0;
    rep(i, 0, N) {
      rrep(j, v[i], V + 1) { chmin(dp[j], dp[j - v[i]] + w[i]); }
    }
    int ans = 0;
    rep(i, 0, V + 1) {
      if (dp[i] <= W)
        chmax(ans, i);
    }
    cout << ans << endl;
  }

  return 0;
}
