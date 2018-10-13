#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template <class Abel> struct BIT {
  vector<Abel> dat;
  Abel UNITY_SUM = 0; // to be set

  /* [1, n] */
  BIT(int n) { init(n); }
  void init(int n) {
    dat.resize(n + 1);
    for (int i = 0; i < (int)dat.size(); ++i)
      dat[i] = UNITY_SUM;
  }

  /* a is 1-indexed */
  inline void add(int a, Abel x) {
    for (int i = a; i < (int)dat.size(); i += i & -i)
      dat[i] = dat[i] + x;
  }

  /* [1, a], a is 1-indexed */
  inline Abel sum(int a) {
    Abel res = UNITY_SUM;
    for (int i = a; i > 0; i -= i & -i)
      res = res + dat[i];
    return res;
  }

  /* [a, b), a and b are 1-indexed */
  inline Abel sum(int a, int b) { return sum(b - 1) - sum(a - 1); }

  /* k-th number (k is 0-indexed) */
  int get(long long k) {
    ++k;
    int res = 0;
    int N = 1;
    while (N < (int)dat.size())
      N *= 2;
    for (int i = N / 2; i > 0; i /= 2) {
      if (res + i < (int)dat.size() && dat[res + i] < k) {
        k = k - dat[res + i];
        res = res + i;
      }
    }
    return res + 1;
  }
};
