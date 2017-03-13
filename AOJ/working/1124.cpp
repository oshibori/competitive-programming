#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, q, m, cnt[100] = {};
	while (cin >> n >> q&&n&&q) {
		for (int i = 0; i < n; i++) {
			cin >> m;
			for (int j = 0; j < m; j++) {
				int t;
				cin >> t;
				cnt[t]++;
			}
		}
		//for (int x = 0; x < 100; x++)cout << cnt[x] << " "; cout << endl;
		int maxc = 0,soeji;
		for (int i = 0; i < 100; i++) {
			if (maxc < cnt[i]) {
				maxc = cnt[i];
				soeji = i;
			}
		}
		if (maxc >= q) {
			cout << soeji << endl;
		}
		else cout << 0 << endl;
		fill_n(cnt, 100, 0);
	}
	return 0;
}