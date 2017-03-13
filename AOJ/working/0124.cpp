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
class Team {
public:
	string name;
	int score;
	bool operator <(const Team &other) {
		return this->score > other.score;
	}
	bool operator >(const Team &other) {
		return other.score < this->score;
	}
	Team(string s, int x) {
		this->name = s;
		this->score = x;
	}
};
signed main() {
	int n, cnt(0);
	while (cin >> n, n) {
		vector<Team>team;
		rep(i, 0, n) {
			string s; int w, l, d;
			cin >> s >> w >> l >> d;
			Team a(s, w * 3 + d);
			team.push_back(a);
		}
		sort(team.begin(), team.end());
		if (cnt++)cout << endl;
		each(it, team)cout << it->name << "," << it->score << endl;
	}
	return 0;
}