#include<iostream>

using namespace std;

int main() {
	long long a, b, c,s;
	const long long d = 1000000007;
	cin >> a >> b >> c;
	s = (a*b) % d;
	s = (s*c) % d;
	cout << s << endl;
	return 0;
}
