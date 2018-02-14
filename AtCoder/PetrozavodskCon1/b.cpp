#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
typedef __int128_t Int;
typedef pair<int, int> P;
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
  vector<int> a(N);
  rep(i, 0, N) { cin >> a[i]; }
  vector<int> b(N);
  rep(i, 0, N) { cin >> b[i]; }
  int x = accumulate(all(b), 0ll) - accumulate(all(a), 0ll);
  dump(x);
  if (x < 0) {
    cout << "No" << endl;
    return 0;
  }

  int A = 0, B = 0;
  rep(i, 0, N) {
    if (a[i] > b[i])
      A += abs(a[i] - b[i]);
    else {
      B += abs(a[i] - b[i]) / 2;
      if (abs(a[i] - b[i]) & 1)
        A++, B++;
    }
  }
  if (A <= B) {
    cout << "Yes" << endl;
  } else
    cout << "No" << endl;

  return 0;
}
