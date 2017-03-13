#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<cstdio>
using namespace std;
class Point {
public:
	double x, y;
};
double distance(Point x, Point y) {
	return pow(pow(fabs(x.x - y.x), 2) + pow(fabs(x.y - y.y), 2), 0.5);
}
int main() {
	cout << setprecision(4);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		Point p[3], s;
		for (int i = 0; i < 3; i++) {
			cin >> p[i].x >> p[i].y;
		}
		double a, b, c, d, e, f;
		a = (-2)*p[0].x + 2 * p[1].x;
		b = (-2)*p[0].y + 2 * p[1].y;
		c = (-2)*p[0].x + 2 * p[2].x;
		d = (-2)*p[0].y + 2 * p[2].y;
		e = pow(p[0].x, 2) + pow(p[0].y, 2) - pow(p[1].x, 2) - pow(p[1].y, 2);
		f = pow(p[0].x, 2) + pow(p[0].y, 2) - pow(p[2].x, 2) - pow(p[2].y, 2);
		s.x = (b*f - d*e) / (a*d - b*c);
		s.y = (a*f - c*e) / (b*c - a*d);
		double k = distance(p[0], s);
		s.x = round(s.x * 1000) / 1000;
		s.y = round(s.y * 1000) / 1000;
		k = round(k * 1000) / 1000;
		printf("%.3f %.3f %.3f\n", s.x, s.y, k);
	}
	return 0;
}