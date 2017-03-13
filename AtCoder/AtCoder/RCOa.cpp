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
class Piece {
public:
	vector<pair<int, int>>vec;
	int value;
};
vector<vector<int>>v1, v2;
vector<int> dx{ 1,0,-1,0 }, dy{ 0,1,0,-1 };
int H, W, K;
vector<Piece>ans;
bool issafe(int x, int y) {
	if (0 <= x&&x < H && 0 <= y&&y < W)return true;
	else return false;
}


signed main() {
	cin >> H >> W >> K;
	rep(i, 0, H) {
		string s; cin >> s;
		vector<int>x;
		rep(j, 0, W) {
			x.push_back(s[j] - '0');
		}
		v1.push_back(x);
	}


	rep(i, 0, H)rep(j, 0, W) {
		if (v1[i][j] != 0) {
			v2 = v1;

			int x = i, y = j;
			Piece p;
			while (1) {
				p.vec.push_back(make_pair(x, y));
				v2[x][y] = 0;
				int _x = x, _y = y;
				rep(l, 0, 4) {
					int __x = x + dx[l], __y = y + dy[l];
					if (issafe(__x, __y) && v2[_x][_y] < v2[__x][__y]) {
						_x = __x; _y = __y;
					}
				}
				x = _x, y = _y;
				if (v2[x][y] == 0)break;
				if (p.vec.size() == K) {
					v1 = v2;
					ans.push_back(p);
					break;
				}
			}

		}	
	}


	rep(i, 0, H)rep(j, 0, W) {
		if (v1[i][j] != 0) {
			v2 = v1;

			int x = i, y = j;
			Piece p;
			while (1) {
				p.vec.push_back(make_pair(x, y));
				v2[x][y] = 0;
				int _x = x, _y = y;
				rep(l, 0, 4) {
					int __x = x + dx[l], __y = y + dy[l];
					if (issafe(__x, __y) && v2[_x][_y] < v2[__x][__y]) {
						_x = __x; _y = __y;
					}
				}
				x = _x, y = _y;
				if (v2[x][y] == 0)break;
				if (p.vec.size() == K) {
					v1 = v2;
					ans.push_back(p);
					break;
				}
			}

		}
	}



	cout << ans.size() << endl;
	rep(i, 0, ans.size()) {
		rep(j, 0, ans[i].vec.size()) {
			cout << ans[i].vec[j].first + 1 << " " << ans[i].vec[j].second + 1 << endl;
		}
	}





	return 0;
}