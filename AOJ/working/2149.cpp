#include<iostream>
using namespace std;
bool flag(bool *f, int n);
int main() {
	int n, a, b, c, x, y[100];
	while (cin >> n >> a >> b >> c >> x&&n) {
		int cnt = 0, i = 0;
		bool f[100] = {};
		//bool u = false;
		for (int i = 0; i < n; i++)cin >> y[i];
		while (true) {
			if (cnt > 10000) { cnt = -1; break; }
			if (y[i] == x) {
				f[i++] = true;
				//u = true;
			}
			if (flag(f, n))break;
			cnt++;
			x = (a*x + b) % c;
			//cout << cnt << " " << x;
			//if (u) { cout << '!'; u = false; }
			//cout << endl;
		}
		cout << cnt << endl;
	}
	return 0;
}

bool flag(bool *f, int n) {
	for (int i = 0; i < n; i++) {
		if (!f[i])return false;
	}
	return true;
}

