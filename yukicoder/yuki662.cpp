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
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int Q;
  cin >> Q;
  int N = 5000;
  vector<int> T(N);
  T[0] = T[1] = T[2] = 0;
  T[3] = 1;
  map<vector<int>, int> s;
  //  s[vector<int>{0, 0, 0, 1}] = 3;

  rep(i, 4, N) {
    dump(i);
    T[i] = (T[i - 1] + T[i - 2] + T[i - 3] + T[i - 4]) % 17;
    vector<int> v{T[i], T[i - 1], T[i - 2], T[i - 3]};
    if (s[v] != 0) {
      dump(s[v]);
    }
    s[v] = i;
  }
  dump(T);
  loop(Q) {
    int x;
    cin >> x;
    x--;
    cout << T[x % 4912] << endl;
  }

  return 0;
}
