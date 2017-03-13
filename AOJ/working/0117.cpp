#define _USE_MATH_DEFINES
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<list>
#include<stack>
#include<queue>
#include<cctype>
#include<iomanip>
#include<functional>
#include<numeric>
#include<map>
#include<set>
#include<complex>
#define EPS 1e-10
using namespace std;
typedef long long llong;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
static const int INF = (1 << 21);
int n, m;
vector<vector<int> >v;
vector<int>color, dis, p;
int s, g, V, P;

void dijkstra(int s) {
	int minv;
	for (int i = 0; i < n; i++) {
		dis[i] = INF;
		color[i] = WHITE;
	}
	dis[s] = 0;
	color[s] = GRAY;
	while (1) {
		minv = INF;
		int u = -1;
		for (int i = 0; i < n; i++) {
			if (minv > dis[i] && color[i] != BLACK) {
				minv = dis[i];
				u = i;
			}
		}
		if (u == -1)break;
		color[u] = BLACK;
		for (int r = 0; r < n; r++) {
			if (color[r] != BLACK&&v[u][r] != INF) {
				if (dis[r] > dis[u] + v[u][r]) {
					dis[r] = dis[u] + v[u][r];
					color[r] = GRAY;
				}
			}
		}
	}

}


int main() {
	cin >> n >> m;
	color = p = dis = vector<int>(n);
	for (int i = 0; i < n; i++) {
		vector<int>x;
		v.push_back(x);
		for (int j = 0; j < n; j++) {
			v[i].push_back(INF);
		}
	}
	int a, b, c, d;
	char e;
	for (int i = 0; i < m; i++) {
		cin >> a >> e >> b >> e >> c >> e >> d;
		a--; b--;
		v[a][b] = c;
		v[b][a] = d;
	}
	cin >> s >> e >> g >> e >> V >> e >> P;
	s--; g--;
	V -= P;
	dijkstra(s);
	V -= dis[g];
	dijkstra(g);
	V -= dis[s];
	cout << V << endl;
	return 0;
}