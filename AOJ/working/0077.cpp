#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	while (cin >> s) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '@') {
				for (int j = 0; j < s[i + 1] - '0'; j++) {
					cout << s[i + 2];
				}
				i += 2;
			}
			else cout << s[i];
		}
		cout << endl;
	}
	return 0;
}