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
	int rank, score, num;
	Team() { rank = 0, score = 0, num = 0; }
};
bool by_score(const Team &a, const Team &b) {
	return a.score > b.score;
}
bool by_num(const Team &a, const Team &b) {
	return a.num < b.num;
}
signed main() {
	int n; cin >> n;
	int battle = n*(n - 1) / 2;
	vector<Team>team(n);
	rep(i, 0, n)team[i].num = i;
	rep(i, 0, battle) {
		int a, b, c, d;
		cin >> a >> b >> c >> d; a--, b--;
		if (c == d) team[a].score++, team[b].score++;
		else if (c < d) team[b].score += 3;
		else team[a].score += 3;
	}
	sort(all(team), by_score);
	team[0].rank = 1;
	int r = 2;
	rep(i, 1, n) {
		if (team[i].score == team[i - 1].score) {
			team[i].rank = team[i - 1].rank;
			r++;
		}
		else team[i].rank = r, r++;
	}
	sort(all(team), by_num);
	rep(i, 0, n)cout << team[i].rank << endl;
	
	return 0;
}