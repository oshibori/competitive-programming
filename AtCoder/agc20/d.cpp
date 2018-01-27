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

  int Q;
  cin >> Q;
  loop(Q) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string ans;
    if (abs(a - b) <= 1) {
      string h, t;
      if (a >= b) {
        if (c & 1) {
          h = "A", t = "B";
        } else
          h = "B", t = "A";
      } else {
        if (c & 1) {
          h = "B", t = "A";
        } else
          h = "A", t = "B";
      }
      rep(i, c, d + 1) {
        if ((i - c) & 1)
          ans += t;
        else
          ans += h;
      }
    }
    else{
      int diff=abs(a-b);
      string s;
      if(a>b){
        :
      }
    }
  }

  return 0;
}
