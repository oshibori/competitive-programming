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
struct Cake {
  int x, y, z;
  int value() { return (x) + (y) + (z); }
  Cake() { x = y = z = 0; }
};
bool operator<(Cake a, Cake b) { return a.value() < b.value(); }
Cake operator+(Cake a, Cake b) {
  Cake c;
  c.x = a.x + b.x;
  c.y = a.y + b.y;
  c.z = a.z + b.z;
  return c;
}
Cake operator-(Cake a) {
  a.x = -a.x;
  a.y = -a.y;
  a.z = -a.z;
  return a;
}
istream &operator>>(istream &is, Cake &a) {
  is >> a.x >> a.y >> a.z;
  return is;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, M;
  cin >> N >> M;
  vector<int> x(N), y(N),z(N); rep(i, 0, N){ cin >> x[i] >> y[i]>>z[i]; }
  int ans=-INF;
  rep(bits,0,8){
    vector<int>v(N);
    rep(i,0,N){
      int a=x[i];
      if(bits&1)a=-a;
      v[i]+=a;
      a=y[i];
      if((bits>>1)&1)a=-a;
      v[i]+=a;
      a=z[i];
      if((bits>>2)&1)a=-a;
      v[i]+=a;
    }
    sort(all(v));
    chmax(ans,accumulate(v.end()-M,v.end(),0ll));
  }
  cout<<ans<<endl;

  return 0;
}
