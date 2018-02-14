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

  int N; cin >> N;
  vector<string> v(N); rep(i, 0, N){ cin >> v[i]; }
  vector<int>ans;
  rep(i,0,N){
    set<string>s;
    rep(j,0,N){
      if(j==i)continue;
      rep(k,0,N){
        if(k==i or k==j)continue;
        s.insert(v[j]+v[k]);
      }
    }
    if(s.count(v[i]))ans.push_back(i);
  }

  rep(i,0,ans.size())cout<<ans[i]<<(i==ans.size()-1?'\n':' ');

    return 0;
}
