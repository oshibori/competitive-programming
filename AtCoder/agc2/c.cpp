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

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, L;
  cin >> N >> L;
  vector<int> a(N);
  rep(i, 0, N) { cin >> a[i]; }

  bool f = false;
  int ind = -1;
  rep(i, 1, N) {
    if (a[i - 1] + a[i] >= L) {
      ind=i;
      f = true;
    }
  }
  if (!f) {
    cout << "Impossible" << endl;
    return 0;
  }

  cout<<"Possible"<<endl;
  rep(i,0,ind-1)cout<<i+1<<endl;
  rrep(i,ind,N)cout<<i<<endl;


  return 0;
}
