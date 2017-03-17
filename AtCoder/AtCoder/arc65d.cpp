#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

vector<vector<int>>vec;
int n;
vector<int>color;
void bsf(int s, int c) {
	queue<int>q;
	q.push(s);
	color[s] = c;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		rep(v, 0, vec[u].size()) {
			if (color[vec[u][v]] != -1)continue;
			color[vec[u][v]] = c;
			q.push(vec[u][v]);
		}
	}
}
void assignColor() {
	rep(i, 0, n) {
		if (color[i] == -1)bsf(i, i);
	}
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	vec = vector<vector<int>>(n);
	color = vector<int>(n, -1);
	int K, L; cin >> K >> L;
	rep(i, 0, K) {
		int p, q; cin >> p >> q; p--, q--;
		vec[p].push_back(q);
		vec[q].push_back(p);
	}
	assignColor();
	vector<int>road = color;
	color = vector<int>(n, -1);
	vec = vector<vector<int>>(n);
	rep(i, 0, L) {
		int r, s; cin >> r >> s; r--, s--;
		vec[r].push_back(s);
		vec[s].push_back(r);
	}
	assignColor();
	vector<int>rail = color;

	dump(road); dump(rail);

	map < pair<int, int>, int>ans;
	rep(i, 0, n)ans[make_pair(road[i], rail[i])]++;
	rep(i, 0, n)cout << ans[make_pair(road[i], rail[i])] << (i == n - 1 ? '\n' : ' ');


	return 0;
}