#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

vector<int>a,b;
int x,y;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;cin>>s;
  cin>>x>>y;

  int i=0;
  int turn=0;
  while(i<s.size()){
    int c=0;
    while(i+c<s.size()&&s[i+c]=='F'){
      c++;
    }
    if(turn%2==0){
      a.push_back(c);
    }
    else{
      b.push_back(c);
    }
    i+=c+1;
    turn++;
  }

  if(false){
    cerr<<"a: ";
    rep(i,0,a.size()){
      cerr<<a[i]<<(i==a.size()-1?'\n':' ');
    }
    cerr<<"b: ";
    rep(i,0,b.size()){
      cerr<<b[i]<<(i==b.size()-1?'\n':' ');
    }
  }

  set<int>set_a;
  set_a.insert(a[0]);
  rep(i,1,a.size()){
    set<int>t;
    for(auto &d:set_a){
      t.insert(d+a[i]);
      t.insert(d-a[i]);
    }
    set_a=t;
  }

  if(false){
    for(auto d:set_a){
      cerr<<d<<endl;
    }
  } 

  set<int>set_b;
  set_b.insert(0);
  rep(i,0,b.size()){
    set<int>t;
    for(auto &d:set_b){
      t.insert(d+b[i]);
      t.insert(d-b[i]);
    }
    set_b=t;
  }
  if(false){
    for(auto d:set_b){
      cerr<<d<<endl;
    }
  } 

  if(set_a.count(x)&&set_b.count(y)){
    cout<<"Yes"<<endl;
  }
  else cout<<"No"<<endl;
  return 0;
}
