#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DBG 0
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const double EPS = 1e-10;

signed main() {
	int N, D, X, Y; cin >> N >> D >> X >> Y;
	X = abs(X);
	Y = abs(Y);
	double ans = 0;
	bool f(false);
	if (X%D == 0)X /= D;
	else f = true;
	if (Y%D == 0)Y /= D;
	else f = true;

	if (X + Y > N)f = true;

	if (abs(N - X + Y) % 2 == 1)f = true;

	dump(X);
	dump(Y);
	if (f)ans = 0;
	else {
		vector<vector<double>>nCr(N + 1, vector<double>(N + 1, 0));
		nCr[0][0] = 1;// nŒÂ‚Ì’†‚©‚çrŒÂ‚ª‘I‚Î‚ê‚éŠm—¦
		for (int n = 1; n < N + 1; n++) {
			for (int r = 0; r <= n; r++) {
				double a = nCr[n - 1][r];
				if (0 <= r - 1)a += nCr[n - 1][r - 1];
				nCr[n][r] = a / 2;
			}
		}

		for (int x = X; x <= N; x++) {
			int y = N - x;
			if (x < X || y < Y || (x + X) % 2 || (y + Y) % 2)continue;
			dump(x); dump(y);

			double a = nCr[N][x];
			a *= nCr[x][(x + X) / 2];
			a *= nCr[y][(y + Y) / 2];
			ans += a;
			dump(a);
			dump(ans);

		}
	}

	cout << fixed << setprecision(8) << ans << endl;
	return 0;
}