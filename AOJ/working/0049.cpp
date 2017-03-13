#include<iostream>
#include<string>
using namespace std;
int main() {
	int x, A, B, AB, O;
	string s;
	char c;
	A = B = AB = O = 0;
	while (cin >> x >> c >> s) {
		if (s == "A")A++;
		else if (s == "B")B++;
		else if (s == "AB")AB++;
		else O++;
	}
	cout << A << endl << B << endl << AB << endl << O << endl;
	return 0;
}