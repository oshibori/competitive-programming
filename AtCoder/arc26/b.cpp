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
//約数を求める 未ソート
vector<int> divisor(int x) {
  vector<int> ret;
  int i;
  for (i = 1; i * i < x; i++) {
    if (x % i)
      continue;
    ret.emplace_back(i);
    ret.emplace_back(x / i);
  }
  if (i * i == x)
    ret.emplace_back(i);
  return ret;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  auto div = divisor(N);
  int sum = accumulate(all(div), 0ll)-N;
  if (sum < N) {
    cout << "Deficient" << endl;

  } else if (sum == N) {
    cout << "Perfect" << endl;
  } else
    cout << "Abundant" << endl;

  return 0;
}
