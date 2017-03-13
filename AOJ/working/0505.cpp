#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class place {
public:
	int num, volume;
};
int main() {
	int n, m;
	while (cin >> n >> m&&n&m) {
		int x;
		vector<place>G(m);
		for (int i = 0; i < m; i++)G[i].num = i + 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> x;
				G[j].volume += x;
			}
		}
		sort(G.begin(), G.end(), [](const place& a, const place & b) {return (a.volume == b.volume) ? a.num<b.num : a.volume > b.volume; });
		for (int i = 0; i < m; i++) {
			if (i != 0)cout << ' ';
			cout << G[i].num;
		}
		cout << endl;

	}
	return 0;
}