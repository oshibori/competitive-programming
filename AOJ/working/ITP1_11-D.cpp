#include<iostream>
using namespace std;
class Cube {
public:
	int f[6];
	Cube() {}
	void roll_z() { roll(1, 2, 4, 3); }
	void roll_y() { roll(0, 2, 5, 3); }
	void roll_x() { roll(0, 1, 5, 4); }
	void roll(int i, int j, int k, int l) {
		int t = f[i]; f[i] = f[j]; f[j] = f[k]; f[k] = f[l]; f[l] = t;
	}
};
bool eq(Cube c1, Cube c2) {
	for (int i = 0; i < 6; i++)
		if (c1.f[i] != c2.f[i])return false;
	return true;
}
bool equal(Cube c1, Cube c2) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (eq(c1, c2))return true;
			c1.roll_z();
		}
		if (i % 2 == 0)c1.roll_y();
		else c1.roll_x();
	}
	return false;
}
Cube C[100]; int n;
bool check() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (equal(C[i], C[j]))return false;			
		}	
	}
	return true;
}
int main() {
	cin >> n;
	for (int j = 0; j < n; j++)for (int i = 0; i < 6; i++)cin >> C[j].f[i];
	if (check())cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
