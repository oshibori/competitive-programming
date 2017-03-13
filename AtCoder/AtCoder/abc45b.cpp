#include<iostream>
#include<string>
#include<queue>
using namespace std;
queue<char>sa, sb, sc;
queue<char> p;
void next(queue<char>z) {
	if (z.empty()) {
		p = z;
		return;
	}
	switch (z.front()) {
	case 'a':z.pop(); next(sa); return;
	case 'b':z.pop(); next(sb); return;
	case 'c':z.pop(); next(sc); return;
	default:break;
	}
	return;
}
int main() {
	string x;
	cin >> x;
	for (int j = 0; j < x.size(); j++)sa.push(x[j]);
	cin >> x;
	for (int j = 0; j < x.size(); j++)sb.push(x[j]);
	cin >> x;
	for (int j = 0; j < x.size(); j++)sc.push(x[j]);
	next(sa);
	if (p == sa)cout << 'A' << endl;
	else if (p == sb)cout << 'B' << endl;
	else cout << 'C' << endl;
	return 0;
}