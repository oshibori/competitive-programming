//#include <bits/stdc++.h>
// utility
#include <bitset>
#include <tuple>
// error handling
#include <cassert>
// string
#include <cctype>
#include <cstring>
#include <string>
// container
#include <array>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// algorithm
#include <algorithm>
// iterator
#include <iterator>
// math
#include <cmath>
#include <complex>
#include <numeric>
#include <random>
// i/o
#include <cstdio>
#include <iomanip>
#include <iostream>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
typedef __int128_t Int;
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
template <typename T, typename S>
istream &operator>>(istream &is, pair<T, S> &p) {
  is >> p.first >> p.second;
  return is;
}
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
vector<vector<int>> dp;
int rev(int x) {
  string s = to_string(x);
  reverse(all(s));
  return stoi(s);
}
int dfs(int x, int y) {
  if (dp[x][y] == 0 or dp[x][y] == 1)
    return dp[x][y];
  if (x == 0 or y == 0) {
    return dp[x][y] = 0;
  }

  if (dp[x][y] == 2) {
    return dp[x][y] = 1;
  }
  dp[x][y] = 2;
  int p=x,q=y;

  if (x < y) {
    x = rev(x);
  } else
    y = rev(y);

  if (x < y) {
    y -= x;
  } else {
    x -= y;
  }
  return dp[p][q] = dfs(x, y);
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, M;
  cin >> N >> M;
  dp.assign(1000, vector<int>(1000, -1));

  int ans = 0;
  rep(i, 1, N + 1) rep(j, 1, M + 1) {
    if (dfs(i, j))
      ans++;
  }
  cout << ans << endl;

  return 0;
}
