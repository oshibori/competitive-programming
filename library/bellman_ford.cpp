#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
struct Edge {
	int from, to, cost;
	Edge() {}
	Edge(int from, int to, int cost) :from(from), to(to), cost(cost) {}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M; cin >> N >> M;
	vector<Edge>edges(M);
	rep(i, 0, M) {
		int a, b, c; cin >> a >> b >> c;
		a--, b--;
		edges[i].from = a;
		edges[i].to = b;
		edges[i].cost = -c;
	}
	vector<int>d(N, INF);
	d[0] = 0;
	rep(i, 0, N - 1) {
		rep(j, 0, M) {
			Edge e(edges[j]);
			if (d[e.from] == INF)continue;
			if (d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
			}
		}
	}
	int ans = -d[N - 1];
	// Å’ZŒo˜Hã‚Ì•Â˜H‚ğŒŸo@abc061 D
	vector<int>neg(N, 0);
	rep(i, 0, N) {
		rep(j, 0, M) {
			Edge e(edges[j]);
			if (d[e.from] == INF)continue;
			if (d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				neg[e.to] = 1;
			}

			if (neg[e.from])neg[e.to] = 1;
		}
	}
	if (neg[N - 1])cout << "inf" << endl;
	else cout << ans << endl;
	return 0;
}