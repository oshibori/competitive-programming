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

class UnfoldingTriangles {

public:
  int solve(vector<string> grid, int unfoldLimit) {

    int h = grid.size(), w = grid[0].size();

    int ans = -1;

    rep(i, 0, h) rep(j, 0, w) {
      for (int k = 0; 0 <= j - k && 0 <= i - k; k++) {
        bool f = true;
        if (i + 1 < h) {
          for (int x = j - k; x <= j; x++) {
            if (grid[i + 1][x] == '#')
              f = false;
          }
        }
        if (j + 1 < w) {
          for (int y = i - k; y <= i; y++) {
            if (grid[y][j + 1] == '#')
              f = false;
          }
        }
        if (!f)
          continue;


        int cnt = 0;
        for (int x = 0; x <= k; x++)
          for (int y = 0; y <= k - x; y++){
            if(y==k-x){
              if(grid[i-x][j-y]!='/')f=false;
            }
            else if(grid[i-x][j-y]=='.')f=false;
            else if (grid[i - x][j - y] == '/')
              cnt++;
          }

        if (f&&cnt <= unfoldLimit)
          chmax(ans, (k + 1) * (k + 2) / 2);
      }
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
    string Arr0[] = {".../", "../#", "./#/", "/#//"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 4;
    int Arg2 = 10;
    verify_case(0, Arg2, solve(Arg0, Arg1));
  }
  void test_case_1() {
    string Arr0[] = {".../", "../#", "./#/", "/#//"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 2;
    int Arg2 = 3;
    verify_case(1, Arg2, solve(Arg0, Arg1));
  }
  void test_case_2() {
    string Arr0[] = {"////", "////", "////", "////"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 5;
    int Arg2 = 6;
    verify_case(2, Arg2, solve(Arg0, Arg1));
  }
  void test_case_3() {
    string Arr0[] = {".....#...", "....###.."};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 10;
    int Arg2 = -1;
    verify_case(3, Arg2, solve(Arg0, Arg1));
  }
  void test_case_4() {
    string Arr0[] = {"#//#", "#//#", "####", "///#"};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 4;
    int Arg2 = 1;
    verify_case(4, Arg2, solve(Arg0, Arg1));
  }
  void test_case_5() {
    string Arr0[] = {".../.../", "../#..//", "./.#.///", "/###...."};
    vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 3;
    int Arg2 = 6;
    verify_case(5, Arg2, solve(Arg0, Arg1));
  }

  // END CUT HERE
};

// BEGIN CUT HERE

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  UnfoldingTriangles().run_test(3);

  return 0;
}

// END CUT HERE
