#include<iostream>
#include<cctype>
#include<string>
using namespace std;
int main() {
	int x, y;
	char c1,c2;
	cin >> x;
	while (true) {
		cin >> c1;
		if (c1 == '=') {
			cout << x << endl;
			return 0;
		}
		else cin >> y;
		switch (c1) {
		case '+':x += y; break;
		case '-':x -= y; break;
		case '*':x *= y; break;
		case '/':x /= y; break;
		}
	}
}