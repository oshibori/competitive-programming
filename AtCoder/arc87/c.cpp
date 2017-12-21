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

vector<string>s;
int N,L;

int solve(int d,vector<int>v){
  if(false){
    cerr<<"d: "<<d<<endl;
    cerr<<"v.size()"<<v.size()<<endl;
    rep(i,0,v.size()){
      cerr<<v[i]<<" ";
    }
    cerr<<endl<<endl;
  }

  if(!(d<L))return 0;
  
  if(v.size()==0)return 1;

  else if(v.size()==1&&s[v[0]].size()==d)return 0;

  vector<int>l,r;
  rep(i,0,v.size()){
    int index=v[i];
    if(s[index][d]=='0'){
      l.push_back(index);
    }
    else {
      r.push_back(index);
    }
  }

  return solve(d+1,l)+solve(d+1,r);
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>N>>L;
  vector<int>v;
  rep(i,0,N){
    string x;cin>>x;
    s.push_back(x);
    v.push_back(i);
  }
  
  int ans=solve(0,v);
  //cout<<"ans: "<<ans<<endl;
  cout<<(ans%2==0 ? "Bob":"Alice")<<endl;

  return 0;
}
