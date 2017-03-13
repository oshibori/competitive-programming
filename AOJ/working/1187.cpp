#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<list>
#include<stack>
#include<queue>
#include<cctype>
#include<iomanip>
#include<functional>
using namespace std;
typedef long long llong;
int M, T, P, R;
class Team {
public:
	int problems[10];
	int ac;
	int number;
	int time;
	int rank;
};

bool f(Team a, Team b) {
	if (a.ac == b.ac&&a.time == b.time)return a.number > b.number;
	else if (a.ac == b.ac)return a.time < b.time;
	else return a.ac > b.ac;
}
int main() {
	while (1) {
		cin >> M >> T >> P >> R;
		if (!M && !T && !P && !R)break;
		vector<int>m(R), t(R), p(R), j(R);

		vector<Team>team(T);
		for (int i = 0; i < T; i++) {
			team[i].number = i + 1;
			team[i].ac = team[i].time = 0;
			for (int j = 0; j < 10; j++) {
				team[i].problems[j] = 0;
			}
		}
		for (int i = 0; i < R; i++) {
			cin >> m[i] >> t[i] >> p[i] >> j[i];
			t[i]--;
			p[i]--;
			if (j[i] == 0) {
				if (team[t[i]].problems[p[i]] == 0) {
					team[t[i]].problems[p[i]] = 1;
					team[t[i]].time += m[i];
					team[t[i]].ac++;
				}
				else if (team[t[i]].problems[p[i]] < 0) {
					team[t[i]].time += (m[i] + 20*(-team[t[i]].problems[p[i]]));
					team[t[i]].problems[p[i]] = 1;
					team[t[i]].ac++;
				}
			}
			else {
				team[t[i]].problems[p[i]]--;
			}

		}
		sort(team.begin(), team.end(), f);
		for (int i = 0; i < T; i++) {
			if (i) {
				if (team[i].ac == team[i - 1].ac&&team[i].time == team[i - 1].time) {
					cout << '=';
				}
				else {
					cout << ',';
				}
			}
			cout << team[i].number;

		}
		cout << endl;
	}
	return 0;
}
