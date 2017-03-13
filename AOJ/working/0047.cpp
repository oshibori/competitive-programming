#include<iostream>
#include<string>
using namespace std;
int main() {
	char x, y, c;
	bool cup[3];
	cup[0] = true; cup[1] = false; cup[2] = false;
	while (cin >> x >> c >> y) {
		swap(cup[x - 'A'], cup[y - 'A']);
	}
	for (char i = 0; i < 3; i++) {
		if (cup[i] == true)cout << (char)('A' + i) << endl;
	}
	return 0;
}