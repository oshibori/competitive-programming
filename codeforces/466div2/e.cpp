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

  int N, C;
  cin >> N >> C;
  vector<int> a(N);
  rep(i, 0, N) { cin >> a[i]; }
  vector<int> ans(N + 1);
  vector<int> ans2(N + 1);
  {
    priority_queue<int, vector<int>, greater<int>> pq;

    int sum = 0;
    int d = 0;
    rep(i, 0, N) {

      sum += a[i];
      pq.push(a[i]);

      if ((i + 1) / C > d) {
        dump((i + 1), d, (i + 1) / C);
        int t = (i + 1) / C - d;
        loop(t) {
          sum -= pq.top();
          dump(sum, pq.top());
          pq.pop();
        }
        d += t;
      }
      ans[i + 1] += sum;
    }
  }
  dump(ans);
  {
    priority_queue<int, vector<int>, greater<int>> pq;

    int sum = 0;
    int d = 0;
    rrep(i, 0, N) {
      sum += a[i];
      pq.push(a[i]);

      if ((N - i) / C > d) {
        dump((N - i), d, (N - i) / C);
        int t = (N - i) / C - d;
        loop(t) {
          sum -= pq.top();
          dump(sum, pq.top());
          pq.pop();
        }
        d += t;
      }
      ans2[i] += sum;
    }
  }
  dump(ans2);

  vector<int> v(ans);
  rep(i, 0, ans2.size()) v[i] += ans2[i];
  dump(v);
  cout << *min_element(all(v)) << endl;

  return 0;
}
