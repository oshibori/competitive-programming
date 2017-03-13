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
	vector<int>l(10), v(2);
	char c;
	while (cin >> l[0]) {
		for (int i = 1; i < 10; i++)cin >> c >> l[i];
		cin >> c >> v[0] >> c >> v[1];
		int sum = accumulate(l.begin(), l.end(), 0);
		//cout << "sum = " << sum;
		int V = v[0] + v[1];
		// cout << "  V = " << V << "  ";
		double x = (double)v[0] * sum / (double)V;
		//cout << "x = " << x << " ";
		int z = 0;
		for (int i = 0; i < 10; i++) {
			z += l[i];
			if (z >= x) {
				cout << i + 1 << endl;
				break;
			}
		}
	}
	return 0;
}