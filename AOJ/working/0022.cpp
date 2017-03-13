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
#define EPS 1e-10
#define INF (-(1<<21))
using namespace std;
typedef long long llong;
int main() {
	int n;
	while (1) {
		cin >> n;
		if (!n)break;
		vector<int>a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		int tmp;
		int m = INF;
		for (int i = 0; i < n; i++) {
			tmp = 0;
			for (int j = i; j < n; j++) {
				tmp += a[j];
				m = max(m, tmp);

			}
		}
		cout << m << endl;
	}
	return 0;
}