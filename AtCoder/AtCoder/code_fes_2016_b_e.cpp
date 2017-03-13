#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<list>
#include<stack>
#include<queue>
#include<iomanip>
#include<functional>
#include<cctype>
#include<map>
using namespace std;
typedef long long llong;
int order[26];
bool comp(string a, string b) {
	for (int i = 0; i < 26; i++) {
		//if (order[a[i] - 'a'] < order[b[i] - 'a'])return a < b;
		//else if (order[a[i] - 'a'] > order[b[i] - 'a'])return b < a;
		if (a[i] != b[i]) {
			if (a.size() == i||b.size()==i)return order[a[i] - 'a'] > order[b[i] - 'a'];

			return order[a[i] - 'a'] < order[b[i] - 'a'];
		}
	}
}
void printv(vector<string>s) {
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << endl;
	}
}
int main() {
	//for (int i = 0; i < 26; i++)order[i] = i;
	//string g = "aa", h = "aaab";
	//cout << comp(g, h) << endl;
	int n, q, k;
	cin >> n;
	vector<string>s(n), sp(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		sp[i] = s[i];
	}
	cin >> q;
	string p;
	for (int i = 0; i < q; i++) {
		cin >> k;
		cin >> p;
		for (int j = 0; j < p.size(); j++) {
			order[p[j] - 'a'] = j;
		}
		//for (int j = 0; j < 26; j++)cout << order[j];
		//cout << endl;
		//cout << "before" << endl;
		//printv(s);
		sort(s.begin(), s.end(), comp);
		//cout << "after" << endl;
		//printv(s);
		for (int j = 0; j < n; j++) {
			if (s[j] == sp[k - 1]) {
				cout << j + 1 << endl;
				break;
			}
		}

	}
	return 0;
}