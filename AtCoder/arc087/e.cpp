#include "bits/stdc++.h"

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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
		}
		else
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

#include<vector>
#include<functional>
using namespace std;

template< int char_size >
struct TrieNode {
	int nxt[char_size + 1];

	int exist;
	vector< int > accept;

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
		if (str_index == str.size()) {
			update_direct(node_index, id);
		}
		else {
			const int c = str[str_index] - margin;
			if (nodes[node_index].nxt[c] == -1) {
				nodes[node_index].nxt[c] = (int)nodes.size();
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
		for (auto &idx : nodes[node_index].accept) f(idx);
		if (str_index == str.size()) {
			return;
		}
		else {
			const int c = str[str_index] - margin;
			if (nodes[node_index].nxt[c] == -1) return;
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
		return ((int)nodes.size());
	}
};
// 0:=lose,1:=win
bool nim(vector<int>a) {
	int x = 0;
	for (int i = 0; i < a.size(); i++) {
		x ^= a[i];
	}
	return x != 0;
}

// 0:=lose
// ƒƒ‚‰»‚ð–Y‚ê‚È‚¢
int grundy(int x) {
	return (x == 0 ? 0 : x & -x);
	set<int>s;
	int gg = 0;
	s.insert(0);
	rrep(i,1,x) {
		gg ^= grundy(i);
		s.insert(gg);
	}
	int g = 0;
	while (s.count(g))g++;
	return g;
}
signed main(signed argc, char *argv[]) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(12);

	int N, L; cin >> N >> L;
	vector<string>s(N); rep(i, 0, N) { cin >> s[i]; }
	Trie<2, '0'> trie;
	rep(i, 0, N) {
		trie.add(s[i]);
	}
	vector<int>v;
	function<void(int, int)>f = [&](int root, int depth) {
		if (trie.nodes[root].accept.size())return;

		if (trie.nodes[root].nxt[0] == -1) {
			v.eb(L - depth);
		}
		else f(trie.nodes[root].nxt[0], depth + 1);

		if (trie.nodes[root].nxt[1] == -1) {
			v.eb(L - depth);
		}
		else f(trie.nodes[root].nxt[1], depth + 1);
	};
	f(trie.root, 0);
	dump(v);
	for (auto &x : v) {
		x = grundy(x);
	}
	dump(v);
	cout << (nim(v) ? "Alice" : "Bob") << endl;

	return 0;
}
