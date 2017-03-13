#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class place {
public:
	int vote, rank, cost;
	place() {
		vote = 0;
	}
};
int main() {
	int n, m;
	cin >> n >> m;
	vector<place>P(n);
	for (int i = 0; i < n; i++) {
		cin >> P[i].cost;
		P[i].rank = i + 1;
	}
	for (int j = 0; j < m; j++) {
		int x; cin >> x;
		for (int k = 0; k < n; k++) {
			if (P[k].cost <= x) {
				P[k].vote++;
				break;
			}
		}
	}
	cout << max_element(P.begin(), P.end(), [](const place& x, const place& y) { return x.vote < y.vote; })->rank << endl;
	return 0;
}