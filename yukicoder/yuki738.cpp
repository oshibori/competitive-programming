#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
typedef __int128_t Int;
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
template <typename T> void printvv(const vector<vector<T>> &v) {
  cerr << endl;
  rep(i, 0, v.size()) rep(j, 0, v[i].size()) {
    if (typeid(v[i][j]) == typeid(INF) and v[i][j] == INF) {
      cerr << "INF";
    } else
      cerr << v[i][j];
    cerr << (j == v[i].size() - 1 ? '\n' : ' ');
  }
  cerr << endl;
}
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
template <class Val> struct Treap {
  struct Node {
    Val val, sum, mini;
    Node *left, *right;
    int pri;
    int size;
    Node(Val v, int p) : val(v), mini(v), pri(p), size(1), sum(v) {
      left = right = nullptr;
    }
  };
  int size(Node *t) { return !t ? 0 : t->size; }
  Val sum(Node *t) { return !t ? 0 : t->sum; }
  Val val(Node *t) {
    assert(t);
    return t->val;
  }
  Val mini(Node *t) { return !t ? INF : t->mini; }

  Node *root;
  Treap() : root(nullptr){};
  Treap(Node *root) : root(root) {}
  Treap(Treap l, Treap r) : root(merge(l.root, r.root)) {}
  int size() { return size(root); }
  // get --- k; 0-index
  Val operator[](int k) {
    assert(k < size());
    return at(root, k)->val;
  }
  Node *setroot(Node *rrr) { return root = rrr; }

  // 子が変わったときに必ず呼ぶ
  Node *update(Node *t) {
    if (!t)
      return t;
    t->size = size(t->left) + size(t->right) + 1;
    t->sum = sum(t->left) + sum(t->right) + t->val;
    t->mini = min({val(t), mini(t->left), mini(t->right)});
    return t;
  }

  Node *update(Node *t, int k, Val v) { return insertAt(eraseAt(t, k), k, v); }

  // [l,r)
  Val mini(Node *t, int l, int r) {
    if (!t)
      return INF;
    if (r <= l)
      return INF;
    if (r - l == size(t))
      return mini(t);
    else if (size(t->left) >= r)
      return mini(t->left, l, r);
    else if (size(t->left) < l)
      return mini(t->right, l - (size(t->left) + 1), r - (size(t->left) + 1));
    return min({val(t), mini(t->left, l, size(t->left)),
                mini(t->right, 0, r - (size(t->left) + 1))});
  }

  Node *merge(Node *l, Node *r) {
    if (!l)
      return r;
    if (!r)
      return l;
    if (l->pri > r->pri) {
      l->right = merge(l->right, r);
      return update(l);
    } else {
      r->left = merge(l, r->left);
      return update(r);
    }
  }

  // ([0, k), [k, n))
  pair<Node *, Node *> split(Node *t, int k) {
    if (!t)
      return pair<Node *, Node *>(nullptr, nullptr);
    if (k <= size(t->left)) {
      pair<Node *, Node *> s = split(t->left, k);
      t->left = s.second;
      return make_pair(s.first, update(t));
    } else {
      pair<Node *, Node *> s = split(t->right, k - size(t->left) - 1);
      t->right = s.first;
      return make_pair(update(t), s.second);
    }
  }
  pair<Node *, Node *> split(int k) { return split(root, k); }

  // [0,n)
  int lowerbound(Node *t, Val v) {
    if (!t)
      return 0;
    if (v <= val(t))
      return lowerbound(t->left, v);
    else
      return size(t->left) + 1 + lowerbound(t->right, v);
  }
  int lowerbound(Val v) { return lowerbound(root, v); }
  int upperbound(Node *t, Val v) {
    if (!t)
      return 0;
    if (v <= val(t))
      return size(t->left) + 1 + upperbound(t->right, v);
    else
      return upperbound(t->left, v);
  }
  int upperbound(Val v) { return upperbound(root, v); }
  int count(Val v) { return upperbound(v) - lowerbound(v); }

  Node *insertAt(Node *t, int k, Val v) {
    auto s = split(t, k);
    Node *m = new Node(v, rand());
    return root = update(merge(update(merge(s.first, m)), s.second));
  }
  Node *insertAt(int k, Val v) { return insertAt(root, k, v); }

  Node *insert(Val v) { return insertAt(root, lowerbound(root, v), v); }

  Node *eraseAt(Node *t, int k) {
    auto s1 = split(t, k);
    auto s2 = split(s1.second, 1);
    return root = update(merge(s1.first, s2.second));
  }
  Node *eraseAt(int k) { return eraseAt(root, k); }
  Node *erase(Val v) { return (contain(v) ? eraseAt(lowerbound(v)) : nullptr); }

  Node *at(Node *t, int k) {
    assert(size(t) > k);
    auto s = split(t, k);
    Node *ret = s.second;
    while (ret->left)
      ret = ret->left;
    root = merge(s.first, s.second);
    return ret;
  }

  Node *circularShift(Node *t, int l, int r) {
    Node *a, *b, *c, *d;
    tie(a, d) = split(t, r);
    tie(a, b) = split(a, l);
    tie(b, c) = split(b, r - l - 1);
    return root = merge(merge(a, merge(c, b)), d);
  }

  bool contain(const Val q) const {
    auto a = root;
    while (a != nullptr) {
      if (a->val == q)
        return true;
      else if (a->val < q)
        a = a->right;
      else
        a = a->left;
    }
    return false;
  }
};

// template <typename T> int g(typename Treap<T>::Node t) { return 5; }

template <class Val> ostream &operator<<(ostream &o, Treap<Val> t) {
  function<void(typename Treap<Val>::Node *)> rec =
      [&](typename Treap<Val>::Node *x) {
        if (!x)
          return;
        rec(x->left);
        o << x->val << " ";
        rec(x->right);
        return;
      };
  o << "[";
  rec(t.root);
  o << "]";
  return o;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  rep(i, 0, N) { cin >> A[i]; }

  Treap<int> t;
  int ans(INF);
  rep(i, 0, N) {
    if (i < K - 1)
      t.insert(A[i]);
    else if (i >= K - 1) {
      t.insert(A[i]);
      dump(t, A[i]);
      int c = t[K / 2];
      int n = K / 2, m = K - n;
      auto p = t.split(K / 2);
      int a = t.sum(p.fi), b = t.sum(p.se);
      dump(a, b, c, n, m);
      chmin(ans, c * n - a + b - c * m);
      dump(ans);
      t.setroot(t.merge(p.fi, p.se));
      dump(t, A[i - (K - 1)]);
      t.erase(A[i - (K - 1)]);
      dump(t, A[i - (K - 1)]);
    }
  }
  cout << ans << endl;

  return 0;
}
