#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
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

  for (int N; cin >> N, N;) {
    vector<int> a(N), index;
    rep(i, 0, N) {
      string s;
      cin >> s;
      if (s == "x")
        index.push_back(i);
      else
        a[i] = stoi(s);
    }

    rep(i, 1, index.size()) {
      if (abs(index[i - 1] - index[i]) <= 1) {
        cout << "none" << endl;
        goto end;
      }
    }

    if (index.empty()) {
      rep(i, 1, a.size() - 1) {
        if (i & 1 && a[i] <= max(a[i - 1], a[i + 1])) {
          cout << "none" << endl;
          goto end;
        } else if (~(i & 1) && a[i] >= min(a[i - 1], a[i + 1])) {
          cout << "none" << endl;
          goto end;
        }
      }
    }

  end:
  }

  return 0;
}
