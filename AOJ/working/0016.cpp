#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<list>
#include<stack>
#include<queue>
#include<iomanip>
#include<functional>
using namespace std;
typedef long long llong;
double digrad(double dig) { return dig*M_PI / 180.0; }
int main() {
	double d, a,q=90;
	double x = 0, y = 0;
	char f;

	double rad=M_PI*q/180;
	while (true) {
		cin >> d >> f >> a;
		if (d == 0 && a == 0)break;
		x += d*cos(digrad(q));
		y += d*sin(digrad(q));
		//cout << "x: " << x << "  y: " << y << endl;
		q -= a;
	}
	x = (int)x;
	y = (int)y;
	cout << x << endl << y << endl;

	return 0;
}