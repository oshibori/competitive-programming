#include<iostream>
#include<vector>
using namespace std;
//int s[100000][100000] = {};

int main() {
	int w, h, a, b;
	cin >> h >> w >> a >> b;
	vector<vector<int>>s1(h - a,vector<int>(w)), s2(a, vector<int>(w-b));
	s1[0][0] = 0;
	for (int i = 1; i < w; i++) {
		s1[0][i] = 1;
	}
	for (int i = 1; i < h - a; i++) {
		s1[i][0] = 1;
	}
	for (int i = 1; i < w; i++) {
		for (int j = 1; j < h - a; j++) {
			s1[i][j] = s1[i - 1][j] + s1[i - 1][j];
		}
	}
	int x = b-1;
	for (int i = 0; i < w - b; i++)s2[0][i] = s1[h - a-1][x++];
	for (int j = 1; j < a; j++)s2[j][0] = s1[0][0];
	for (int i = 1; i < w - b; i++) {
		for (int j = 1; j < a; j++) {
			s2[i][j] = s2[i - 1][j] + s2[i][j - 1];
		}
	}
	cout << s2[a-1][w-b-1] << endl;
	return 0;
}
