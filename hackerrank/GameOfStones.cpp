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

vector<int> a(101, -1);
vector<int> b{2, 3, 5};

int f(int x) {
  if (a[x] != -1)
    return a[x];
  rep(i, 0, b.size()) {
    if (f(x - b[i]) == 0) {
      return a[x] = 1;
    }
  }
  return a[x] = 0;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  a[0] = 0;
  a[1] = 0;
  loop(T) {
    int n;
    cin >> n;
    cout << (f(n) ? "First" : "Second") << endl;
  }
  return 0;
}
