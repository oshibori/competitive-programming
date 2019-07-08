//http://drken1215.hatenablog.com/entry/2019/03/20/202800


// using Num = unsigned long long;
template <typename Num> struct Matrix {
  vector<vector<Num>> v;
  Matrix() {}
  Matrix(int n, int m) : v(n, vector<Num>(m)) { assert(n > 0 and m > 0); }
  inline int height() const { return (int)v.size(); }
  inline int width() const { return (int)v[0].size(); }
  inline Num &at(int i, int j) {
    assert(0 <= i and i < height() and 0 <= j and j < width());
    return v[i][j];
  }
  inline const Num &at(int i, int j) const {
    assert(0 <= i and i < height() and 0 <= j and j < width());
    return v[i][j];
  }
  inline vector<Num> &operator[](int x) {
    assert(0 <= x and x < height());
    return v[x];
  }
  inline const vector<Num> &operator[](int x) const {
    assert(0 <= x and x < height());
    return v[x];
  }
  static Matrix identity(int n) {
    Matrix A(n, n);
    for (int i = 0; i < n; i++)
      A.at(i, i) = 1;
    return A;
  }
  inline static Matrix identity(const Matrix &A) {
    return identity(A.height());
  }
  Matrix operator*(const Matrix &B)const { return Matrix(*this) *= B; }
  Matrix &operator*=(const Matrix &B) {
		int n = height(), m = B.width(), p = B.height();
		Matrix C(*this);
		assert(p == width());
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				Num x = 0;
				for (int k = 0; k < p; k++)
					x += at(i, k) * B.at(k, j);
				C.at(i, j) = x;
			}

		return (*this) = C;
	}
};
template <typename Num>
Matrix<Num> operator^(const Matrix<Num> &m, long long exponent) {
  Matrix<Num> A = m, B = Matrix<Num>::identity(m);
  while (exponent) {
    if (exponent & 1)
      B *= A;
    A *= A;
    exponent >>= 1;
  }
  return B;
}

//* => &(and), + => ^(xor)
using Num = unsigned long long;
struct Matrix {
  vector<vector<Num>> v, w;
  Matrix() {}
  Matrix(int n, int m) : v(n, vector<Num>(m)) {}
  inline int height() const { return (int)v.size(); }
  inline int width() const { return (int)v[0].size(); }
  inline Num &at(int i, int j) { return v[i][j]; }
  inline const Num &at(int i, int j) const { return v[i][j]; }
  static Matrix identity(int n) {
    Matrix A(n, n);
    for (int i = 0; i < n; i++)
      A.at(i, i) = ~0U;
    return A;
  }
  inline static Matrix identity(const Matrix &A) {
    return identity(A.height());
  }
  Matrix &operator*=(const Matrix &B) {
    int n = height(), m = B.width(), p = B.height();
    assert(p == width());
    w.assign(n, vector<Num>(m, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        Num x = 0;
        for (int k = 0; k < p; k++)
          x ^= at(i, k) & B.at(k, j);
        w[i][j] = x;
      }
    v.swap(w);
    return *this;
  }
};
Matrix operator^(const Matrix &m, long long exponent) {
  Matrix A = m, B = Matrix::identity(m);
  while (exponent) {
    if (exponent & 1)
      B *= A;
    A *= A;
    exponent >>= 1;
  }
  return B;
}
