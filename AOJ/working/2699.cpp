#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main() {
	double kotoshi[101][101];
	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 10; j++) {
			kotoshi[i][j] = sqrt(i*i + j*j);
			//cout <<" "<< kotoshi[i][j];
		}
		//cout << endl;
	}
	int d, e;
	while (cin >> d >> e&&d&&e) {
		double cost = 50000;
		int x , y = 0;
		for (x = d; x >= 0; x--, y++) {
			cost = min(cost, fabs(kotoshi[y][x] - e));
		}
		cout << cost << endl;
	}
	return 0;

}