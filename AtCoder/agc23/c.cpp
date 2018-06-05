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

void paint(vector<int> &a, int x) {
  a[x] = 1;
  if (x + 1 < a.size())
    a[x + 1] = 1;
}
bool all_black(vector<int> &a) {
  for (auto x : a)
    if (x == 0)
      return false;
  return true;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  vector<int> p(N - 1);
  rep(i, 0, N - 1) p[i] = i;
  int score(0);
  map<int, int> mp;

  do {
    vector<int> a(N);
    int turn = 0;
    while (!all_black(a)) {
      paint(a, p[turn]);
      turn++;
    }
    mp[turn]++;
  } while (next_permutation(all(p)));

  for (auto x : mp) {
    score += x.first * x.second;
    dump(x.first, x.second);
  }
  cout<<score<<endl;

  return 0;
}
