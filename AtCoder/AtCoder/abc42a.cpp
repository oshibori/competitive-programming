#include<iostream>
using namespace std;
int main() {
	int x[3] = {}, f[3] = {};
	for (int i = 0; i < 3; i++) {
		cin >> x[i];
		if (x[i] == 7) {
			f[0] = true;
		}
		else if (f[1]&&x[i] == 5) {
			f[2] = true;
		}
		else if (x[i] == 5) {
			f[1] = true;
		}
		//cout << f[0] << f[1] << f[2] << endl;
	}
	if (f[0] && f[1] && f[2])puts("YES");
	else puts("NO");
	return 0;

}