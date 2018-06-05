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
int f(int x, pair<int, int> p) {
  if (p.first <= x and x <= p.second)
    return 0;
  else
    return min(abs(x - p.first), abs(x - p.second));
}
int g(int x, pair<int, int> p) {
  if (abs(x - p.first) <= abs(x - p.second))
    return p.first;
  else
    return p.second;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  vector<int> L(N), R(N);
  rep(i, 0, N) { cin >> L[i] >> R[i]; }
  vector<pair<int, int>> v(N);
  rep(i, 0, N) v[i] = make_pair(L[i], R[i]);
  sort(all(v));
  int x = 0;
  int K = 0;
  int l = 0, r = N - 1;
  loop(N) {
    int a = f(x, v[l]);
    int b = f(x, v[r]);

    dump(x, a, b);
    dump(l, r,K);

    K += max(a, b);
    if(max(a,b)==0)continue;
    if (max(a, b) == a) {
      x = g(x, v[l]);
      l++;
    } else {
      x = g(x, v[r]);
      r--;
    }
    dump(x, a, b);
    dump(l, r,K);
  }
  K += abs(x);
  cout << K << endl;

  return 0;
}
