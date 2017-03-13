#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int a[3], cnt = 0;
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
		for (int j = 0; j < i; j++) {
			if (a[j] != a[i])cnt++;
		}
	}
	if (cnt == 0)cnt++;
	cout << cnt << endl;
	return 0;
}