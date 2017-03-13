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
void print(double *a) {
	for (int i = 0; i < 10; i++) {
		if (i)cout << " ";
		cout << a[i];
	}
}
int main() {
	cout << setprecision(10);
	double a;
	while (cin >> a) {
		double s[10];
		s[0] = a;
		for (int i = 1; i < 10; i++) {
			if (i & 1) {
				s[i] = s[i - 1] * 2;
			}
			else {
				s[i] = s[i - 1] / 3;
			}
		}
		//print(s);
		double sum = 0;
		for (int i = 0; i < 10; i++)sum += s[i];
		cout <<sum << endl;
	}
	return 0;
}