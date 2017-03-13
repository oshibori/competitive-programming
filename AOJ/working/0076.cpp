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
class complex {
public:
	double r, i, abs;
};
int main() {
	int n;
	cout << setprecision(8);
	while (1) {
		cin >> n;
		if (n == -1)break;
		complex x;
		x.i = 0; x.r = 1; x.abs = 1;
		for (int k = 1; k < n; k++) {
			complex w;
			w.r = x.r - x.i / x.abs;
			w.i = x.i + x.r / x.abs;
			w.abs = pow(w.r*w.r + w.i*w.i, 0.5);
			x = w;
		}
		cout << x.r << endl << x.i << endl;
	}
	return 0;
}