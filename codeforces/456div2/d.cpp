#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
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

  int N, M, R, K;
  cin >> N >> M >> R >> K;
  int n = N / 2, m = M / 2;
  vector<int> v;
  auto f = [&](int a, int b) {
    a--,b--;
    int x = min(max(a - R, 0), R);
    int y = min(max(b - R, 0), R);
    return x * y;
  };
  rep(i, 1, n + 1) rep(j, 1, m + 1) {
    dump(f(i,j))
    loop(4) v.push_back(f(i,j));
  }
  if (N & 1) {
    rep(i, 1, M) v.push_back(f(n + 1, i));
  }
  if (M & 1) {
    rep(i, 1, N) v.push_back(f(i, m + 1));
  }
  sort(all(v), greater<int>());
  double ans = 0;
  rep(i, 0, K) ans += v[i];
  ans /= (N - R + 1) * (M - R + 1);

  cout << ans << endl;

  return 0;
}
