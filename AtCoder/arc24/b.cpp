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
  vector<int> c(N);
  rep(i, 0, N) { cin >> c[i]; }
  int b = count(all(c), 1);
  int r = count(all(c), 0);
  if (b == N or r == N) {
    cout << -1 << endl;
    return 0;
  }

  vector<int> v;
  int i = 0;
  while (i < N) {
    int j = 0;
    while (i + j + 1 < N and c[i + j] == c[i + j + 1])
      j++;
    v.push_back(j + 1);
    i += j + 1;
  }
  dump(v);

  int M = v.size();
  if (c[0] == c[N - 1])
    v[0] += v.back(), M--;

  int ans = 0;
  rep(i, 0, M) { chmax(ans, (v[i] + 1) / 2); }
  cout << ans << endl;

  return 0;
}
