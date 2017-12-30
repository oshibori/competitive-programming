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

class CubeWalking {

	public:

	string finalPosition(string movement) {

		int x=0,y=0,dir=1;
    int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
    rep(i,0,movement.size()){
      if(movement[i]=='L')dir=(dir+1)%4;
      else if(movement[i]=='R')dir=(dir-1+4)%4;
      else {
        x+=dx[dir];
        y+=dy[dir];

        if(x==-2)x+=3;
        if(x==2)x-=3;
        if(y==-2)y+=3;
        if(y==2)y-=3;
      }
    }
    if(x==0&&y==0)return "GREEN";
    else if((x==-1||x==1)&&(y==-1||y==1))return "RED";
    else return "BLUE";

	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LLRR"; string Arg1 = "GREEN"; verify_case(0, Arg1, finalPosition(Arg0)); }
	void test_case_1() { string Arg0 = "WWWWWWWWWWWW"; string Arg1 = "GREEN"; verify_case(1, Arg1, finalPosition(Arg0)); }
	void test_case_2() { string Arg0 = "WLWRW"; string Arg1 = "RED"; verify_case(2, Arg1, finalPosition(Arg0)); }
	void test_case_3() { string Arg0 = "WWLLWRWLWLLRWW"; string Arg1 = "BLUE"; verify_case(3, Arg1, finalPosition(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE 

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  return 0;
}

// END CUT HERE
