#include <bits/stdc++.h>
using namespace std;

//https://atcoder.jp/contests/abc133/submissions/6308069

struct LCA { // rooted tree
	using Node = int;
	vector<vector<Node>> parent;
	Graph g;
	int root, V, log2_n;
	vector<Node> depth;
	vector<Weight>dist;
	int get_depth(int x) { return depth[x]; }

	void dfs(int v, int p, int _depth, Weight w) {
		parent[0][v] = p;
		depth[v] = _depth;
		dist[v] = w;
		for (const auto &e : g[v]) {
			if (e.d == p)continue;
			dfs(e.d, v, _depth + 1, w + e.w);
		}
	}
	LCA(const Graph &G, int root)
		: root(root), V(G.size()), g(G), depth(V), log2_n(1 + (int)log2(V)), dist(V) {
		parent.resize(log2_n, vector<Node>(V));
		dfs(root, -1, 0, 0);
		for (int k = 0; k + 1 < log2_n; k++) {
			for (int v = 0; v < V; v++) {
				auto p = parent[k][v];
				if (p < 0) {
					parent[k + 1][v] = -1;
				}
				else {
					parent[k + 1][v] = parent[k][p];
				}
			}
		}
	}
	Node query(int u, int v) {
		if (depth[u] > depth[v])
			swap(u, v);
		for (int k = 0; k < log2_n; k++) {
			if ((depth[v] - depth[u]) >> k & 1) {
				v = parent[k][v];
			}
		}
		if (u == v)
			return u;
		for (int k = log2_n - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]) {
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		return parent[0][u];
	}
	Weight distance(int u, int v) {
		Node lca = query(u, v);
		return dist[u] + dist[v] - 2 * dist[lca];
	}
};
