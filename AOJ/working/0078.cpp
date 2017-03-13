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
#define EPS 1e-10
using namespace std;
typedef long long llong;
int main() {
	int n;
	while (cin >> n&&n) {
		vector<vector<int >>v(n, vector<int>(n));
		for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)v[i][j] = -1;
		v[n / 2 + 1][n / 2] = 1;
		pair<int, int>pp;
		pp.first = n / 2 + 1;
		pp.second = n / 2;
		int cnt = 1;
		pair<int, int>pn;
		pn.first = pp.first + 1;
		pn.second = pp.second + 1;
		while (cnt < n*n) {
			if (pn.second == n) {
				pn.second = 0;
				//cout << "right" << endl;
			}
			if (pn.second == -1) {
				pn.second = n - 1;
				//cout << "left" << endl;
			}
			if (pn.first == n) {
				pn.first = 0;
				//cout << "under" << endl;
			}

			if (v[pn.first][pn.second] != -1) {
				pn.first++;
				pn.second--;
				//cout << "full" << endl;
			}
			else {
				cnt++;
				v[pn.first][pn.second] = cnt;
				pn.first++;
				pn.second++;
				//cout << "success" << endl;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%4d", v[i][j]);
			}
			putchar('\n');
		}
	}
	return 0;
}