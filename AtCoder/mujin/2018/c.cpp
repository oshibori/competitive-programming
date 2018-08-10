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

#define int long long
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

void print(vector<vector<int>> &v) {
  cout << endl;
  rep(i, 0, v.size()) {
    rep(j, 0, v[i].size()) {
      cout << v[i][j] << (j == v[i].size() - 1 ? '\n' : ' ');
    }
  }
  cout << endl;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, M;
  cin >> N >> M;
  vector<vector<char>> S(N + 2, vector<char>(M + 2));
  rep(i, 0, S.size()) {
    S[i][0] = '#';
    S[i][M + 1] = '#';
  }
  rep(i, 0, S[0].size()) {
    S[0][i] = '#';
    S[N + 1][i] = '#';
  }
  rep(i, 1, N + 1) rep(j, 1, M + 1) { cin >> S[i][j]; }

  vector<vector<int>> right(N + 2, vector<int>(M + 2)), left(right), up(right),
      down(right);
  rep(i, 0, N + 2) {
    rrep(j, 0, M + 2) {
      if (S[i][j] == '#')
        right[i][j] = j;
      else
        right[i][j] = right[i][j + 1];
    }
  }

  rep(j, 0, M + 2) {
    rrep(i, 0, N + 2) {
      if (S[i][j] == '#')
        down[i][j] = i;
      else
        down[i][j] = down[i + 1][j];
    }
  }

  rep(i, 0, N + 2) {
    rep(j, 0, M + 2) {
      if (S[i][j] == '#')
        left[i][j] = j;
      else
        left[i][j] = left[i][j - 1];
    }
  }

  rep(j, 0, M + 2) {
    rep(i, 0, N + 2) {
      if (S[i][j] == '#')
        up[i][j] = i;
      else
        up[i][j] = up[i - 1][j];
    }
  }

  vector<vector<int>> zero(N + 2, vector<int>(M + 2, 0));
  vector<vector<int>> right_sum(zero), down_sum(zero), left_sum(zero),
      up_sum(zero);

  rep(i, 1, N + 1) {
    rep(j, 1, M + 1) {
      right_sum[i][j] =
          max(0ll, abs(down[i][j] - i) - 1) + (j > 0 ? right_sum[i][j - 1] : 0);
    }
  }
  rep(i, 1, N + 1) {
    rep(j, 1, M + 1) {
      left_sum[i][j] =
          max(0ll, abs(up[i][j] - i) - 1) + (j > 0 ? left_sum[i][j - 1] : 0);
    }
  }

  rep(j, 1, M + 1) {
    rep(i, 1, N + 1) {
      down_sum[i][j] =
          max(0ll, abs(left[i][j] - j) - 1) + (i > 0 ? down_sum[i - 1][j] : 0);
    }
  }
  rep(j, 1, M + 1) {
    rep(i, 0, N + 1) {
      up_sum[i][j] =
          max(0ll, abs(right[i][j] - j) - 1) + (i > 0 ? up_sum[i - 1][j] : 0);
    }
  }


  int ans = 0;

  rep(i, 1, N + 1) rep(j, 1, M + 1) {
    int x = right[i][j] - 1;
    ans += right_sum[i][x] - right_sum[i][j];
    int y = down[i][j] - 1;
    ans += down_sum[y][j] - down_sum[i][j];
    int z = left[i][j];
    ans += left_sum[i][j - 1] - left_sum[i][z];
    int w = up[i][j];
    ans += up_sum[i - 1][j] - up_sum[w][j];
  }
  cout << ans << endl;
  return 0;
}
