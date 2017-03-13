#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<list>
#include<stack>
#include<queue>
#include<cctype>
#include<iomanip>
#include<functional>
#include<numeric>
#include<map>
#include<set>
#define EPS 1e-10
#define N 1000000007
using namespace std;
typedef long long llong;

int main() {
	int n; cin >> n;
	vector<llong>t(n), a(n), h(n);
	bool f = false;
	for (int i = 0; i < n; i++) {
		h[i] = -1;
	}
	for (int i = 0; i < n; i++)cin >> t[i];
	for (int i = 0; i < n; i++)cin >> a[i];
	h[0] = t[0];
	for (int i = 1; i < n; i++) {
		if (t[i] != t[i - 1]) {
			h[i] = t[i];
		}
	}
	if (h[n - 1] != -1 && h[n - 1] != a[n - 1]) {
		f = true;
		cout << 0 << endl;
		return 0;
	}
	h[n - 1] = a[n - 1];

	for (int i = n - 2; i >= 0; i--) {
		if (h[i] != -1 && a[i] < h[i]) {
			f = true;
			cout << 0 << endl;
			return 0;
		}
		if (a[i] != a[i + 1]) {
			if (h[i] != -1 && h[i] != a[i]) {
				f = true;
				cout << 0 << endl;
				return 0;
			}
			h[i] = a[i];
		}
	}

	llong cnt = 1;
	for (int i = 0; i < n; i++) {
		if (h[i] == -1) {
			cnt = (cnt*(llong)min(t[i], a[i])) % N;
		}
	}

	/*for (int i = 0; i < n; i++) {
		cout << h[i] << " ";
	}
	cout << endl;*/
	cout << cnt << endl;
	return 0;
}