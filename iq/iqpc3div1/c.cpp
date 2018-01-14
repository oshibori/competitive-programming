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

  int N, K;
  cin >> N >> K;
  map<int, int> m;
  vector<int> a(N);
  rep(i, 0, N) {
    cin >> a[i];
    m[a[i]]++;
  }

  sort(all(a));
  a.erase(unique(all(a)), a.end());
  N = a.size();
  int ans = 0;
  int sum = 0;
  int l = 0, r = 0;
  while (r < N) {
    while (r < N and sum <= K) {
      sum += m[a[r++]];
      if (sum <= K)
        chmax(ans, sum);
    }
    while (l < r and sum > K) {
      sum -= m[a[l++]];
    }
    if (sum <= K)
      chmax(ans, sum);
}
cout << ans << endl;

return 0;
}
