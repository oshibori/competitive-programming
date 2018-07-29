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

  int N, M, P;
  cin >> N >> M >> P;
  vector<int> h(N);
  rep(i, 0, N) { cin >> h[i]; }
  vector<int> a(M), c(M);
  vector<string> t(M);
  rep(i, 0, M) { cin >> t[i] >> a[i] >> c[i]; }
  sort(all(h));

  auto f = [&](int n) {
    vector<int> x(n);
    rep(i, 0, n) x[i] = h[i];
    vector<pair<int, int>> all, single;
    rep(i, 0, M) {
      if (t[i] == "all") {
        all.push_back(make_pair(a[i], c[i]));
      } else {
        all.push_back(make_pair(a[i], c[i] * n));
      }
      single.push_back((make_pair(a[i], c[i])));
    }

    // all
    vector<int> dp(P + 1, 0);
    rep(i, 0, M) {
      rep(j, all[i].second, P + 1) {
        chmax(dp[j], dp[j - all[i].second] + all[i].first);
      }
    }

    // single
    vector<int> dp2(h[n - 1] + 1, INF);
    dp2[0] = 0;
    rep(i, 0, M) {
      rep(j, single[i].first, h[n - 1] + 1) {
        chmin(dp2[j], dp2[j - single[i].first] + single[i].second);
      }

      if (i == M - 1) {
        rrep(j, 1, dp2.size()) { chmin(dp2[j - 1], dp2[j]); }
      }
    }

    dump(all);
    dump(dp);
    dump(single);
    dump(dp2);

    int ret = 0;
    rep(p, 0, P + 1) {
      int cnt = 0;
      int remain = P - p;
      rep(i, 0, n) {
        if (x[i] > dp[p]) {
          remain -= dp2[x[i] - dp[p]];

          if (remain < 0)
            break;
        }

        cnt++;
      }
      chmax(ret, cnt);
    }
    return ret;

  };

  cout << f(N) << endl;

  return 0;
}
