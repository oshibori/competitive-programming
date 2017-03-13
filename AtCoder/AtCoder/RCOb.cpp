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
class Esa {
public:
	int fr, fc, F, D;
};
bool issafe(int x, int y) {
	if (0 <= x&&x < H && 0 <= y&&y < W)return true;
	else return false;
}
int H, W, K, sr, sc;
vector<vector<int>>v;
vector<int>dx{ 1,0,-1,0 }, dy{ 0,1,0,-1 };
vector<Esa>esa(1);
int N;
string dfs(int x, int y, int k, int sum, string s) {
	if (k == 0)return s;

	rep(i, 0, 4) {
		int _x = x + dx[i], _y = y + dy[i];
		if (issafe(_x, _y) && v[_x][_y] != -1) {
			if(_x==x+1&&_y==y)
		}
	}
}
signed main() {
	cin >> H >> W >> K >> sr >> sc; sr--; sc--;
	rep(i, 0, H) {
		vector<int>x;
		string s; cin >> s;
		rep(j, 0, W) {
			if (s[j] == '.')x.push_back(0);
			else if (s[j] == '#')x.push_back(-1);
		}
		v.push_back(x);
	}
	esa[0].F = 0;
	cin >> N;
	rep(i, 1, N + 1) {
		Esa g; cin >> g.fr >> g.fc >> g.F >> g.D;
		g.fr--; g.fc--;
		esa.push_back(g);
		v[g.fr][g.fc] = i;
	}


	return 0;
}