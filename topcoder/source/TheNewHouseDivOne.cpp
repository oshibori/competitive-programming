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

class TheNewHouseDivOne {

public:
  double distance(vector<int> x, vector<int> y, int k) {

    double ans = 1e9;

    int W = 51;
    for(double i=-W;i<W;i+=0.5)for(double j=-W;j<W;j+=0.5) {
      vector<double> arr;
      rep(l, 0, x.size()) arr.push_back(abs(i - x[l]) + abs(j - y[l]));
      sort(all(arr));
      chmin(ans, arr[k - 1]);
    }
    return ans;
  }

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
