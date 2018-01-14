#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
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

  int N, M, T, X, Y;
  cin >> N >> M >> T >> X >> Y;
  vector<int> p(M),score(N,0);
  rep(i, 0, M) { cin >> p[i]; }
  vector<int> t(Y), n(Y), m(Y);
  vector<string> s(Y);
  rep(i, 0, Y) {
    cin >> t[i] >> n[i] >> m[i] >> s[i];
    n[i]--;
    m[i]--;
  }
  vector<vector<int>>S(N,vector<int>(M));
  vector<vector<int>>w(S),E(S);

  rep(i,0,Y){
    if(s[i]=="open"){
      S[n[i]][m[i]]=t[i];
    }
    else if(s[i]=="correct"){
      score[n[i]]+=max(p[m[i]]-(t[i]-S[n[i]][m[i]])-120*w[n[i]][m[i]],X);
    }
    else {
      w[n[i]][m[i]]++;
    }
  }

  rep(i,0,N)cout<<score[i]<<endl;


  return 0;
}
