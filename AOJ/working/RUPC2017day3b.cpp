#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

template<class ForwardIterator, class T, class Compare>
ForwardIterator
lower_bound2(ForwardIterator first, ForwardIterator last, const T& value, Compare comp)
{
	using diff = typename std::iterator_traits<ForwardIterator>::difference_type;
	for (diff len = std::distance(first, last); len != 0; ) {
		diff half = len / 2;
		ForwardIterator mid = first;
		std::advance(mid, half);
		if (comp(*mid, value)) {
			len -= half + 1;
			first = ++mid;
		}
		else {
			len = half;
		}
	}
	return first;
}

// operator< 用の関数オブジェクト（std::less は特殊化されているかもしれないので）
struct less_inner {
	template <class T, class U>
	bool operator()(const T& lhs, const U& rhs) const { return bool(lhs < rhs); }
};

template<class ForwardIterator, class T>
inline ForwardIterator
lower_bound2(ForwardIterator first, ForwardIterator last, const T& value)
{
	return std::lower_bound(first, last, value, less_inner());
}


class Unit {
public:
	int status[3];
	int score, num;
	vector<int>rank;
	Unit(int s, int p, int c, int n) {
		status[0] = s; status[1] = p; status[2] = c;
		num = n;
		rank.resize(3);
	};
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	vector<int>r(N); rep(i, 0, N)cin >> r[i];
	vector<Unit>team;
	vector<vector<int>>Status(3);
	rep(i, 0, N) {
		int s, p, c; cin >> s >> p >> c;
		team.emplace_back(Unit(s, p, c, i));
		Status[0].emplace_back(s);
		Status[1].emplace_back(p);
		Status[2].emplace_back(c);
	}

	//cout << distance(Smile.begin(), Smile.begin()) << endl;

	sort(all(Status[0]), greater<int>());
	sort(all(Status[1]), greater<int>());
	sort(all(Status[2]), greater<int>());

	dump(Status[0]);
	dump(Status[1]);
	dump(Status[2]);

	rep(i, 0, N) {

		rep(j, 0, 3) {
			team[i].rank[j] = distance(Status[j].begin(), lower_bound2(all(Status[j]), team[i].status[j],
				[](const int &a, const int &b) {return a > b; }));

			dump(team[i].rank[j]);
		}
		team[i].score = 0;

		rep(j, 0, 3)team[i].score += r[team[i].rank[j]];
	}
	auto v = team[0];
	//sort(all(team), [](const Unit &a, const Unit &b) {return a.score > b.score; });

	//if (_DEBUG) {
	//	rep(i, 0, N)cout << team[i].num << " " << team[i].score << endl;
	//}

	int ans(INF);
	rep(i, 0, 3) {

		int left(-1), right(110);
		while (right - left > 1) {
			auto team_tmp(team);
			auto Status_tmp(Status);
			int mid = (left + right) / 2;
			dump(mid);
			dump(Status_tmp[i]);
			*lower_bound2(all(Status_tmp[i]), team_tmp[0].status[i], [](const int &a, const int &b) {return a > b; }) += mid;
			sort(all(Status_tmp[i]), greater<int>());
			dump(Status_tmp[i]);

			team_tmp[0].status[i] += mid;

			rep(j, 0, N) {
				team_tmp[j].rank[i] = distance(Status_tmp[i].begin(), lower_bound2(all(Status_tmp[i]), team_tmp[j].status[i],
					[](const int &a, const int &b) {return a > b; }));

				//dump(team_tmp[j].rank[i]);

				team_tmp[j].score = 0;
				rep(k, 0, 3) {
					team_tmp[j].score += r[team_tmp[j].rank[k]];
				}
				dump(team_tmp[j].rank[i], team_tmp[j].score);
			}
			int a = team_tmp[0].score;

			sort(all(team_tmp), [](const Unit &a, const Unit &b) {return a.score > b.score; });
			
			int index(0);
			while (team_tmp[index].score != a)index++;
			dump(index);
			if (index <= 7)right = mid;
			else left = mid;

			dump(left, right);
		}
		if (right != 110)chmin(ans, right);
		dump(ans);

	}

	if (ans == INF)cout << "Saiko" << endl;
	else cout << ans << endl;
	
	return 0;
}