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

class ManageSubsequences {

public:
  string lcs(string s, string t) {
    enum Direction { HORIZONTAL, VERTICAL, DIAGONAL, END };
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<Direction>> backtrace(n + 1, vector<Direction>(m + 1, END));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        dp[i + 1][j + 1] =
            max(dp[i][j] + (s[i] == t[j]), max(dp[i][j + 1], dp[i + 1][j]));
        if (dp[i + 1][j + 1] == dp[i][j + 1])
          backtrace[i + 1][j + 1] = VERTICAL;
        else if (dp[i + 1][j + 1] == dp[i + 1][j])
          backtrace[i + 1][j + 1] = HORIZONTAL;
        else
          backtrace[i + 1][j + 1] = DIAGONAL;
      }
    string r;
    int i = n, j = m;
    while (backtrace[i][j] != END) {
      if (backtrace[i][j] == DIAGONAL) {
        r.push_back(s[i - 1]);
        i--, j--;
      } else if (backtrace[i][j] == HORIZONTAL)
        j--;
      else
        i--;
    }
    reverse(all(r));
    return r;
    // return dp[n][m];
  }
  int minAdded(string S, string A, string B) {
    if(lcs(A,B)==B or lcs(S,B)==B)return -1;
    
  }

  // BEGIN CUT HERE
public:
  void run_test(int Case) {
    if ((Case == -1) || (Case == 0))
      test_case_0();
    if ((Case == -1) || (Case == 1))
      test_case_1();
    if ((Case == -1) || (Case == 2))
      test_case_2();
    if ((Case == -1) || (Case == 3))
      test_case_3();
    if ((Case == -1) || (Case == 4))
      test_case_4();
    if ((Case == -1) || (Case == 5))
      test_case_5();
    if ((Case == -1) || (Case == 6))
      test_case_6();
  }

private:
  template <typename T> string print_array(const vector<T> &V) {
    ostringstream os;
    os << "{ ";
    for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end();
         ++iter)
      os << '\"' << *iter << "\",";
    os << " }";
    return os.str();
  }
  void verify_case(int Case, const int &Expected, const int &Received) {
    cerr << "Test Case #" << Case << "...";
    if (Expected == Received)
      cerr << "PASSED" << endl;
    else {
      cerr << "FAILED" << endl;
      cerr << "\tExpected: \"" << Expected << '\"' << endl;
      cerr << "\tReceived: \"" << Received << '\"' << endl;
    }
  }
  void test_case_0() {
    string Arg0 = "ABXBCA";
    string Arg1 = "ABCD";
    string Arg2 = "XD";
    int Arg3 = 2;
    verify_case(0, Arg3, minAdded(Arg0, Arg1, Arg2));
  }
  void test_case_1() {
    string Arg0 = "BXC";
    string Arg1 = "BOCZ";
    string Arg2 = "DSFHDS";
    int Arg3 = 2;
    verify_case(1, Arg3, minAdded(Arg0, Arg1, Arg2));
  }
  void test_case_2() {
    string Arg0 = "BXC";
    string Arg1 = "BOCZ";
    string Arg2 = "BZ";
    int Arg3 = -1;
    verify_case(2, Arg3, minAdded(Arg0, Arg1, Arg2));
  }
  void test_case_3() {
    string Arg0 = "ABC";
    string Arg1 = "CDE";
    string Arg2 = "ABCE";
    int Arg3 = 3;
    verify_case(3, Arg3, minAdded(Arg0, Arg1, Arg2));
  }
  void test_case_4() {
    string Arg0 = "BANANA";
    string Arg1 = "APPLE";
    string Arg2 = "ANNA";
    int Arg3 = -1;
    verify_case(4, Arg3, minAdded(Arg0, Arg1, Arg2));
  }
  void test_case_5() {
    string Arg0 = "BANANA";
    string Arg1 = "ANANAS";
    string Arg2 = "BS";
    int Arg3 = 6;
    verify_case(5, Arg3, minAdded(Arg0, Arg1, Arg2));
  }
  void test_case_6() {
    string Arg0 = "BANANA";
    string Arg1 = "ANANAS";
    string Arg2 = "BNNS";
    int Arg3 = 3;
    verify_case(6, Arg3, minAdded(Arg0, Arg1, Arg2));
  }

  // END CUT HERE
};

// BEGIN CUT HERE

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  return 0;
}

// END CUT HERE
