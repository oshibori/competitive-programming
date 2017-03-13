#define _USE_MATH_DEFINES
#include<iostream>
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
vector<string>v(8);
void print_s() {
	for (int i = 0; i < 8; i++) {
		cout << v[i] << endl;
	}
}

void dfs(int x, int y) {
	v[x][y] = '0';
	int i = x-1, j = y,cnt=0;
	while (0 <= i&&i <= 7 && 0 <= j&&j <= 7 && cnt++ < 3) {
		if (v[i][j] == '1')dfs(i, j);
		i--;
	}
	i = x, j = y+1, cnt = 0;
	while (0 <= i&&i <= 7 && 0 <= j&&j <= 7 && cnt++ < 3) {
		if (v[i][j] == '1')dfs(i, j);
		j++;
	}
	i = x+1, j = y, cnt = 0;
	while (0 <= i&&i <= 7 && 0 <= j&&j <= 7 && cnt++ < 3) {
		if (v[i][j] == '1')dfs(i, j);
		i++;
	}
	i = x, j = y-1, cnt = 0;
	while (0 <= i&&i <= 7 && 0 <= j&&j <= 7 && cnt++ < 3) {
		if (v[i][j] == '1')dfs(i, j);
		j--;
	}
}

int main() {
	int n; cin >> n;
	for(int k=1;k<=n;k++) {
		for (int i = 0; i < 8; i++) {
			cin >> v[i];
		}
		int x, y;
		cin >> x >> y;
		x--; y--;
		dfs(y, x);
		cout << "Data " << k << ":" << endl;
		print_s();
	}
	return 0;
}