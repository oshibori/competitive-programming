#include<iostream>
#include<vector>
using namespace std;
class birthday {
public:
	int y, m, d, D , M, Y, today, x;
	birthday() {
		cin >> y >> m >> d;
		y--; m--;
		today = 999 / 3 * 590 + 1;
		D = y / 3 * 590 + y % 3 * 195 + m / 2 * 39 + m % 2 * 20 + d;
		if ((y + 1) % 3 == 0) {
			if ((m + 1) % 2 == 1)D += (m + 1) / 2;
			else D += m / 2;
		}
		x = today - D;
		cout << x <<endl;
	}
};
int main() {
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	birthday people;
	return 0;
}
