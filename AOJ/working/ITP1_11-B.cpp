#include<iostream>
using namespace std;
class Cube {
public:
	int f[6];
	Cube(){}
	void roll_z() { roll(1, 2, 4, 3); }
	void roll_y() { roll(0, 2, 5, 3); }
	void roll_x() { roll(0, 1, 5, 4); }
	void roll(int i, int j, int k, int l) {
		int t = f[i]; f[i] = f[j]; f[j] = f[k]; f[k] = f[l]; f[l] = t;
	}
};
int getRight(Cube c1, int f1, int f2) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (c1.f[0] == f1&&c1.f[1] == f2)return c1.f[2];
			c1.roll_z();
		}
		if (i % 2 == 0)c1.roll_y();
		else c1.roll_x();
	}
	return -1;
}
int main() {
	Cube c;
	int f1, f2;
	for (int i = 0; i < 6; i++) {
		cin >> c.f[i];
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> f1 >> f2;
		cout << getRight(c, f1, f2) << endl;
	}
	return 0;
}
