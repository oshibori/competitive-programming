#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n; cin >> n;
	vector<unsigned long long>a(n), t(n);
	unsigned long long sum, m1, m2;
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> a[i];
		if (!i) {
			sum = t[i] + a[i];
		}
		else {
			unsigned long long x;
			if (t[i - 1] % t[i] == 0)m1 = t[i - 1] / t[i];
			else m1 = t[i - 1] / t[i] + 1;
			if (a[i - 1] % a[i] == 0)m2 = a[i - 1] / a[i];
			else m2 = a[i - 1] / a[i] + 1;
			x = max(m1, m2);
			t[i] = x*t[i];
			a[i] = x*a[i];
		
		
		}
		//cout << endl;
		//cout << "t[" << i << "] " << t[i] << " a[" << i << "] " << a[i] << endl << endl;
	}
	sum = t[n - 1] + a[n - 1];
	cout << sum << endl;
	return 0;
}