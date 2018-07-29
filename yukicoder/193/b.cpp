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

string f(vector<int>&v){
  int n=v.size();
  rep(i,0,n-1){
    v[i+1]+=v[i]/26;
    v[i]%=26;
  }
  string ret;
  ret.resize(n);
  rep(i,0,n){
    ret[i]=(char)('a'+v[i]);
  }
  v[0]++;
  return ret;

}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(12);

  int N; cin >> N;
  vector<int>v(18);
  rep(i,0,N-1){
    cout<<"a"+f(v)+"a"<<endl;
  }
  cout<<"an"<<endl;

    return 0;
}
