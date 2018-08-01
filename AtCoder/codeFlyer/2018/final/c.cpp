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

  string S;
  cin >> S;
  vector<string> v;
  vector<int> check(S.size());
  stack<int> st;
  rep(i, 0, S.size()) {
    if (S[i] == ')' and !st.empty()) {
      int p = st.top();
      st.pop();
      check[p] = check[i] = true;
    } else if (S[i] == '(') {
      st.push(i);
    }
  }
  dump(check);
  auto f = [](string s) {

    int ret = 0;
    stack<int> st;
    int x = 0;
    rep(i, 0, s.size()) {
      if (s[i] == '(') {
        st.push(x);
        x = 0;
      } else {
        ret += x * (x + 1) / 2;
        x = st.top();
        x++;
        st.pop();
      }
    }
    return ret += x * (x + 1) / 2;
  };
  int ans = 0;
  rep(i, 0, S.size()) {
    while (i < S.size() and !check[i])
      i++;
    int j = i;
    while (i < S.size() and check[i])
      i++;

    dump(i,j,S.substr(i,j-i));
    ans += f(S.substr(j, i - j));
  }
  cout << ans << endl;

  return 0;
}
