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
class takara {
public:
	int v, w;
	takara() {}
	takara(int x, int y) :v(x), w(y) {}
	bool operator<(const takara &other) {
		return this->w < other.w;
	}
};
signed main() {
	int W; int x(1);
	while (cin >> W, W) {
		int N; cin >> N;
		vector<takara>list;
		list.push_back(takara(0, 0));
		rep(i, 0, N) {
			int w, v; char c; cin >> v >> c >> w;
			list.push_back(takara(v, w));
		}
		vector<vector<int > >v(N + 1, vector<int>(W + 1, 0));
		rep(i, 1, N + 1) {
			rep(j, 1, W + 1) {
				v[i][j] = v[i - 1][j];
				if (j - list[i].w >= 0) {
					v[i][j] = max(v[i - 1][j], v[i - 1][j - list[i].w] + list[i].v);
				}
			}
		}
		int ret(0);
		rep(i, 0, W + 1) {
			if (v[N][ret] < v[N][i])ret = i;
		}
		cout << "Case " << x++ << ":" << endl;
		cout << v[N][W] << endl << ret << endl;
	}
	return 0;
}