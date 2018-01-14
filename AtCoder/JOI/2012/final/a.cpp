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
  int k = 0, i = 0, N = s.size();
  while (i < N) {
    int J = 0, O = 0, I = 0;

    int b = i;
    while (i < N and s[i] == 'J')
      i++;
    J = i - b;

    b = i;
    while (i < N and s[i] == 'O')
      i++;
    O = i - b;

    b = i;
    while (i < N and s[i] == 'I')
      i++;
    I = i - b;

    int m=min(J,min(O,I));
    if(m==O)chmax(k,m);
  }
  cout<<k<<endl;

  return 0;
}
