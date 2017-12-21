#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
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

  int N;cin>>N;
  vector<int>a(N);
  rep(i,0,N)cin>>a[i];

  vector<int>big,small;
  vector<pair<int,int>>ans;
  rep(i,0,N){
    if(a[i]>=0){
      big.push_back(i);

    }
    else{
      small.push_back(i);
    }
  }

  auto b=max_element(all(a)),s=min_element(all(a));

  if(abs(*b)>abs(*s)){
    int index=distance(a.begin(),b);
    rep(i,0,N){
      ans.push_back(make_pair(index,i));
    }
    rep(i,1,N){
      ans.push_back(make_pair(i-1,i));
    }
  }

  else{
    int index=distance(a.begin(),s);
    rep(i,0,N){
      ans.push_back(make_pair(index,i));
    }
    rrep(i,1,N){
      ans.push_back(make_pair(i,i-1));
    }
  }

  cout<<ans.size()<<endl;
  rep(i,0,ans.size()){
    cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
  }


  return 0;
}
