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

  int N;
  cin >> N;
  vector<int> v(N);
  rep(i, 0, N) { cin >> v[i]; }
  vector<pair<int, int>> a;
  rep(i, 0, N) {
    int j = 0;
    while (i + j + 1 < N and v[i + j] == v[i + j + 1])
      j++;
    a.push_back(make_pair(v[i], j + 1));
    i += j;
  }
  int ans = 0;
  auto calc = [&]() {
    vector<pair<int, int>> b;
    int x = 0;
    while (a[x].second == 0)
      x++;
    b.push_back(a[x]);
    int j = 0;
    rep(i, x + 1, a.size()) {
      if (a[i].second == 0)
        continue;
      if (b[j].first == a[i].first)
        b[j].second += a[i].second;
      else {
        b.push_back(a[i]);
        j++;
      }
    }
    dump(b);
    int i = x;
    while (i < b.size() and b[i].second < 4)
      i++;
    if (i == b.size())
      return;
    int del = b[i].second;
    j = i - 1;
    i = i + 1;
    while (i < b.size() and j >= x and b[i].first == b[j].first and
           b[i].second + b[j].second >= 4) {
      del += b[i].second + b[j].second;
      i++, j--;
    }
    chmax(ans, del);

  };
  dump(a);
  rep(i, 0, a.size()) {
    if (i - 1 >= 0) {
      a[i].second--;
      a[i - 1].second++;
      calc();
      a[i].second++;
      a[i - 1].second--;
    }
    if (i + 1 < a.size()) {
      a[i].second--;
      a[i + 1].second++;
      calc();
      a[i].second++;
      a[i + 1].second--;
    }
  }
  cout << N - ans << endl;

  return 0;
}
