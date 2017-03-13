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
int N = 1000000;
signed main() {
	int n;
	while (cin >> n, n) {
		vector<int>v(n); rep(i, 0, n)cin >> v[i]; sort(all(v));
		//vector<bool>vf(N, false); rep(i, 0, n)vf[v[i]] = true;
		bool f(false),first(true);

		rep(i, 0, n-1) {
			if (f == false) {

				if (v[i] == v[i + 1] - 1) {
					if (first)first = false;
					else cout << " ";

					cout << v[i] << "-";
					f = true;
				}
				else {
					if (first)first = false;
					else cout << " ";
					cout << v[i];
				}
			}
			else {
				if (f&&v[i] != v[i + 1] - 1) {
					cout << v[i];
					f = false;
				}
			}
		}
		if (!f&&!first)cout << " ";
		cout << v[n - 1];
		cout << endl;
		
		//rep(i, 0, N) {
		//	if (vf[i]) {
		//		if (f == false) {
		//			if (first)first = false;
		//			else cout << " ";

		//			cout << i << "-";
		//			f = true;
		//		}
		//	}
		//	else {
		//		if (f == true) {
		//			cout << i - 1;
		//			f = false;
		//		}
		//	}
		//}
		//cout << endl;

	}
	return 0;
}