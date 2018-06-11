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

  int N, K, Q;
  cin >> N >> K >> Q;
  vector<int> v(N);
  rep(i, 0, N) { cin >> v[i]; }
  int ans = INF;

  rep(i, 0, N) {
    int x = v[i];
    dump(x);
    vector<int> a, b;
    rep(j, 0, N) {
      if (v[j] < x) {
        sort(all(a));
        rep(k, 0, (int)a.size() - K + 1) { b.push_back(a[k]); }
        a.clear();
      } else {
        a.push_back(v[j]);
      }
    }
    sort(all(a));
    rep(k, 0, (int)a.size() - K + 1) { b.push_back(a[k]); }
    a.clear();

    if (b.size() < Q)
      continue;
    sort(all(b));
    dump(b);
    chmin(ans, b[Q - 1] - x);
  }
  cout << ans << endl;

  return 0;
}
