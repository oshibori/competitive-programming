#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Student {
public:
	int tall;
	int bango;

};

int main() {
	int n;
	cin >> n;
	vector<Student> student(n);
	for (int i = 0; i < n; i++) {
		student[i].bango = i + 1;
		cin >> student[i].tall;
	}
	sort(student.begin(), student.end(),
		[](const Student& x, const Student& y) { return x.tall < y.tall; });

	for (int i = n-1; i >=0 ; i--) {
		cout << student[i].bango << endl;
	}
	
	return 0;
}