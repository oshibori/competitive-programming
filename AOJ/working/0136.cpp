#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	int tall[6] = {};
	double x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x < 165.0)tall[0]++;
		else if (165.0 <= x&&x < 170.0)tall[1]++;
		else if (170.0 <= x&&x < 175.0)tall[2]++;
		else if (175.0 <= x&&x < 180.0)tall[3]++;
		else if (180.0 <= x&&x < 185.0)tall[4]++;
		else if (185.0 <= x)tall[5]++;
	}
	for (int i = 0; i < 6; i++) {
		cout << i + 1 << ':';
		for (int j = 0; j < tall[i]; j++)cout << '*';
		cout << endl;
	}
	return 0;
}