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

  string s;
  cin >> s;
  map<char, int> m;
  rep(i, 0, s.size()) { m[s[i]]++; }

  if(m['2']!=m['5']){
    cout<<-1<<endl;
    return 0;
  }
  int ans=0;
  while(!s.empty()){
    string t;
    bool two=true;;
    if(s[0]!='2'){
      cout<<-1<<endl;
      return 0;
    }
    rep(i,0,s.size()){
      if(two and s[i]=='2'){
        two=false;
        continue;
      }
      else if(!two and s[i]=='5'){
        two=true;
        continue;
      }

      t.push_back(s[i]);
    }
    s=t;
    ans++;
  }
  cout<<ans<<endl;

  return 0;
}
