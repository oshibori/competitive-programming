#define _GLIBCXX_DEBUG
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

int pow(int b, int e) {
  int ret = 1;
  rep(i, 0, e) ret *= b;
  return ret;
}
string operator*(string x, int y) {
  string ret;
  rep(i, 0, y) ret += x;
  return ret;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;
  K--;
  string ans;
  string J = "J", O = "O", I = "I";
  int l = 0, r = pow(2, N);
  while (1) {
    if(N==0){
      ans+=J;
      break;
    }
    int m = (l + r) / 2;
    if (l <= K and K < m) {
      ans += J * pow(2, N - 1) + O * pow(2, N - 1);
      break;
    } else {
      ans+=I*pow(2,N-1);
      l=m;
      N--;
    }
  }
  cout<<ans<<endl;

  return 0;
}
