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
bool isrectangle(int a, int b, int c) {
	if (a != b&&a*a + b*b == c*c)return true;
	else return false;
}
bool islozenge(int a, int b, int c) {
	if (a == b)return true;
	else return false;
}
int main() {
	int a, b, c;
	char x;
	int r = 0, l = 0;
	while (cin >> a >> x >> b >> x >> c) {
		if (isrectangle(a, b, c))r++;
		if (islozenge(a, b, c))l++;
	}
	cout << r << endl << l << endl;
	return 0;
}