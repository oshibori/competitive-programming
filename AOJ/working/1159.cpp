#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int cnt,n, p, a[50] = {};
	while (cin >> n >> p&&n&&p) {
		fill(a, a + 50, 0);
		cnt = p;
		for (int i = 0;; i++) {
			if (a[i%n] == p) {
				cout << i%n << endl;
				break;
			}
			if (cnt == 0) {
				swap(cnt, a[i%n]);
				continue;
			}
			a[i%n]++;
			cnt--;
		}
	}
	return 0;
}