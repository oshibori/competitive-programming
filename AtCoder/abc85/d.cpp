#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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

  int N, H;
  cin >> N >> H;
  vector<int> a(N), b(N);
  rep(i, 0, N) { cin >> a[i] >> b[i]; }
  sort(all(a));
  sort(all(b));
  int ans = 0;
  int i = N - 1;
  while (H) {
    if (i >= 0 and a[N - 1] < b[i])
      H = max(0ll, H - b[i--]);
    else {
      ans += (H + a[N - 1] - 1) / a[N - 1];
      break;
    }
    ans++;
  }
  cout << ans << endl;

  return 0;
}