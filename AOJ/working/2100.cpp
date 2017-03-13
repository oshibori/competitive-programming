#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int h[100];
		for (int j = 0; j < n; j++) {
			cin >> h[j];
		}
		int max1 = 0, min1 = 0;
		for (int j = 1; j < n; j++) {
			if (h[j - 1] < h[j])max1 = max(max1, h[j] - h[j - 1]);
			if (h[j - 1] > h[j])min1 = max(min1, h[j - 1] - h[j]);
			cout << max1 << ' ' << min1 << endl;
		}
		//cout << max1 << ' ' << min1 << endl;
	}
	return 0;
}