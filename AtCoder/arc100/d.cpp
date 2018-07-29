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

  int N;
  cin >> N;
  vector<int> v(N + 1);
  rep(i, 1, N + 1) { cin >> v[i]; }
  rep(i, 1, N + 1) v[i] += v[i - 1];

  auto valid = [&](int s, int m, int t) { return abs(v[m] * 2 - v[s] - v[t]); };
  int ans = INF;

  dump(v);

  rep(i, 2, N - 1) {
    // (0,i),(i,N+1)
    int l = 1, r = i;
    while (r - l > 1) {
      int m = (l + r) / 2;
      int x = valid(0, m, i);
      int y = valid(0, m - 1, i);
      int z = valid(0, m + 1, i);

      if (y <= x) {
        r = m;
      } else {
        l = m;
      }
    }

    vector<int> a;
    a.push_back(v[l]);
    a.push_back(v[i] - v[l]);

    l = i + 1, r = N;
    while (r - l > 1) {
      int m = (l + r) / 2;
      int x = valid(i, m, N);
      int y = valid(i, m - 1, N);

      if (y <= x) {
        r = m;
      } else {
        l = m;
      }
    }
    a.push_back(v[l] - v[i]);
    a.push_back(v[N] - v[l]);
    sort(all(a));
    chmin(ans, a[3] - a[0]);
  }
  cout << ans << endl;

  return 0;
}
