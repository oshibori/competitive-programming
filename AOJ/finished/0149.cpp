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
	int n;
	while (cin >> n) {
		while (n > 39) {
			n -= 39;
		}
		cout << "3C";
		printf("%.2d\n", n);
	}
	return 0;
}