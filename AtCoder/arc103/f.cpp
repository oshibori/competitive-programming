#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
using ll = long long;
using namespace std;

vector<pair<int, int> > solve(int n, vector<ll> const & d) {
    map<ll, int> index;
    REP (i, n) {
        index[d[i]] = i;
    }

    int root = index.begin()->second;
    vector<pair<int, int> > edges;
    vector<int> size(n, 1);
    vector<ll> d1(n, 0);
    for (auto it = index.rbegin(); ; ++ it) {
        ll d_i; int i; tie(d_i, i) = *it;
        if (i == root) break;
        ll d_parent = d_i - n + 2 * size[i];
        if (not index.count(d_parent)) {
            return vector<pair<int, int> >();
        }
        int parent = index[d_parent];
        edges.emplace_back(parent, i);
        size[parent] += size[i];
        d1[parent] += d1[i] + size[i];
    }

    if (d1[root] != d[root]) {
        return vector<pair<int, int> >();
    }
    return edges;
}

int main() {
    int n; cin >> n;
    vector<ll> d(n);
    REP (i, n) cin >> d[i];
    auto edges = solve(n, d);
    if (edges.empty()) {
        cout << -1 << endl;
    } else {
        for (auto edge : edges) {
            int i, j; tie(i, j) = edge;
            cout << i + 1 << ' ' << j + 1 << endl;
        }
    }
    return 0;
}
