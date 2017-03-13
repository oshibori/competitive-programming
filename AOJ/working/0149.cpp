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
	double l, r;
	int al, ar, bl, br, cl, cr, dl, dr;
	al = ar = bl = br = cl = cr = dl = dr = 0;
	while (cin >> l >> r) {
		if (l >= 1.1)al++;
		else if (l >= 0.6)bl++;
		else if (l >= 0.2)cl++;
		else dl++;
		if (r >= 1.1)ar++;
		else if (r >= 0.6)br++;
		else if (r >= 0.2)cr++;
		else dr++;
	}
	cout << al << " " << ar << endl;
	cout << bl << " " << br << endl;
	cout << cl << " " << cr << endl;
	cout << dl << " " << dr << endl;
	return 0;
}