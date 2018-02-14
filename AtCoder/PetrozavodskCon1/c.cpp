#include <bits/stdc++.h>
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
  int l = 0, r = N - 1;
  vector<string> s(N);
  string res;
  cout << 0 << endl;
  cin >> s[0];

  if (s[0] == "Vacant") {
    return 0;
  }

  loop(19) {
    if (abs(l - r) <= 1) {
      cout << l << endl;
      cin >> res;
      if (res == "Vacant") {
        return 0;
      }
      cout << r << endl;
      cin >> res;
      if (res == "Vacant") {
        return 0;
      }
    }

    dump(l, r);
    int m = (l + r) / 2;

    cout << m << endl;
    cin >> res;
    s[m]=res;
    if (res == "Vacant") {
      return 0;
    }

    if (abs(l - m) % 2 == 0) {
      if (s[l] == res) {
        l = m;
      } else {
        r = m+1;
      }
    } else {
      if (s[l] == res) {
        r = m+1;
      } else {
        l = m;
      }
    }
  }

  return 0;
}
