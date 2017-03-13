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
vector<int>ans;
vector<int>a, b;
int m;
void dandc(int x, int i) {
	if (x > 1009)return;
	if (i == m) {
		ans[x]++;
		return;
	}
	for (int j = 0; j <= b[i]; j++) {
		dandc(x + j*a[i], i + 1);
	}
}
int main() {
	while (cin >> m&&m) {
		ans = vector<int>(1010, 0);
		a = b = vector<int>(m, 0);
		for (int i = 0; i < m; i++) {
			cin >> a[i] >> b[i];
		}
		dandc(0, 0);
		int g, n;
		cin >> g;
		while (g--) {
			cin >> n;
			cout << ans[n] << endl;
		}
	}
	return 0;
}