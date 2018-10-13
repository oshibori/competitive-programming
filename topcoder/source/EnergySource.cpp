#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define ll long long
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define all(c) begin(c), end(c)
const int INF =
    sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
#define fi first
#define se second
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

class EnergySource {

public:
  set<map<ll, ll>> st;
  void dfs(map<ll, ll> mp) {
    if (st.count(mp))
      return;
    st.insert(mp);
    for (auto p : mp) {
      rep(i, 2, p.fi + 1) {
        if (p.fi % i == 0) {
          map<ll, ll> mp2(mp);
          mp2[p.fi]--;
          if (mp2[p.fi] == 0) {
            mp2.erase(p.fi);
          }
          mp2[p.fi / i] += i;
          dfs(mp2);
        }
      }
    }
  }
  ll ppow(ll base, ll exp) {
    ll ret = 1;
    while (exp) {
      if (exp & 1) {
        ret *= base;
      }
      base *= base;
      exp >>= 1;
    }
    return ret;
  }
  vector<long long> countDifferentSources(int number) {
    vector<ll> ret(2, 0);
    map<ll, ll> mp;
    mp[number] = 1;
    dfs(mp);
    for (auto x : st) {
      ll y = 1;
      for (auto p : x) {
        y *= ppow(p.fi, p.se);
      }
      ret[1]+=y;
    }
    ret[0]=st.size();
    return ret;
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
  void verify_case(int Case, const vector<long long> &Expected,
                   const vector<long long> &Received) {
    cerr << "Test Case #" << Case << "...";
    if (Expected == Received)
      cerr << "PASSED" << endl;
    else {
      cerr << "FAILED" << endl;
      cerr << "\tExpected: " << print_array(Expected) << endl;
      cerr << "\tReceived: " << print_array(Received) << endl;
    }
  }
  void test_case_0() {
    int Arg0 = 3;
    long Arr1[] = {2, 4};
    vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(0, Arg1, countDifferentSources(Arg0));
  }
  void test_case_1() {
    int Arg0 = 10;
    long Arr1[] = {9, 103};
    vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(1, Arg1, countDifferentSources(Arg0));
  }
  void test_case_2() {
    int Arg0 = 1;
    long Arr1[] = {1, 1};
    vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(2, Arg1, countDifferentSources(Arg0));
  }
  void test_case_3() {
    int Arg0 = 90;
    long Arr1[] = {98014, 45465390986863499};
    vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(3, Arg1, countDifferentSources(Arg0));
  }
  void test_case_4() {
    int Arg0 = 48;
    long Arr1[] = {6978, 9697161469};
    vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    verify_case(4, Arg1, countDifferentSources(Arg0));
  }

  // END CUT HERE
};

// BEGIN CUT HERE

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  EnergySource x;
  x.run_test(-1);

  return 0;
}

// END CUT HERE
