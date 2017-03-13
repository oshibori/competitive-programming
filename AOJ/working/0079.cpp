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
	vector<complex<double> >v;
	double inx, iny;
	char c;

	complex<double> input(0, 0);
	//cout << input << endl;
	while (cin >> inx >> c >> iny) {
		complex<double> g(inx, iny);
		v.push_back(g);
	}
	double s = 0.0;
	for (int i = 1; i < v.size() - 1; i++) {
		double a = abs(v[0] - v[i]);
		double b = abs(v[0] - v[i + 1]);
		double c = abs(v[i] - v[i + 1]);
		double z = (a + b + c) / 2;
		s += sqrt(z*(z - a)*(z - b)*(z - c));
	}
	printf("%.6f\n", s);
	return 0;
}