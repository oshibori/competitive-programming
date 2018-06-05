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
  vector<int> sum(a);
  rrep(i, 0, N - 1) { sum[i] += sum[i + 1]; }

  int ans = 0;
  vector<int> x(a);
  rrep(i, 0, N - 1) { x[i] ^= x[i + 1]; }
  dump(x);

  rep(i, 0, N) {
    int l = -1, r = i;

    while (abs(r - l) > 1) {
      int m = (l + r) / 2;
      int c = x[i] ^ x[m];
      dump(l, r, m, c);
      if ((a[i] ^ c) == sum[m] - sum[i] + a[i])
        r = m;
      else
        l = m;
    }

    int y = abs(i - r) + 1;
    ans += y;
    dump(l, r, ans);
  }

  cout << ans << endl;

  /*
    int l = 0, r = 0;
    int ans = 0;
    rep(i,0,N) {


      r=i;
      int x = 0;
      while (r < N and (x & a[r]) == 0) {
        x ^= a[r];
        r++;
      }

      int y = abs(r - i);
      ans += y * (y + 1) / 2;
      dump(l,r,y,ans);
    }
    cout<<ans<<endl;
  */
  return 0;
}
