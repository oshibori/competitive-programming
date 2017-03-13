#include<iostream>
using namespace std;
int main() {
	double w;
	while (cin >> w) {
		if (w <= 48)cout << "light fly" << endl;
		else if (w <= 51)cout << "fly" << endl;
		else if (w <= 54)cout << "bantam" << endl;
		else if (w <= 57)cout << "feather" << endl;
		else if (w <= 60)cout << "light" << endl;
		else if (w <= 64)cout << "light welter" << endl;
		else if (w <= 69)cout << "welter" << endl;
		else if (w <= 75)cout << "light middle" << endl;
		else if (w <= 81)cout << "middle" << endl;
		else if (w <= 91)cout << "light heavy" << endl;
		else if (w >91)cout << "heavy" << endl;
	}
	return 0;
}