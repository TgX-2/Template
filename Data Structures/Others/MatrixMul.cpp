template<class T> class Matrix {
private: 
    int n, m;
    vector <vector <T> > x;

public: 
    vector<T> & operator[] (int i) { return x[i]; }
    const vector<T> & operator[] (int i) const { return x[i]; }

    Matrix(int r, int c) : x(r, vector <T> (c)), n(r), m(c) { }
    Matrix(const vector<vector<T>> &x) : x(x), n(x.size()), m(x[0].size()) { }

    Matrix operator+ (const Matrix &b) {
        Matrix ans(m, n);
        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++)
                (ans[i][j] = x[i][j] + b[i][j]) %= mod;
        return ans;
    }

    Matrix operator* (const Matrix &b) {
        Matrix& a = *this;
        assert(a.m == b.n);
        Matrix c(a.n, b.m);
        for (int i = 0; i < a.n; ++i)
            for (int j = 0; j < b.m; ++j)
                for (int k = 0; k < a.m; ++k)
                    (c[i][j] += a[i][k] * b[k][j] % mod) %= mod;
        return c;
    }

    Matrix operator^ (int exp) {
        assert(n == m);
        Matrix base = *this;
        Matrix ans(n, n);
        for(int i=0; i<n; i++) ans[i][i] = 1;
        for (; exp > 0; exp >>= 1, base = base * base)
            if (exp & 1) ans = ans * base;
        return ans;
    }

    friend ostream & operator << (ostream &out, const Matrix &d) {
        for (auto a : d.x) {
            for (auto b : a) out << b << ' ';
            out << '\n';
        }
        return out;
    }
};
