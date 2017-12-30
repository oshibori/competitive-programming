#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

class CirclesCountry {

	public:

	int leastBorders(vector <int> X, vector <int> Y, vector <int> R, int x1, int y1, int x2, int y2) {

    int n=X.size();
    int ans(0);

    rep(i,0,n){
      // (x-x1)^2+(y-y1)^2 <= R^2
      bool f = (x1-X[i])*(x1-X[i])+(y1-Y[i])*(y1-Y[i])<=R[i]*R[i];
      bool g = (x2-X[i])*(x2-X[i])+(y2-Y[i])*(y2-Y[i])<=R[i]*R[i];

      if(f^g)ans++;
    }

    return ans;

	}

	


};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
