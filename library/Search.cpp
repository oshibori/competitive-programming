//例) l=-INF: false, r=INF: true または l=INF: false, r=-INF: true になるようにする

template<class F>
int binary_search_(int l, int r, F f) {
	if (f(l))return l; //exception f(l):true
	while (l + 1 < r) {
		int m = (l + r) / 2;
		if (f(m))
			r = m;
		else
			l = m;
	}
	//f(l):false, f(r):true
	return r;
}

template<class F>
double binary_search_(double l, double r, F f) {
	if (f(l))return l; //exception f(l):true
	for (int i = 0; i < 60; i++) { //ループの回数は適当
		double m = (l + r) / 2;
		if (f(m))
			r = m;
		else
			l = m;
	}
	return r; //f(l):false, f(r):true
}
