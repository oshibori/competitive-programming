#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Cube {
public:
	int f[6];
	int sum;
	Cube() {
		f[0] = 1; f[1] = 2; f[2] = 3; f[3] = 4; f[4] = 5; f[5] = 6;
		sum = 1;
	}
	void roll(int i, int j, int k, int l) {
		int t = f[i]; f[i] = f[j]; f[j] = f[k]; f[k] = f[l]; f[l] = t;
	}
	void roll_north() { roll(0, 1, 5, 4); sum += f[0]; }
	void roll_east() { roll(0, 3, 5, 2); sum += f[0]; }
	void roll_west() { roll(0, 2, 5, 3); sum += f[0];}
	void roll_south() { roll(0, 4, 5, 1); sum += f[0];}
	void roll_right() { roll(1, 2, 4, 3); sum += f[0];}
	void roll_left() { roll(2, 1, 3, 4); sum += f[0];}
};
int main() {
	int n;
	while (cin >> n&&n) {
		Cube c;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			if (s == "North")c.roll_north();
			else if (s == "East")c.roll_east();
			else if (s == "South")c.roll_south();
			else if (s == "West")c.roll_west();
			else if (s == "Right")c.roll_right();
			else if (s == "Left")c.roll_left();
		}
		cout << c.sum << endl;
	}
	return 0;
}