#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void kakunin1(int kaki[][100], int w, int h) {
	for (int i = 1; i <= h; i++) {
		for (int j = 0; j < w; j++) {
			cout << " " << kaki[i][j];
		}
		cout << endl;
	}
	return;
}
int main() {
	int n;
	while (cin >> n&&n) {
		int w, h;
		cin >> w >> h;
		int kaki[100][100] = { {} };
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			kaki[y][x] = 1;
		}
		//kakunin1(kaki, w, h);
		int s, t;
		cin >> s >> t;
		int cnt = 0;
		for (int x1 = 1; x1 <= w - s + 1; x1++) {
			for (int y1 = 1; y1 <= h - t + 1; y1++) {
				int cntkari = 0;
				for (int x2 = 0; x2 < s; x2++) {
					for (int y2 = 0; y2 < t; y2++) {
						//cout << " " << kaki[y2][x2];
						cntkari += kaki[y1 + y2][x1 + x2];
					}
					//cout << endl;
				}
				//cout << endl;
				cnt = max(cnt, cntkari);
			}
		}
		cout << cnt << endl;
	}
	return 0;
}