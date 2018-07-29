#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
//typedef __int128_t Int;
#define DBG 1
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define loop(n) rep(loop,(0),(n))
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(12);

  int Q, X; cin >> Q >> X;
  vector<int> A(Q), B(Q); rep(i, 0, Q){ cin >> A[i] >> B[i]; }
  loop(12){
    int a=0;
    rep(i,0,Q){
      if(X>=A[i]){
        chmax(a,B[i]-A[i]);
      }
    }
    X+=a;
  }
  cout<<X<<endl;

    return 0;
}
