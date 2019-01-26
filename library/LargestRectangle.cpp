#include<stdio.h>
#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
#define MAX 105
#define BLOCK 0
using namespace std;

//https://tubo28.me/algorithm/max-rect/
// h:= histgram
long long maximum_rectangle(const std::vector<int> &h) {
    int n = h.size();
    std::stack<int> s;
    std::vector<int> L(n), R(n);
    for (int i = 0; i < n; i++) {
        while (s.size() && h[s.top()] >= h[i]) s.pop();
        L[i] = s.size() ? (s.top() + 1) : 0;
        s.push(i);
    }
    while (s.size()) s.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (s.size() > 0 && h[s.top()] >= h[i]) s.pop();
        R[i] = s.size() ? s.top() : n;
        s.push(i);
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res = std::max(res, (long long)h[i] * (R[i] - L[i]));
    }
    return res;
}

//-------------------------------------------------------------------

struct Rectangle { int height;  int pos; };
int getLargestRectangle(vector<int>h) {
	stack<Rectangle> S;
	int maxv = 0;
	h.emplace_back(0);
	int W = h.size();
	//  右端がh[i]のとき、{j | j<i, h[j]>h[i]}の情報はいらないので、それまでの長方形を計算する
	// stackの中を単調増加に保つ
	for (int i = 0; i < W; i++) {
		Rectangle rect;
		rect.height = h[i];
		rect.pos = i;
		if (S.empty()) {
			S.push(rect);
		}
		else {
			if (S.top().height < rect.height) {
				S.push(rect);
			}
			else if (S.top().height > rect.height) {
				int target = i;
				while (!S.empty() && S.top().height >= rect.height) {
					Rectangle pre = S.top(); S.pop();
					int area = pre.height * (i - pre.pos);
					maxv = max(maxv, area);
					target = pre.pos;
				}
				rect.pos = target;
				S.push(rect);
			}
		}
	}
	return maxv;
}

// can use:1, cannot use:0
int getLargestRectangle(const vector<vector<int>>&v) {
	int H = v.size(), W = v[0].size();
	enum { NG, OK };
	vector<int>h(W, 0);
	int maxv = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (v[i][j] == OK)h[j]++;
			else h[j] = 0;
		}
		maxv = max(maxv, getLargestRectangle(h));
	}
	return maxv;
}
