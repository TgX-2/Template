struct Matrix {
    int n, m;
    vector <vector <int> > x;

    vector<int> & operator[] (int i) { return x[i]; }

    Matrix(int r, int c) : x(r, vector <int> (c)), n(r), m(c) { }

    Matrix(const vector<vector<int>> &x) : x(x), n(x.size()), m(x[0].size()) { }

    Matrix operator* (Matrix &b) {
        Matrix& a = *this;
        assert(a.m == b.n);
        Matrix c(a.n, b.m);
        for (int i = 0; i < a.n; ++i)
            for (int j = 0; j < b.m; ++j)
                for (int k = 0; k < a.m; ++k){
                    c[i][j] += 1ll * a[i][k] * b[k][j] % mod;
                    c[i][j] %= mod;
                }
        return c;
    }

    Matrix pow(long long exp) {
        assert(n == m);
        Matrix base = *this, ans = Matrix(n, n);
        for(int i=0; i<n; i++) ans[i][i] = 1;
        for (; exp > 0; exp >>= 1, base = base * base)
            if (exp & 1) ans = ans * base;
        return ans;
    }
};

ostream& operator<< (ostream &out, const Matrix &d) {
    for (auto a : d.x) {
        for (auto b : a) out << b << ' ';
        out << '\n';
    }
    return out;
}
