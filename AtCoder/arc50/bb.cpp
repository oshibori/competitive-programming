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

  int R, B;
  cin >> R >> B;
  int x, y;
  cin >> x >> y;
/*
  int w = max(0ll, (R - B * x) / (1 - x * y));
  dump(R - B * x, 1 - x * y);
  int v = max(0ll, B - w * y);

  dump(w, v);
  cout << w + v << endl;
*/

  int low=0,high=min(R,B)+1;
  while(high-low>1){
    int mid=(high+low)/2;
    bool f = (R-mid)/(x-1)+(B-mid)/(y-1)>=mid;
    if(f)low=mid;
    else high=mid;
  }
  cout<<low<<endl;
  return 0;
}
