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
int main() {
	int n, m;
	while (cin >> n >> m&&n&&m) {
		vector<int>v(n);
		//for (int i = 1; i <= n; i++)printf("%3d", i); cout << endl;
		for (int i = 0; i < n; i++)v[i] = 0;
		int cnt = 1;
		int tom = 0;
		int index;
		for (int i = 0; cnt != n + 1; i++) {
			if (v[i%n] == 0) {
				tom++;
			}

			if (tom == m) {
				v[i%n] = cnt++;
				index = i%n + 1;
				tom = 0;
			}
			//for (int j = 0; j < n; j++)printf("%3d", v[j]);
			//cout << "index is " << index << endl;
		}
		cout << index << endl;
	}
	return 0;
}