string add(const string &x, const string &y) {
	int l = max(x.size(), y.size()) + 2;
	vector<int>a(l, 0), b(l, 0);
	rep(i, 0, x.size()) {
		a[i] = x[x.size() - 1 - i] - '0';
	}
	rep(i, 0, y.size()) {
		b[i] = y[y.size() - 1 - i] - '0';
	}
	rep(i, 0, l - 1) {
		b[i] += a[i];
		b[i + 1] += b[i] / 10;
		b[i] %= 10;
	}
	vector<int>c;
	int e = l;
	while (b[e - 1] == 0)e--;
	string ret;
	rep(i, 0, e) {
		ret.push_back('0' + b[i]);
	}
	reverse(all(ret));
	return ret;
}

auto comp = [](string x, string y)->bool {
		if (x.size() == y.size()) {
			rep(i, 0, x.size()) {
				if (x[i] != y[i])return x[i] < y[i];
			}
			return false;
		}
		else {
			return x.size() < y.size();
		}
	};