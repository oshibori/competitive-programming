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
int N = 50;
vector<pair<int, int>>p;
vector<string> input() {
	vector<string>t;
	rep(i, 0, N) {
		string s; cin >> s;
		t.push_back(s);
	}
	return t;
}
void output(const vector<string> &t) {
	cout << endl;
	rep(i, 0, N)cout << t[i] << endl;
}

vector<string> process(vector<string> t) {
	rrep(i, 1, N) {
		rep(j, 0, N) {
			if (t[i][j] == '.') {
				rrep(k, 0, i) {
					if (t[k][j] == '-') {
						rrep(l, k, i)t[l][j] = '-';
						break;
					}
					else if (t[k][j] != '.') {
						swap(t[i][j], t[k][j]);
						break;
					}

				}
			}
		}
		//output(t);
	}
	return t;
}

int dfs(vector<string>&t, int x, int y, int &cnt, char z) {
	if (x < 0 || N <= x || y < 0 || N <= y)return 0;
	int res(0);
	if (t[x][y] != z)return cnt;
	else if (t[x][y] == z) {
		t[x][y] = '.';
		cnt++;
		res = max(dfs(t, x - 1, y, cnt, z), max(dfs(t, x + 1, y, cnt, z), max(dfs(t, x, y - 1, cnt, z), dfs(t, x, y + 1, cnt, z))));
	}
	return res;
}
int exe_dfs(vector<string> t) {
	int reso(0), resx(0), cnto(0), cntx(0);
	rep(i, 0, N) {
		rep(j, 0, N) {
			cnto = cntx = 0;
			reso = max(reso, dfs(t, i, j, cnto, 'o'));
			resx = max(resx, dfs(t, i, j, cntx, 'x'));
		}
	}
	return reso + resx;
}

signed main() {
	vector<string>in = input();
	int value = exe_dfs(process(in));
	dump(value);
	//for (int bits = 0; bits < (1 << 16); bits++) {
	//	vector<string>copy(in);
	//	for (int i = 0; i < 16; i++) {
	//		if (bits&(1 << i)) {
	//			copy[p[i].first][p[i].second] = '-';
	//		}
	//		else {
	//			copy[p[i].first][p[i].second] = '.';
	//		}
	//		
	//	}
	//	int x = exe_dfs(process(copy));
	//	if (value < x) {
	//		in = copy;
	//		value = x;
	//	}
	//}
	rrep(i, 0, N) {
		rep(j, 0, N) {
			if (in[i][j] == '.') {
				vector<string>copy(in);
				copy[i][j] = '+';
				int a = exe_dfs(process(copy));
				if (value < a) {
					in = copy;
					value = a;
				}
				copy[i][j] = '-';
				int b = exe_dfs(process(copy));
				if (value < b) {
					in = copy;
					value = b;
				}

			}
		}
	}
	
	output(in);
	dump(value);
	return 0;
}