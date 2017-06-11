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
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
vector<vector<int>>G(256, vector<int>(256, 0));
int len(0);
vector<string>ans;
void solve(string s) {
	dump(s);
	if (s.length() == len)ans.push_back(s);
	rep(i, 0, 256)if (G[s.back()][i]) {
		string g(s);
		g.push_back(char(i));
		solve(g);
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<string>a(N); rep(i, 0, N)cin >> a[i];
	vector<int>indeg(256, 0);
	rep(i, 0, N)len += a[i].length();
	rep(i, 0, N) {
		rep(j, 0, a[i].length() - 1) {
			G[a[i][j]][a[i][j + 1]] = 1;
			indeg[a[i][j + 1]]++;
		}
	}
	int M; cin >> M;

	bool f(false);
	vector<string>b(M); rep(i, 0, M)cin >> b[i];
	rep(i, 0, M) {
		rep(j, 0, b[i].length() - 1) {
			G[b[i][j]][b[i][j + 1]] = 1;
			indeg[b[i][j + 1]]++;
		}
	}
	rep(i, 0, N)rep(j, 0, a[i].size()) {
		if (indeg[a[i][j]] == 0) {
			string z("");
			z.push_back(a[i][j]);
			solve(z);

		}
	}

	if (ans.size() != 1)cout << -1 << endl;
	else cout << ans[0] << endl;
	return 0;
}