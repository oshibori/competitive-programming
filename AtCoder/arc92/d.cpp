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
  vector<int> a(N);
  rep(i, 0, N) { cin >> a[i]; }
  vector<int> b(N);
  rep(i, 0, N) { cin >> b[i]; }

  int ans = 0;

  rep(k,0,29){
    vector<int>c(N),d(N);
    rep(i,0,N){
      c[i]=a[i]%(1<<(k+1));
      d[i]=b[i]%(1<<(k+1));
    }
    sort(all(c));
    sort(all(d));
    dump(c,d);

    rep(i,0,N){
      auto t1=lower_bound(all(d),  (1<<k)-c[i]);
      auto t2=lower_bound(all(d),2*(1<<k)-c[i]);
      auto t3=lower_bound(all(d),3*(1<<k)-c[i]);
      auto t4=lower_bound(all(d),4*(1<<k)-c[i]);

      dump(t1-d.begin());
      dump(t2-d.begin());
      dump(t3-d.begin());
      dump(t4-d.begin());

      int d1=t2-t1 + t4-t3;
      
      ans^=((d1&1)<<k);
      dump(ans);
    }
  }

  cout<<ans<<endl;

  return 0;
}
