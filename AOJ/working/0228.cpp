#include<iostream>
#include<bitset>
using namespace std;
int henkan1(int x) {
	int y;
	switch (x) {
	case 0:y = 0b0111111; break;
	case 1:y = 0b0000110; break;
	case 2:y = 0b1011011; break;
	case 3:y = 0b1001111; break;
	case 4:y = 0b1100110; break;
	case 5:y = 0b1101101; break;
	case 6:y = 0b1111101; break;
	case 7:y = 0b0100111; break;
	case 8:y = 0b1111111; break;
	case 9:y = 0b1101111; break;
	default:break;
	}
	return y;
}
int henkan1(int x,int i) {
	if (!i)return 0;
	int y;
	switch (x) {
	case 0:y = 0b0111111; break;
	case 1:y = 0b0000110; break;
	case 2:y = 0b1011011; break;
	case 3:y = 0b1001111; break;
	case 4:y = 0b1100110; break;
	case 5:y = 0b1101101; break;
	case 6:y = 0b1111101; break;
	case 7:y = 0b0100111; break;
	case 8:y = 0b1111111; break;
	case 9:y = 0b1101111; break;
	default:break;
	}
	return y;
}
int henkan2(int x, int y,int i) {
	return henkan1(x,i) ^ henkan1(y);
}
int main() {
	int n;
	while (true) {
		cin >> n;
		if (n == -1)return 0;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> y;
			cout << static_cast<bitset<7>>(henkan2(x, y, i)) << endl;
			x = y;
		}
	}
	return 0;
}