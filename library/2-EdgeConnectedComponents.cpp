#include "bits/stdc++.h"
using namespace std;
//http://www.learning-algorithms.com/entry/2018/03/19/133709
struct LowLink {
        set<pair<int, int>> bridge;
        vector<int> articulation, ord, low;
        vector<bool> used;
        vector<vector<int>> g;
        int n, k = 0;
        LowLink(const vector<vector<int>> &g) : g(g) {
                n = g.size();
                ord.resize(n, 0);
                low.resize(n, 0);
                used.resize(n, false);
        }
        void dfs(int u, int prev) {
                used[u] = true;
                ord[u] = k ++;
                low[u] = ord[u];
                bool is_articulation = false;
                int cnt = 0;
                for (auto v : g[u]) if (v != prev) {
                        if (!used[v]) {
                                cnt ++;
                                dfs(v, u);
                                low[u] = min(low[u], low[v]);
                                if (low[v] > ord[u]) {
                                        bridge.emplace(min(u, v), max(u, v));
                                } 
                                if (prev != -1 && low[v] >= ord[u]) {
                                        is_articulation = true;
                                }
                        } else {
                                low[u] = min(low[u], ord[v]);
                        }
                }
                if (prev == -1 && cnt > 1) is_articulation = true;
                if (is_articulation) articulation.push_back(u);
        }
};
struct TwoEdgeConnectedComponent {
        int n;
        vector<vector<int>> g, tree;
        vector<int> cmp;
        TwoEdgeConnectedComponent(const vector<vector<int>> &g) : g(g) {
                n = (int) g.size();
                cmp.assign(n, -1);
        }
        void build() {
                LowLink lnk(g);
                lnk.dfs(0, -1);
                int k = 0;
                function<void (int, int)> dfs = [&](int u, int prev) {
                        cmp[u] = k;
                        for (auto v : g[u]) if (cmp[v] == -1 && lnk.bridge.count({min(u, v), max(u, v)}) == 0) {
                                dfs(v, u);
                        }
                };
                for (int i = 0; i < n; i ++) if (cmp[i] == -1) {
                        dfs(i, -1);
                        k ++;
                }
                tree.resize(k);
                for (auto e : lnk.bridge) {
                        tree[cmp[e.first]].push_back(cmp[e.second]);
                        tree[cmp[e.second]].push_back(cmp[e.first]);
                }
        }
};