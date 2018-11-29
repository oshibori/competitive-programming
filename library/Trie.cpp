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
