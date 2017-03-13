#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main() {
	cout << fixed << setprecision(6);
	int n;
	cin >> n;
	int x[100], y[100];
	for (int i = 0; i < n; i++)cin >> x[i];
	for (int i = 0; i < n; i++)cin >> y[i];
	double sum1 = 0;
	for (int i = 0; i < n; i++)sum1 += fabs(x[i] - y[i]);
	double sum2 = 0;//Œã‚Å•½•ûª‚ð‚Æ‚é
	for (int i = 0; i < n; i++)sum2 += pow(fabs(x[i] - y[i]), 2);
	double sum3 = 0;//Œã‚Å—§•ûª‚ð‚Æ‚é
	for (int i = 0; i < n; i++)sum3 += pow(fabs(x[i] - y[i]), 3);
	double max = 0;
	for (int i = 0; i < n; i++)if (max < fabs(x[i] - y[i]))max = fabs(x[i] - y[i]);
	cout << sum1 << endl << sqrt(sum2) << endl << pow(sum3, 1.0 / 3) << endl << max << endl;
	return 0;
}