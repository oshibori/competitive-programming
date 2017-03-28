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
class Choco {
public:
	int x, y, z;
	Choco(int x, int y, int z) :x(x), y(y), z(z) {}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M, P, Q, R; cin >> N >> M >> P >> Q >> R;

	vector<Choco>choco;
	rep(i, 0, R) {
		int a, b, c; cin >> a >> b >> c; a--; b--;
		choco.emplace_back(a, b, c);
	}
	sort(all(choco), [](const Choco &a, const Choco &b) {return a.z > b.z; });
	int ans(-INF);
	rep(bits, 0, (1 << N)) {
		int cnt(0);
		rep(i, 0, N)if (bits&(1 << i))cnt++;
		if (cnt != P)continue;
		vector<int>boy(M, 0);
		for (int i(0), lim(Q); i < R; i++) {
			if (bits&(1 << choco[i].x)) {
				boy[choco[i].y] += choco[i].z;
			}
		}
		sort(all(boy), greater<int>());

		int t = accumulate(boy.begin(), boy.begin() + Q, 0LL);

		dump(t);
		chmax(ans, t);

	}
	cout << ans << endl;



	return 0;
}