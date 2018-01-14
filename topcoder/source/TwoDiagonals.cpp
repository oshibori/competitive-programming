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

class TwoDiagonals {

public:
  bool inrange(int x, int y) {
    return 0 <= x and x < 1000 and 0 <= y and y < 1000;
  }
  int maxPoints(vector<int> x, vector<int> y) {

    vector<vector<int>> v(1000, vector<int>(1000, 0));
    int N = x.size();
    rep(i, 0, N) { v[x[i]][y[i]]++; }

    vector<int> l(1000, 0), r(1000, 0); // num,cross
    rep(i, 0, 1000) {
      int a = i, b = i;
      int cnt = v[a][b];
      a--, b++;
      while (inrange(a, b))
        cnt += v[a--][b++];
      a = i + 1, b = i - 1;
      while (inrange(a, b))
        cnt += v[a++][b--];
      l[i] = cnt;
    }
    rep(i, 0, 1000) {
      int a = 999 - i, b = i;
      int cnt = v[a][b];
      a--, b--;
      while (inrange(a, b))
        cnt += v[a--][b--];
      a = i + 1, b = i + 1;
      while (inrange(a, b))
        cnt += v[a++][b++];
      r[i] = cnt;
    }
    int ans = 0;
    rep(i, 0, 1000) rep(j, 0, 1000) {
      int a2 = (999 - (i - j)), b2 = (i + j - 999);
      int c = l[i] + r[j];
      if (a2 % 2 == 0 and b2 % 2 == 0 and inrange(a2 / 2, b2 / 2))
        c -= v[a2/2][b2/2];
      chmax(ans, c);
    }
    return ans;
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
    if ((Case == -1) || (Case == 7))
      test_case_7();
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
    int Arr0[] = {1, 4, 4, 5};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {3, 0, 2, 3};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 4;
    verify_case(0, Arg2, maxPoints(Arg0, Arg1));
  }
  void test_case_1() {
    int Arr0[] = {0, 1, 2, 3, 4, 5};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {2, 2, 2, 2, 2, 2};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 2;
    verify_case(1, Arg2, maxPoints(Arg0, Arg1));
  }
  void test_case_2() {
    int Arr0[] = {2, 2, 3, 3};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {2, 3, 2, 3};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 4;
    verify_case(2, Arg2, maxPoints(Arg0, Arg1));
  }
  void test_case_3() {
    int Arr0[] = {10, 0, 15, 9};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {10, 0, 15, 11};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 4;
    verify_case(3, Arg2, maxPoints(Arg0, Arg1));
  }
  void test_case_4() {
    int Arr0[] = {273, 100, 999, 789, 105};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {838, 200, 999, 0, 560};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 2;
    verify_case(4, Arg2, maxPoints(Arg0, Arg1));
  }
  void test_case_5() {
    int Arr0[] = {0, 2, 0, 2, 1};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {0, 0, 2, 2, 1};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 5;
    verify_case(5, Arg2, maxPoints(Arg0, Arg1));
  }
  void test_case_6() {
    int Arr0[] = {500, 503, 501};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {200, 197, 199};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 3;
    verify_case(6, Arg2, maxPoints(Arg0, Arg1));
  }
  void test_case_7() {
    int Arr0[] = {0, 2, 4};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arr1[] = {0, 3, 6};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 2;
    verify_case(7, Arg2, maxPoints(Arg0, Arg1));
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
