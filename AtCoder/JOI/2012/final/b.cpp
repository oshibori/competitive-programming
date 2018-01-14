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

  int A, B;
  cin >> A >> B;

  vector<int> a(A);
  rep(i, 0, A) { cin >> a[i]; }
  vector<int> b(B);
  rep(i, 0, B) { cin >> b[i]; }

  int l = 0, r = min(A, B) + 1;
  while (r - l > 1) {
    int m = (l + r) / 2;
    dump(m);
    bool f = false;

    rep(i, 0, B - m) {
      vector<int> v(m);
      rep(j, 0, m) v[j] = b[i + j];

      int x = 0, y = 0;
      while (x < m and y < A) {
        if (v[x] == a[y])
          x++, y++;
        else
          y++;
      }
      if (x == m) {
        f = true;
        break;
      }
    }
    if (f)
      l = m;
    else
      r = m;
  }
  cout<<l<<endl;

  return 0;
}
