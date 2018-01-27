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

  int K, N, M;
  cin >> K >> N >> M;
  vector<int> p(K);
  rep(i, 0, K) { cin >> p[i]; }
  p.push_back(-INF);
  vector<int> a(p);
  sort(all(p), greater<int>());
  dump(p);
  int g = (K + 11) / 12 - 1;
  dump(g);
  int plus = (N - M) * 100;
  dump(plus);
  rep(i, 0, K) {
    dump(i, a[i]);
    if (a[i] >= p[g]) {
      if (a[i] >= p[g + 1] + plus)
        cout << i + 1 << endl;
    } else if (a[i] >= p[g] + plus)
      cout << i + 1 << endl;
  }
  cout << "--------" << endl;
  rep(i, 0, K) {
    if (a[i] + plus >= p[g])
      cout << i + 1 << endl;
  }

  return 0;
}
