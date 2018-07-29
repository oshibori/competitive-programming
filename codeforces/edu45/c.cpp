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
bool fzero(string s){
  stack<char>st;
  rep(i,0,s.size()){
    if(s[i]=='(')st.push(s[i]);
    else {
      if(st.empty())return false;
      else st.pop();
    }
  }
  return true;
}
bool fone(string s){
  stack<char>st;
  rrep(i,0,s.size()){
    if(s[i]==')')st.push(s[i]);
    else {
      if(st.empty())return false;
      else st.pop();
    }
  }
  return true;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  vector<string> v(N);
  rep(i, 0, N) { cin >> v[i]; }
  vector<int> p(N);
  map<int, int> m;
  rep(i, 0, N) {
    int l = count(all(v[i]), '(');
    int r = count(all(v[i]), ')');
    dump(l, r);
    p[i] = l - r;

    bool h=fzero(v[i]);
    bool g=fone(v[i]);

    if(p[i]==0 and (!h or !g)){
      continue;
    }
    else if(p[i]!=0 and !h and !g){
      continue;

    }
    m[p[i]]++;
  }
  dump(m);

  int ans = 0;
  for (auto x : m) {
    if (x.first < 0)
      continue;

    ans += x.second * m[-x.first];
  }

  cout << ans << endl;

  return 0;
}
