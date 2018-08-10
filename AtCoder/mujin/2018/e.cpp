//#include <bits/stdc++.h>
// utility
#include <bitset>
#include <tuple>
#include <typeinfo>
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
#define fi first
#define se second
using pii = pair<int, int>;
// template<class T> ostream &operator<<(ostream &os,T &t){dump(t);return os;}
template <typename T, typename S>
istream &operator>>(istream &is, pair<T, S> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T> void printvv(const vector<vector<T>> &v) {
  cerr << endl;
  rep(i, 0, v.size()) rep(j, 0, v[i].size()) {
    if (typeid(v[i][j]) == typeid(INF) and v[i][j] == INF) {
      cerr << "INF";
    } else
      cerr << v[i][j];
    cerr << (j == v[i].size() - 1 ? '\n' : ' ');
  }
  cerr << endl;
}
#ifndef _DEBUG
#define printvv(...)
#endif
void YES(bool f) { cout << (f ? "YES" : "NO") << endl; }
void Yes(bool f) { cout << (f ? "Yes" : "No") << endl; }
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

  int N, M, K;
  cin >> N >> M >> K;
  string d;
  cin >> d;
  d = d + d;
  string S = "RULD";
  vector<vector<int>> cost(4, vector<int>(d.size()));
  rep(i, 0, S.size()) {
    cost[i].push_back(INF);
    rrep(j, 0, cost[i].size() - 1) {
      if (d[j] == S[i])
        cost[i][j] = 1;
      else
        cost[i][j] = cost[i][j + 1] + 1;
    }
  }
  dump(cost);

  vector<vector<int>> dist(N, vector<int>(M, INF));
  pii start, goal;
  vector<string> v(N);
  rep(i, 0, N) { cin >> v[i]; }
  rep(i, 0, N) rep(j, 0, M) {
    if (v[i][j] == 'S') {
      start = pii(i, j);
    } else if (v[i][j] == 'G') {
      goal = pii(i, j);
    }
  }

  dist[start.fi][start.se] = 0;
  using State = tuple<int, int, int>;
  priority_queue<State, vector<State>, greater<State>> pq;
  int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
  auto inrange = [&](int x, int y) {
    return 0 <= x and x < N and 0 <= y and y < M;
  };
  pq.push(State(0, start.fi, start.se));
  while (pq.size()) {
    int c, x, y;
    tie(c, x, y) = pq.top();
    dump(c, x, y);
    pq.pop();

    if (dist[x][y] < c)
      continue;

    rep(i, 0, 4) {
      int X = x + dx[i], Y = y + dy[i];
      if (inrange(X, Y) and v[X][Y] != '#') {
        int C = c + cost[i][c % K];
        dump(X, Y, C);
        if (chmin(dist[X][Y],  C)) {
          pq.push(State(dist[X][Y], X, Y));
        }
      }
    }
    printvv(dist);
  }

  cout << (dist[goal.fi][goal.se] == INF ? -1 : dist[goal.fi][goal.se]) << endl;

  return 0;
}
