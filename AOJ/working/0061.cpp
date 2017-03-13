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
#include<numeric>
#include<map>
#include<set>
#define EPS 1e-10
using namespace std;
typedef long long llong;
class Team {
public:
	int num;
	int pro;
	int rank;

	bool operator<(const Team r) {
		if (pro != r.pro)return pro > r.pro;
		else return num < r.num;
	}
};
bool f(Team a, Team b) {
	if (a.pro != b.pro)return a.pro > b.pro;
	else return a.num < b.num;
}
void print_Team(vector<Team>t) {
	for (vector<Team>::iterator it = t.begin(); it != t.end(); it++) {
		cout << it->num << " ";
	}
	cout << endl;
}
int main() {
	vector<Team> t;
	int p, s;
	char c;
	while (1) {
		cin >> p >> c >> s;
		if (p == 0 && s == 0)break;
		Team z;
		z.num = p; z.pro = s;
		t.push_back(z);
	}
	//cout << "Before" << endl;
	//print_Team(t);
	sort(t.begin(), t.end());
	//cout << "After" << endl;
	//print_Team(t);
	int g = 1;
	t[0].rank = g;
	for (vector<Team>::iterator it = t.begin()+1; it != t.end(); it++) {
		if ((it - 1)->pro != it->pro)it->rank = ++g;
		else it->rank = g;
	}
	int q;
	while (cin >> q) {
		for (vector<Team>::iterator it = t.begin(); it != t.end(); it++) {
			if (it->num == q) {
				cout << it->rank << endl;
				break;
			}
		}
	}

	return 0;
}