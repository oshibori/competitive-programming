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

class MakeTwoConsecutive {

	public:

	string solve(string S) {

		string po="Possible";
    string im="Impossible";

    if(S.size()<=2)return im;
    else {
      rep(i,2,S.size())if(S[i]==S[i-2])return po;
      return im;
    }

	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "VIKING"; string Arg1 = "Possible"; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { string Arg0 = "BCAB"; string Arg1 = "Impossible"; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { string Arg0 = "XX"; string Arg1 = "Impossible"; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { string Arg0 = "A"; string Arg1 = "Impossible"; verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { string Arg0 = "AABB"; string Arg1 = "Possible"; verify_case(4, Arg1, solve(Arg0)); }
	void test_case_5() { string Arg0 = "QWERTYY"; string Arg1 = "Possible"; verify_case(5, Arg1, solve(Arg0)); }
	void test_case_6() { string Arg0 = "ITHINKYOUAREAHUMAN"; string Arg1 = "Impossible"; verify_case(6, Arg1, solve(Arg0)); }
	void test_case_7() { string Arg0 = "BOB"; string Arg1 = "Possible"; verify_case(7, Arg1, solve(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE 

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  return 0;
}

// END CUT HERE
