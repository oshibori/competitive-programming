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

  int N;
  cin >> N;
  vector<int> day;
  day.push_back(0);
  rep(i, 1, 13) {
    if (i == 1 or i == 3 or i == 5 or i == 7 or i == 8 or i == 10 or i == 12) {
      day.push_back(31);
    } else if (i == 4 or i == 6 or i == 9 or i == 11) {
      day.push_back(30);
    } else
      day.push_back(29);
  }
  dump(day);
  rep(i, 1, 13) day[i] += day[i - 1];

  vector<int> v(369);
  // 1-> 1/1
  for (int i = 1; i <= 366; i++) {
    if (i % 7 == 1 or i % 7 == 0)
      v[i] = 1;
  }
  auto parse = [&](string s) {
    int l = find(all(s), '/') - s.begin();
    return make_pair(stoi(s.substr(0, l)), stoi(s.substr(l + 1)));
  };
  loop(N) {
    string w;
    cin >> w;
    auto p = parse(w);
    dump(p);
    int d = day[p.first - 1] + p.second;
    while (d <= 366 and v[d]) {
      dump(d, v[d]);
      d++;
    }
    v[d] = 1;
  }
  int i = 1;
  int ans = 0;
  while (i <= 366) {
    int j = 0;
    while (i + j <= 366 and v[i + j])
      j++;
    chmax(ans, j);
    i += j + 1;
  }
  cout << ans << endl;

  return 0;
}
