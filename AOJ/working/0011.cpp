#include<iostream>
#include<vector>
using namespace std;
int main() {
	int w; cin >> w;
	int n; cin >> n;
	int a, b;
	vector<int>v(w);
	char c;
	for (int i = 0; i < w; i++)v[i] = i + 1;
	for (int i = 0; i < n; i++) {
		cin >> a >>c>> b;
		swap(v[a - 1], v[b - 1]);
	}
	for (int i = 0; i < w; i++)cout << v[i] << endl;
	return 0;
}