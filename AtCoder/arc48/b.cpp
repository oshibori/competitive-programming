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
  map<int, map<int, int>> m;
  vector<int> r(N), h(N);
  rep(i, 0, N) {
    cin >> r[i] >> h[i];
    h[i]--;
    m[r[i]][h[i]]++;
  }

  // win lose draw
  int n = 0;
  for (auto &o : m) {
    dump(o.first,n);
    o.second[3] = n;
    n += o.second[0] + o.second[1] + o.second[2];
  }
  rep(i, 0, N) {
    int win = m[r[i]][3] + m[r[i]][(h[i] + 1 + 3) % 3],
        draw = m[r[i]][h[i]] - 1;
    int lose = N - win - draw - 1;
    cout << win << " " << lose << " " << draw << endl;
  }

  return 0;
}
