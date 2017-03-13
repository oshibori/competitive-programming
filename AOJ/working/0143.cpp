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
class Point {
public:
	int x, y;
};
int cross(Point z, Point a, Point b) {
	a.x -= z.x; a.y -= z.y;
	b.x -= z.x; b.y -= z.y;
	return a.x*b.y - a.y*b.x;
}
bool juge(Point z, Point a, Point b, Point c) {
	bool g = false, h = false;
	if (cross(z, a, b) > 0 && cross(z, b, c) > 0 && cross(z, c, a) > 0) {
		g = true;
	}
	if (cross(z, a, b) < 0 && cross(z, b, c) < 0 && cross(z, c, a) < 0) {
		h = true;
	}
	return g || h;
}
int main() {
	int n; cin >> n;
	while (n--) {
		Point p1, p2, p3, k, s;
		cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> k.x >> k.y >> s.x >> s.y;
		bool g = juge(k, p1, p2, p3);
		bool h = juge(s, p1, p2, p3);
		if (g^h == true)cout << "OK" << endl;
		else cout << "NG" << endl;

	}
	return 0;
}