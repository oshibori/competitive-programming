#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
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
using pii = pair<int, int>;
// template<class T> ostream &operator<<(ostream &os,T &t){dump(t);return os;}
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
  cout << fixed << setprecision(12);

  int K;
  cin >> K;
  string S;
  cin >> S;

  if (S.size() % 2 == 0) {
    cout << "NG" << endl;
    return 0;
  }

  map<char, int> mp;
  for (auto c : S) {
    mp[c]++;
  }

  int op = mp['+'] + mp['-'], num = S.size() - op;

  if (abs(num - op + 1) > K) {
    cout << "NG" << endl;
    return 0;
  }

  stack<int>st;
  rep(i,0,S.size()){
    if(isdigit(S[i])){
      st.push(S[i]);
    }
    else{

    }
  }

  return 0;
}
