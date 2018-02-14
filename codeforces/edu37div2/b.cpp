#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
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

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  loop(t) {
    int N;
    cin >> N;
    vector<int> l(N), r(N);
    rep(i, 0, N) { cin >> l[i] >> r[i]; }
    vector<int> ans;
    int index = 0;
    int time = 1;
    while (index < N) {
      if(l[index]<=time){
        if(time<=r[index]){
          ans.push_back(time);
          time++;
        }
        else ans.push_back(0);
        index++;
      }
      else time++;
    }
    rep(i, 0, ans.size()) cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }

  return 0;
}
