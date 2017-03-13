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
const double EPS = 1e-10;
int N, C, K;
vector<int>v;

int check() {
	int i(0);
	int bus(0);
	while (i < N) {
		int time_limit = v[i] + K;
		int member(1);
		int j;
		for (j = i + 1; j<N&&member < C&&v[j] <= time_limit; j++) {
			member++;
		}
		i = j;
		bus++;
	}

	return bus;
}

signed main() {
	cin >> N >> C >> K;
	rep(i, 0, N) {
		int a; cin >> a; v.push_back(a);
	}
	sort(all(v));
	cout << check() << endl;



	return 0;
}