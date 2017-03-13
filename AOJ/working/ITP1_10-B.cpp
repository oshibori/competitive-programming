#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	double PI = acos(-1);
	cout << PI << endl;
	//printf("%.10f", PI);
	double rad = c*PI / 180;
	cout << fixed << setprecision(5);
	cout << a*b*sin(rad)/2 << endl << a + b + sqrt(a*a + b*b - 2 * a*b*cos(rad)) << endl << b*sin(rad) << endl;
	return 0;
}