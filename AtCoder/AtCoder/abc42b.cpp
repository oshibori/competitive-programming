#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	int n, l;
	cin >> n >> l;
	string s[100];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (s[j].compare(s[j - 1]) < 0) {
				swap(s[j], s[j - 1]);
			}
		}
	}
	string sum;
	for (int i = 0; i < n; i++) {
		sum += s[i];
	}
	cout << sum << endl;
	return 0;
}