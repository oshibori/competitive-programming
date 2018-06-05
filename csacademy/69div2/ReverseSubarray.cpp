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
  vector<int> a(N);
  rep(i, 0, N) { cin >> a[i]; }
  a.push_back(INF);
  vector<int> d;
  int i = 0, p, q;
  while (i < N) {
    int j = 0;
    bool f = false;
    while (i + j + 1 < N and a[i + j] >= a[i + j + 1]) {
      f |= a[i + j] > a[i + j + 1];
      j++;
    }
    if (f) {
      d.push_back(j + 1);
      p = i;
      q = i + j;
    }
    i += j + 1;
  }
  dump(d);
  if (d.size() == 0) {
    map<int, int> m;
    rep(i, 0, a.size() - 1) { m[a[i]]++; }
    int ans = 0;
    for (auto o : m) {
      ans += (o.second + 1) * o.second / 2;
    }
    cout << ans << endl;
    cout << 1 << " " << 1 << endl;
    return 0;
  } else if (d.size() >= 2) {
    cout << 0 << endl;
    return 0;
  } else {
    p = q;
    while (p - 1 >= 0 and a[p - 1] >= a[p])
      p--;
    dump(p, q);
    reverse(a.begin() + p, a.begin() + q + 1);
    dump(a);
    rep(i, 1, N) {
      if (a[i - 1] > a[i]) {
        cout << 0 << endl;
        return 0;
      }
    }
    cout << 1 << endl;
    cout << p + 1 << " " << q + 1 << endl;
  }

  return 0;
}
