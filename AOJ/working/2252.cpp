#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	while (true) {
		cin >> s;
		if (s == "#")break;
		bool right = 0, left = 0;
		int cnt=0;
		for (int i = 0; i < s.size(); i++) {
			switch (s[i]) {
			case 'q':
			case 'w':
			case 'e':
			case 'r':
			case 't':
			case 'a':
			case 's':
			case 'd':
			case 'f':
			case 'g':
			case 'z':
			case 'x':
			case 'c':
			case 'v':
			case 'b':if (right) { right = false; left = true; cnt++; break; }if (!left && !right) { left = true; break; }break;
			case 'y':
			case 'u':
			case 'i':
			case 'o':
			case 'p':
			case 'h':
			case 'j':
			case 'k':
			case 'l':
			case 'n':
			case 'm':if (left) { left = false; right = true; cnt++; break; }if (!left && !right) { right = true; break; }break;
			default:break;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
