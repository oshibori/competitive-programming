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

bool check(vector<int> a, int m) {
  vector<int> x(a.begin(), a.begin() + m);
  vector<int> y(a.end() - m, a.end());
  sort(all(x));
  sort(all(y));
  return x == y;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, 0, N) { cin >> a[i]; }
  int k = 0;
  vector<int> ans;
  ans.push_back(N);

  while (k < (N + 1) / 2) {
    int l = k, r = N - 1 - k, u, t;
    dump(k, l, r);
    for (u = 0; a[l] != a[r - u]; u++)
      ;
    for (t = 0; a[l + t] != a[r]; t++)
      ;
    dump(u, t);
    int m = max(u, t) + 1;
    dump(m);
    k += m;
    if (check(a, k)) {
      ans.push_back(k);
    }
    dump(k);
  }
  for (auto x : ans) {
    if (N - x > 0 and N - x < N)
      ans.push_back(N - x);
  }
  sort(all(ans));
  ans.erase(unique(all(ans)), ans.end());
  rep(i, 0, ans.size()) cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');

  return 0;
}
