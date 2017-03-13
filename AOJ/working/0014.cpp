#include<iostream>
using namespace std;
typedef long long llong;
llong f(llong x) {
	return x*x;
}
int main() {
	int d;
	while (cin >> d) {
		llong s = 0;
		for (int i = d; i < 600; i += d) {
			s += f(i)*d;
		}
		cout << s << endl;
	}
	return 0;
}