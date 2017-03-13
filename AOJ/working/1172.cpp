#include<iostream>
#include<cmath>
using namespace std;
int sosuhantei(int x) {
	if (x == 2)return 1;
	if (x % 2 == 0||x==1||x<=0)return 0;
	for (int i = 3; i <= sqrt(x); i += 2) {
		if (x%i == 0)return 0;
	}
	return 1;
}

int cnt_primary(int n) {
	int cnt = 0;
	for (int i = n + 1; i <= 2 * n; i++) {
		if (sosuhantei(i))cnt++;
	}
	return cnt;
}

int main() {
	int n;
	while (cin >> n&&n) {
		cout << cnt_primary(n) << endl;
	}
	return 0;
}