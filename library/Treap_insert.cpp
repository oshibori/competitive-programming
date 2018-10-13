#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

struct Treap {
  // https://www.slideshare.net/iwiwi/2-12188757
  // insert-erase base

  struct node_t {
    int val, cnt, sum; // 値,部分木のサイズ,部分木の値の和
    double pri;        // 優先度
    node_t *ch[2];     // = {左,右};
    node_t(int v, double p) : val(v), pri(p), cnt(1), sum(v) {
      ch[0] = ch[1] = nullptr;
    }
  };

  int count(node_t *t) { return !t ? 0 : t->cnt; }
  int sum(node_t *t) { return !t ? 0 : t->sum; }

  node_t *update(node_t *t) {
    // 部分木に関する情報を計算しなおす
    // 子が変わった時などに必ず呼ぶようにする
    t->cnt = count(t->ch[0]) + count(t->ch[1]) + 1;
    t->sum = sum(t->ch[0]) + sum(t->ch[1]) + t->val;
    return t; // 便利なのでt返しとく
  }

  node_t *rotate(node_t *t, int b) {
    // b=0 -> ccw, b=1 cw
    // 左右の順序を保ちつつ親子関係を変える。
    // 子を、別の変数でなく配列にすると、左右の回転が１つの関数で可能。
    //
    // 親の親のポインタを張替えなくて良いのは、各操作が常に部分木の根を返すように実装してるから。
    node_t *s = t->ch[1 - b];
    t->ch[1 - b] = s->ch[b];
    s->ch[b] = t;
    update(t);
    update(s);
    return s;
  }

  node_t *insert(node_t *t, int k, int val, double pri) {
    // tが根となっている木のk番目に値val,優先度priのノードを挿入。
    // 根のノードを返す。
    if (!t)
      return new node_t(val, pri);
    int c = count(t->ch[0]), b = (k > c);
    t->ch[b] = insert(t->ch[b], k - (b ? (c + 1) : 0), val, pri);
    update(t);
    if (t->pri < t->ch[b]->pri)
      t = rotate(t, 1 - b);
    return t;
  }
};
