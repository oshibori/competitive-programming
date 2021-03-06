#include<vector>
#include<functional>
using namespace std;
//https://ei1333.github.io/luzhiled/snippets/structure/trie.html
template< int char_size >
struct TrieNode {
  int nxt[char_size + 1];

  int exist;// 子ども以下に存在する文字列の数の合計
  vector< int > accept;//ノードにマッチする全ての追加された文字列の番号が格納される。

  TrieNode() : exist(0) {
    memset(nxt, -1, sizeof(nxt));
  }
};

template< int char_size, int margin >
struct Trie {
  using Node = TrieNode< char_size >;

  vector< Node > nodes;
  int root;

  Trie() : root(0) {
    nodes.push_back(Node());
  }

  void update_direct(int node, int id) {
    nodes[node].accept.push_back(id);
  }

  void update_child(int node, int child, int id) {
    ++nodes[node].exist;
  }

  void add(const string &str, int str_index, int node_index, int id) {
    if(str_index == str.size()) {
      update_direct(node_index, id);
    } else {
      const int c = str[str_index] - margin;
      if(nodes[node_index].nxt[c] == -1) {
        nodes[node_index].nxt[c] = (int) nodes.size();
        nodes.push_back(Node());
      }
      add(str, str_index + 1, nodes[node_index].nxt[c], id);
      update_child(node_index, nodes[node_index].nxt[c], id);
    }
  }

  void add(const string &str, int id) {
    add(str, 0, 0, id);
  }

  void add(const string &str) {
    add(str, nodes[0].exist);
  }

  void query(const string &str, const function< void(int) > &f, int str_index, int node_index) {
    for(auto &idx : nodes[node_index].accept) f(idx);
    if(str_index == str.size()) {
      return;
    } else {
      const int c = str[str_index] - margin;
      if(nodes[node_index].nxt[c] == -1) return;
      query(str, f, str_index + 1, nodes[node_index].nxt[c]);
    }
  }

  void query(const string &str, const function< void(int) > &f) {
    query(str, f, 0, 0);
  }

  int size() const {
    return (nodes[0].exist);
  }

  int nodesize() const {
    return ((int) nodes.size());
  }
};

// simpler ver
/*
struct Trie {
  Trie *node[26];
  int score;
  Trie() {
    score = 0;
    fill(node, node + 26, (Trie *)0);
  }
  void insert(const string &s, int val) {
    Trie *r = this;
    for (size_t i = 0; i < s.length(); i++) {
      int c = s[i] - 'a';
      if (!r->node[c])
        r->node[c] = new Trie;
      r = r->node[c];
    }
    r->score = val;
  }
  Trie *find(const char &s, Trie *pos) {
    int c = s - 'a';
    if (!pos->node[c])
      return (Trie *)0;
    return pos->node[c];
  }
};
*/