#include<iostream>
using namespace std;
int main() {
	int a, b;
	while (cin >> a >> b&&a&&b) {
		int cnt[3] = {};
		int x = b - a;
		cnt[2] = x / 1000;
		x %= 1000;
		cnt[1] = x / 500;
		x %= 500;
		cnt[0] = x / 100;
		cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;
	}
	return 0;
}