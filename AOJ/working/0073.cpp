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
	double x, h;
	cout << setprecision(11);
	while (cin >> x >> h&&x&&h) {
		double a = x*pow(2, 0.5) / 2;
		double b = pow(a*a + h*h, 0.5);
		double c = x / 2;
		double d = pow(b*b - c*c, 0.5);
		cout << x*x + x*d / 2 * 4 << endl;
	}
	return 0;
}