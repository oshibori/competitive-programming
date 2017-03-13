#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<list>
using namespace std;
int main() {
	int n; cin >> n;
	vector<int>v(n);
	vector<bool>f(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		f[i] = false;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (v[v[i] - 1] == i + 1 && f[i] == false && f[v[i] - 1] == false) {
			cnt++;
			f[i] = f[v[i] - 1] = true;
		}
	}
		cout << cnt << endl;


		return 0;

	

}