#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
	cout << fixed << setprecision(5);
	int n;
	while (cin >> n&&n) {
		int x[1000],sum=0,sum2=0;
		for (int i = 0; i < n; i++) {
			cin >> x[i];
			sum += x[i];
			sum2 += x[i] * x[i];
		}
		double ave = (double)sum / n;
		double ave2 = (double)sum2 / n;
		cout << sqrt(ave2 - ave*ave) << endl;

	}
	return 0;
}