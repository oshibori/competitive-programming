int longest_increasing_subsequence(const vector<int> &v) {
	// これまで出てきた中で、k枚の部分列が作れるもののうち、最も値が小さいものを持つ
	int n = v.size();
	vector<int> dp(n, INF);
	for (int i = 0; i < n; i++)
		*lower_bound(dp.begin(), dp.end(), v[i]) = v[i];
	return find(dp.begin(), dp.end(), INF) - dp.begin();
}