#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<list>
using namespace std;
int main() {
	int R, C, N;
	cin >> R >> C >> N;
	vector<vector<int>>v(R, vector<int>(C));
	vector<int>r(R), c(C);
	for (int i = 0; i < N; i++) {
		cin >> r[i] >> c[i] >> v[r[i]][c[i]];
	}
	bool f = true;

	return 0;
}