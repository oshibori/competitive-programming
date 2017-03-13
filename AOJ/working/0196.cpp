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
class Team {
public:
	int order, win, lose;
	char name;
	bool operator<(const Team &other) {
		if (win != other.win)return win > other.win;
		else if (lose != other.lose)return lose < other.lose;
		else return order < other.order;
	}
};
signed main() {
	int n;
	while (cin >> n, n) {
		vector<Team>v(n);
		rep(i, 0, n) {
			char c; cin >> c;
			v[i].name = c; v[i].order = i;
			rep(j, 0, n - 1) {
				int x; cin >> x;
				if (x == 0)v[i].win++;
				else if (x == 1)v[i].lose++;
			}
		}
		sort(all(v));
		rep(i, 0, n)cout << v[i].name << endl;
	}
	return 0;
}