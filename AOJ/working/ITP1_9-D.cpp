#include<iostream>
#include<string>

using namespace std;

int main() {
	string str, cmd;
	string p; int n = 0;
	int a, b, q;
	cin >> str >> q;
	for (int i = 0; i < q; i++) {
		cin >> cmd >> a >> b; 
		if (cmd == "print") {
			for (int j = a; j <= b; j++)
				cout << str[j]; cout << endl;
		}
		else if (cmd == "reverse") {
			for (int j = 0; j < (b - a + 1)/2; j++)
				swap(str[(a + j)], str[(b - j)]);
		}
		else if (cmd == "replace") {
			cin >> p;
			for (int k = a; k <= b; k++) {
				str[k] = p[n++];
			}n = 0;
		}
	}
	return 0;
}
