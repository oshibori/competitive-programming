#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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
  vector<int> a(N * 3);
  rep(i, 0, N * 3) { cin >> a[i]; }

  // first->sum, second->pq
  pair<int, priority_queue<int, vector<int>, greater<int>>> p;
  pair<int, priority_queue<int, vector<int>, less<int>>> q;

  vector<int> b(N + 1), c(N + 1);

  rep(i, 0, N) {
    p.first += a[i];
    p.second.push(a[i]);
  }
  b[0] = p.first;
  rep(i, 0, N) {
    p.first += a[N + i];
    p.second.push(a[N + i]);
    int x = p.second.top();
    p.second.pop();
    p.first -= x;
    b[i + 1] = p.first;
  }
  rep(i, 2 * N, 3 * N) {
    q.first += a[i];
    q.second.push(a[i]);
  }
  c[N] = q.first;
  rep(i, 0, N) {
    q.first += a[2 * N - 1 - i];
    q.second.push(a[2 * N - 1 - i]);
    int x = q.second.top();
    q.second.pop();
    q.first -= x;
    c[N - 1 - i] = q.first;
  }
  dump(b, c);
  int ans = -INF;
  rep(i, 0, N + 1) chmax(ans, b[i] - c[i]);
  cout << ans << endl;

  return 0;
}
