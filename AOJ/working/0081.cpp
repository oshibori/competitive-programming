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
	double x1, y1, x2, y2, xq, yq; char c;
	while (cin >> x1 >> c >> y1 >> c >> x2 >> c >> y2 >> c >> xq >> c >> yq) {
		complex<double>p1(x1, y1), p2(x2, y2), q(xq, yq), r;
		r = p1+polar(abs(p1-q), 2*arg(p2-p1)-arg(q-p1));
		printf("%.4f %.4f\n", r.real(), r.imag());
	}
	return 0;
}