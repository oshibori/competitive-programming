#include<iostream>
#include<string>
using namespace std;

int main() {
	int n, k, d[9];
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> d[i];
	}
	while (true) {
		bool f = false;
		string s = to_string(n);
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < k; j++) {
				if (s[i] == '0' + d[j]) {
					f = true;
					break;
				}
			}
			if (f)break;
		}
		if (!f) {
			cout << n << endl;
			break;
		}
		n++;
	}
	return 0;
}

