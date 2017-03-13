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
int main() {
	int a, b, c;
	while (cin >> a >> b >> c) {
		int x[11];
		for (int i = 1; i < 11; i++)x[i] = 1;
		x[a] = x[b] = x[c] = 0;
		int me = a + b;
		int cnt = 0;
		for (int i = 1; i <= 20-me; i++) {
			if (x[i])cnt++;
		}
		double p = (double)cnt / 7;
		if (p >= 0.500)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}