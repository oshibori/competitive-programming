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
  vector<int> v(N);
  rep(i, 0, N) { cin >> v[i]; }
  sort(all(v));
  int n = v.back();
  int r = (n % 2 == 0 ? n / 2 : (n + 1) / 2);

  dump(n, r);

  if (binary_search(all(v), r)) {
    cout << n << " " << r << endl;
    return 0;
  }

  auto small = prev(lower_bound(all(v), r));

  auto big = upper_bound(all(v), r);

  dump(*small, *big);

  if (*big == n) {
    cout << n << " " << *small << endl;
    return 0;
  }

  if (abs(*small - r) < abs(*big - r)) {
    cout << n << " " << *small << endl;
  } else
    cout << n << " " << *big << endl;

  return 0;
}
