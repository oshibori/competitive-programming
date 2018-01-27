#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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

int calc(string s) {
  dump(s);
  int n = s.size();
  vector<int> I(s.size(), 0), OI(s.size(), 0), JOI(s.size(), 0);
  I[n - 1] = (s[n - 1] == 'I');
  OI[n - 1] = 0;
  JOI[n - 1] = 0;
  rrep(i, 0, s.size() - 1) {
    I[i] = I[i + 1] + (s[i] == 'I');
    OI[i] = OI[i + 1] + I[i + 1] * (s[i] == 'O');
    JOI[i] = JOI[i + 1] + OI[i + 1] * (s[i] == 'J');
  }
  dump(I);
  dump(OI);
  dump(JOI);
  return JOI[0];
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  string s;
  cin >> s;

  vector<int> J(N, 0), I(N, 0);
  J[0] = (s[0] == 'J');
  I[N - 1] = (s[N - 1] == 'I');
  rep(i, 1, N) { J[i] = J[i - 1] + (s[i] == 'J'); }
  rrep(i, 0, N - 1) { I[i] = I[i + 1] + (s[i] == 'I'); }
  dump(J);
  dump(I);
  int cnt = calc(s);
  int tmp = 0;
  rep(i, 0, N - 1) chmax(tmp, +(J[i] * I[i + 1]));

  int ans = max({calc(s + "I"), calc("J" + s), cnt + tmp});
  cout << ans << endl;

  return 0;
}
