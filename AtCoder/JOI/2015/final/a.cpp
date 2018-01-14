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

  int N, M;
  cin >> N >> M;
  vector<int> p(M);
  rep(i, 0, M) { cin >> p[i]; }
  vector<int> l(N + 2, 0), r(N + 2, 0);
  vector<int> v(N + 2, 0);

  rep(i, 0, M - 1) {
    if (p[i] < p[i + 1]) {
      l[p[i]]++;
      l[p[i + 1]]--;
    } else {
      r[p[i]]++;
      r[p[i + 1]]--;
    }
  }
  rep(i, 1, N + 2) l[i] += l[i - 1];
  rrep(i, 0, N + 1) r[i] += r[i + 1];
  dump(l);
  dump(r);

  int ans = 0;
  vector<int> a(N + 1), b(N + 1), c(N + 1);
  rep(i, 1, N) cin >> a[i] >> b[i] >> c[i];

  rep(i, 1, N ) {
    int buy = 0, no = 0;
    int t=l[i]+r[i+1];
    buy+=b[i]*t+c[i];
    no+=a[i]*t;
    ans += min(buy, no);
  }
  cout << ans << endl;

  return 0;
}
