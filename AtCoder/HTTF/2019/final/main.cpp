#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define ll long long
#define ll1 1ll
#define ONE 1ll
#define DBG 1
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define loop(n) rep(loop, (0), (n))
#define all(c) begin(c), end(c)
const int INF =
    sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
using pii = pair<int, int>;
// template<class T> ostream &operator<<(ostream &os,T &t){dump(t);return os;}
template <typename T, typename S>
istream &operator>>(istream &is, pair<T, S> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, pair<T, S> &p) {
  os << p.first << " " << p.second;
  return os;
}

template <typename T> void printvv(const vector<vector<T>> &v) {
  cerr << endl;
  rep(i, 0, v.size()) rep(j, 0, v[i].size()) {
    if (typeid(v[i][j]).name() == typeid(INF).name() and v[i][j] == INF) {
      cerr << "INF";
    } else
      cerr << v[i][j];
    cerr << (j == v[i].size() - 1 ? '\n' : ' ');
  }
  cerr << endl;
}
/*
   typedef __int128_t Int;
   std::ostream &operator<<(std::ostream &dest, __int128_t value) {
   std::ostream::sentry s(dest);
   if (s) {
   __uint128_t tmp = value < 0 ? -value : value;
   char buffer[128];
   char *d = std::end(buffer);
   do {
   --d;
 *d = "0123456789"[tmp % 10];
 tmp /= 10;
 } while (tmp != 0);
 if (value < 0) {
 --d;
 *d = '-';
 }
 int len = std::end(buffer) - d;
 if (dest.rdbuf()->sputn(d, len) != len) {
 dest.setstate(std::ios_base::badbit);
 }
 }
 return dest;
 }

 __int128 parse(string &s) {
 __int128 ret = 0;
 for (int i = 0; i < s.length(); i++)
 if ('0' <= s[i] && s[i] <= '9')
 ret = 10 * ret + s[i] - '0';
 return ret;
 }
 */

#ifndef _DEBUG
#define printvv(...)
#endif
void YES(bool f) { cout << (f ? "YES" : "NO") << endl; }
void Yes(bool f) { cout << (f ? "Yes" : "No") << endl; }
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
//高速累乗 繰り返し自乗法
//オーバーフローする可能性があれば掛け算にmodmul()を使う
double modpow(double base, long long exponent) {
  double res = 1;
  while (exponent > 0) {
    if (exponent & 1)
      res = res * base;
    base = base * base;
    exponent >>= 1;
  }
  return res;
}
long long modpow(long long base, long long exponent) {
  long long res = 1;
  while (exponent > 0) {
    if (exponent & 1)
      res = res * base;
    base = base * base;
    exponent >>= 1;
  }
  return res;
}
long long Money = 1000;
vector<int> skilllevel(11), training_counter(11);
int T;
int N, M;
int baito = 1000;
int now = 0;
const int MM = 30002;
const int TT = 1002;
struct Quest {
  int a, b, id;
  long long c;
  vector<int> s;
};
Quest quests[MM];
vector<int> startq[MM], endq[MM];
vector<vector<int>> max_level(TT, vector<int>(11, 0));
set<int> candidate;
string command[TT];
int skillpointsum = 0;
void update(int mode = 1) {
  if (mode == 1) {
    for (auto &q : endq[now]) {
      candidate.erase(q);
    }
    for (auto &q : startq[now]) {
      candidate.insert(q);
    }
  } else {
    for (auto &q : startq[now + 1]) {
      candidate.erase(q);
    }
    for (auto &q : endq[now + 1]) {
      candidate.insert(q);
    }
  }
}
istream &operator>>(istream &is, Quest &q) {
  is >> q.a >> q.b >> q.c;
  rep(j, 1, 10 + 1) { is >> q.s[j]; }
  return is;
}
bool operator<(const Quest &q1, const Quest &q2) { return q1.id < q2.id; }
long long try_quest(const int &t, const int &qq) {
  Quest q = quests[qq];
  if (not(q.a <= t and t <= q.b)) {
    dump(q.a, t, q.b);
    // assert(q.a <= t and t <= q.b);
  };
  double addmoney = q.c;
  double deadline = (1 + 9 * (double)(t - q.a) / (q.b - q.a));
  addmoney *= deadline;
  int skilllack = 0;
  rep(j, 1, N + 1) skilllack += max(0, q.s[j] - skilllevel[j]);
  if (skilllack == 0)
    addmoney *= 10;
  else {
    addmoney *= modpow(0.5, skilllack);
    addmoney += 1e-9;
  }
  return (long long)addmoney;
}
long long training_const(int skill) {
  if (skilllevel[skill] >= 10)
    return -1;
  return 10000ll * modpow(2ll, skilllevel[skill] + 1);
}
void train(int skill) {
  assert(1 <= skill and skill <= 10);
  assert(skilllevel[skill] < 10);
  Money -= training_const(skill);
  assert(Money >= 0);
  training_counter[skill]++;
  if (training_counter[skill] == skilllevel[skill] + 1) {
    training_counter[skill] = 0;
    skilllevel[skill]++;
    skillpointsum++;
  }
  command[now] = "1 " + to_string(skill);
}
void arubaito() {
  Money += baito;
  command[now] = "3";
}
void achive_quest(const int &q) {
  Quest qq = quests[q];
  double deadline = (1 + 9 * (double)(now - qq.a) / (qq.b - qq.a));
  //  dump(deadline);
  Money += try_quest(now, q);
  candidate.erase(q);
  command[now] = "2 " + to_string(q);
}
signed main(signed argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  cin >> T;
  cin >> N >> M;
  skilllevel[0] = INF;
  rep(i, 1, M + 1) {
    quests[i].s.resize(11, INF);
    cin >> quests[i];
    quests[i].id = i;
    startq[quests[i].a].eb(i);
    endq[quests[i].b + 1].eb(i);
  }
  /*
  for (now = 1; now <= T; now++) {
    update();
    for (auto &q : candidate) {
      rep(j, 1, 11) { chmax(max_level[now][j], quests[q].s[j]); }
    }
  }
  update();
  rrep(t, 1, T) {
    rep(j, 1, 11) { chmax(max_level[t][j], max_level[t + 1][j]); }
  }
  */

  for (now = 1; now <= T and skillpointsum < 100; now++) {
    update();
    long long gain = 0;
    int prevMoney = Money;
    int id = -1;
    double deadline = 0;
    int id2 = -1;
    int deadlineover9 = 0;
    for (auto &q : candidate) {
      if (chmax(gain, try_quest(now, q))) {
        id = q;
      }
      Quest qq = quests[q];
      double _deadline = (1 + 9 * (double)(now - qq.a) / (qq.b - qq.a));
      if (_deadline > 9) {
        deadlineover9++;
      }
      if (chmax(deadline, _deadline)) {
        id2 = q;
      }
    }
    auto mm = min_element(skilllevel.begin() + 1, skilllevel.end());
    int d = mm - skilllevel.begin();
    if (0 and gain > Money * 2) {
      dump("!!!");
      achive_quest(id);
    } else if (training_const(d) != -1 and Money >= training_const(d)) {
      train(d);
    } else {
      if (0 and id2 != -1 and deadline > 9) {
        achive_quest(id2);
      } else if (id != -1 and gain > baito)
        achive_quest(id);
      else
        arubaito();
    }
  }
  dump(now, Money, skilllevel);
  int stop = now;
  candidate.clear();
  for (now = T; stop <= now; now--) {
    update(2);
    long long gain = 0;
    int id = -1;
    for (auto &q : candidate) {
      if (chmax(gain, try_quest(now, q))) {
        id = q;
      }
    }
    achive_quest(id);
  }
  dump(now, Money, skilllevel);

  rep(i, 1, T + 1) { cout << command[i] << endl; }

  return 0;
}
