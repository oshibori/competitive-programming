#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int W = 0, B = 1;
vector<vector<pair<int, int>>>adj;
int n;
void dijkstra() {
	priority_queue<pair<int, int>>pq;
	vector<int>color(n, W), d(n, INF);
	d[0] = 0;
	pq.push(make_pair(0, 0));

	while (!pq.empty()) {
		pair<int, int>f(pq.top()); pq.pop();// d[v], v
		color[f.second] = B;

		if (d[f.second] < (-1)*f.first)continue;
		
		rep(i, 0, adj[f.second].size()) {
			pair<int, int>v(adj[f.second][i]);
			if (color[v.first] != B&&d[f.second] + v.second < d[v.first]) {
				d[v.first] = d[f.second] + v.second;
				pq.push(make_pair(d[v.first] * (-1),v.first));
			}
		}
	}
	rep(i, 0, n) {
		cout << i << " " << d[i] << endl;
	}
}
signed main() {
	cin >> n; adj = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
	rep(i, 0, n) {
		int u, k; cin >> u >> k;
		rep(j, 0, k) {
			int v, c; cin >> v >> c;
			adj[u].push_back(make_pair(v, c));

		}
	}
	dijkstra();
	return 0;
}