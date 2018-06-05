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

  int N, A, B;
  cin >> N >> A >> B;
  vector<int> P(N);
  rep(i, 0, N) P[i] = i;

  int x = 0, y = -1;
  while (0 <= N - A * x) {
    if ((N - A * x) % B == 0 and (N - A * x) / B >= 0) {
      y = (N - A * x) / B;
      break;
    }
    x++;
  }
  if (y == -1) {
    cout << -1 << endl;
    return 0;
  }

  rep(i, 0, x) {
    int s = i * A;
    rep(j, 0, A - 1) { swap(P[s + j], P[s + (j + 1) % A]); }
  }

  rep(i, 0, y) {
    int s = i * B + A * x;
    rep(j, 0, B - 1) { swap(P[s + j], P[s + (j + 1) % B]); }
  }

  rep(i, 0, N) cout << P[i] + 1 << (i == N - 1 ? '\n' : ' ');

  return 0;
}
