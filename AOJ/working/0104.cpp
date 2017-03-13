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
vector<string>v;
set<pair<int, int>>S;
pair<int, int> simulate(int x, int y) {
	auto it = S.find(make_pair(x, y));
	if (it != S.end())return make_pair(-1, -1);
	else S.insert(make_pair(x, y));

	if (v[x][y] == '>')return simulate(x, y + 1);
	else if (v[x][y] == '<')return simulate(x, y - 1);
	else if (v[x][y] == '^')return simulate(x - 1, y);
	else if (v[x][y] == 'v')return simulate(x + 1, y);
	else return make_pair(x, y);
}
signed main() {
	int w, h;
	while (cin >> h >> w, h || w) {
		v = vector<string>(h);
		S.clear();
		rep(i, 0, h) cin >> v[i];

		auto p = simulate(0, 0);
		if (p == make_pair(-1, -1)) {
			cout << "LOOP" << endl;
		}
		else cout << p.second << " " << p.first << endl;
	}
	return 0;
}