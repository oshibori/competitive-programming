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

signed main() {
	int Case(1), n;
	while (cin >> n, n) {
		if (n == 1) {
			cout << "Case " << Case++ << ":" << endl;
			printf("  1\n");
			continue;
		}
		vector<vector<int>>v(n, vector<int>(n));
		int nowi(0), nowj(1), pasti(0), pastj(0), cnt(1);
		v[pasti][pasti] = cnt++;
		v[nowi][nowj] = cnt++;
		while (nowi!=n-1||nowj!=n-1) {
			if (nowi == 0 && pasti == 0 && pastj+1 == nowj) {
				pasti = nowi;
				pastj = nowj;
				nowi++;
				nowj--;
				v[nowi][nowj] = cnt++;
			}
			else if (nowi == 0 && pasti == 1 && pastj + 1 == nowj) {
				if (nowj != n - 1) {
					pasti = nowi;
					pastj = nowj;
					nowj++;
					v[nowi][nowj] = cnt++;
				}
				else {
					pasti = nowi;
					pastj = nowj;
					nowi++;
					v[nowi][nowj] = cnt++;
				}
			}
			else if (nowj == 0 && pastj == 0 && pasti + 1 == nowi) {
				pasti = nowi;
				pastj = nowj;
				nowi--;
				nowj++;
				v[nowi][nowj] = cnt++;
			}
			else if (nowj == 0 && pastj == 1 && pasti + 1 == nowi) {
				if (nowi != n - 1) {
					pasti = nowi;
					pastj = nowj;
					nowi++;
					v[nowi][nowj] = cnt++;
				}
				else {
					pasti = nowi;
					pastj = nowj;
					nowj++;
					v[nowi][nowj] = cnt++;
				}
			}
			else if (nowi == n - 1 && pasti == n - 1 && pastj + 1 == nowj) {
				pasti = nowi;
				pastj = nowj;
				nowi--;
				nowj++;
				v[nowi][nowj] = cnt++;
			}
			else if (nowi == n - 1 && pasti == nowi - 1 && nowj + 1 == pastj) {
				pasti = nowi;
				pastj = nowj;
				nowj++;
				v[nowi][nowj] = cnt++;
			}
			else if (nowj == n - 1 && pastj == n - 1 && pasti + 1 == nowi) {
				pasti = nowi;
				pastj = nowj;
				nowi++;
				nowj--;
				v[nowi][nowj] = cnt++;
			}
			else if (nowj == n - 1 && pastj == nowj - 1 && pasti == nowi + 1) {
				pasti = nowi;
				pastj = nowj;
				nowi++;
				v[nowi][nowj] = cnt++;
			}

			else if (nowi == pasti - 1 && nowj == pastj + 1) {
				pasti = nowi;
				pastj = nowj;
				nowi--;
				nowj++;
				v[nowi][nowj] = cnt++;
			}
			else if (nowi == pasti + 1 && nowj == pastj - 1) {
				pasti = nowi;
				pastj = nowj;
				nowi++;
				nowj--;
				v[nowi][nowj] = cnt++;
			}

		}
		cout << "Case " << Case++ << ":" << endl;
		rep(i, 0, n) {
			rep(j, 0, n) {
				printf("%3d", v[i][j]);
			}
			cout << endl;
		}


	}
	return 0;
}