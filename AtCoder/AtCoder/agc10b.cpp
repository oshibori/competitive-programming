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
bool check(vector<int>a, vector<int>b) {
	int x = distance(a.begin(), min_element(all(a)));
	int y = distance(b.begin(), min_element(all(b)));
	int len = a.size();
	rep(i, 0, len) {
		if (a[(i + x) % len] != b[(i + y) % len])return false;
	}
	return true;
}
signed main() {
	int n; cin >> n; vector<int>v(n); rep(i, 0, n)cin >> v[i];
	int sum = accumulate(v.begin(), v.end(), 0);
	int dic = (n*(n + 1)) / 2;
	if (sum % dic != 0) {
		cout << "NO" << endl;
		if (DBG)cout << 1 << endl;
	}
	else {
		int times = sum / dic;


		vector<int>origin(n);
		rep(i, 0, n)origin[i] = (i + 1);
		vector<int>law1(origin);
		rep(i, 0, n)law1[i] *= times;
		vector<int>law2(origin);
		int k = 1;
		rep(i, 0, times - 1) {
			rep(j, 0, n) {
				law2[j] += origin[(k + j) % n];
			}
			k++;
		}
		dumpc(law1);
		dumpc(law2);
		if (check(v, law1) || check(v, law2)) {
			cout << "YES" << endl;
			if (DBG)cout << 4 << endl;
		}
		else {
			cout << "NO" << endl;
			if (DBG)cout << 5 << endl;
		}


	}
	return 0;
}