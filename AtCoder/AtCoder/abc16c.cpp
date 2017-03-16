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

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M; cin >> N >> M;
	vector<vector<int>>G(N, vector<int>(N, 0));
	rep(i, 0, M) {
		int a, b; cin >> a >> b;
		a--; b--;
		G[a][b] = G[b][a] = 1;
	}
	rep(i, 0, N) {
		int ans(0);
		vector<int>friend_friend_list(N, 0);
		rep(j, 0, N) {

			rep(k, 0, N) {
				if (i == j || j == k || k == i)continue;
				if(G[i][j]&&G[j][k]&&!G[i][k])
				friend_friend_list[k] = 1;
			}

		}
		cout << accumulate(all(friend_friend_list), 0) << endl;
	}
	return 0;
}