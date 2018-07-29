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
using pii = pair<int, int>;
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

  auto me = max_element(all(v));
  if (*me <= 0) {
    cout << *me << endl << N - 1 << endl;
    for (int i = N - 1; i > me - v.begin(); i--)
      cout << i + 1 << endl;
    loop(distance(v.begin(), me)) cout << 1 << endl;
    return 0;
  }

  vector<int> odd, even;
  int odd_sum = 0, even_sum = 0;
  rep(i, 0, N) {
    if (v[i] > 0)
      if (i & 1) {
        odd.push_back(i);
        odd_sum += v[i];
      } else {
        even.push_back(i);
        even_sum += v[i];
      }
  }
  cout << max(odd_sum, even_sum) << endl;
  vector<int> s = (odd_sum < even_sum ? even : odd);
  vector<bool> a(N, 0);
  for (auto e : s) {
    a[e] = 1;
  }

  vector<int> ans;
  auto f = [&](int x) {
    vector<bool> _a;
    if (x == 0) {
      rep(i, 1, a.size()) { _a.push_back(a[i]); }
    } else if (x == a.size() - 1) {
      rep(i, 0, a.size() - 1) { _a.push_back(a[i]); }
    } else {
      rep(i, 0, a.size()) {
        if (i == x - 1 or i == x + 1)
          continue;
        else if (i == x) {
          _a.push_back(a[i - 1]);

        } else
          _a.push_back(a[i]);
      }
    }
    swap(a, _a);
    ans.push_back(x);
  };

  while (a[0] == 0)
    f(0);
  while (a.back() == 0)
    f(a.size() - 1);

  int i = 1;
  while (a.size() > 1) {
    if (a[0] == a[2])
      f(1);
    else
      f(2);
  }

  cout << ans.size() << endl;
  for (auto e : ans)
    cout << e + 1 << endl;

  return 0;
}
