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

  int n, a, b;
  cin >> n >> a >> b;
  if(abs(b-a)%2){
    cout<<"Borys"<<endl;
  }
  else cout<<"Alice"<<endl;
  /*
  int i;
  for (i = 0; abs(a - b) > 1; i++) {
    if (i & 1)
      b--;
    else
      a++;
    dump(a,b);
  }
  while (a!=1 and b!=n) {
    if(i&1){
      if(a==b-1)b++;
      else b--;
    }
    else{
      if(a==b-1)a--;
      else a++;
    }
    i++;
    dump(a,b);
  }
  cout<<(a==1?"Borys":"Alice")<<endl;
  */
  /*
  if (n & 1) {
    int m = (n + 1) / 2;
    if (abs(a - 1) >= abs(b - n)) {
      cout << "Alice" << endl;
    } else
      cout << "Borys" << endl;
  } else {
    int m1 = n / 2;
    int m2 = n / 2 + 1;
    if (abs(a - 1) > abs(b - n)) {
      cout << "Alice" << endl;
    }
    else {
      cout << "Borys" << endl;
    }

  }
  */

  return 0;
}
