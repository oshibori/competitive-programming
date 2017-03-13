#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	char s[50][50];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[j][n-1-i];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << s[i][j];
		}
		cout << endl;
	}
	return 0;
}