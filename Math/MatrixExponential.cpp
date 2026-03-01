const int mod = 1e9 + 7;
using mat = vector<vector<int>>;

// O(nm)
mat add(mat a, const mat &b) {
    int n = (int)(a.size());
    int m = (int)(a[0].size());
    for(int i = 0; i <= n - 1; i++)
        for(int j = 0; j <= m - 1; j++)
            a[i][j] = (a[i][j] + b[i][j]) % mod;
    return a;
}

// O(n^3)
mat mul(const mat &a, const mat &b) {
    int n = (int)(a.size());
    int m = (int)(b[0].size());
    int p = (int)(b.size()); // == a[0].size()

    mat c(n, vector<int>(m, 0));
    for(int i = 0; i <= n - 1; i++)
        for(int j = 0; j <= m - 1; j++)
            for(int k = 0; k <= p - 1; k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j] % mod) % mod;
    return c;
}

// O(n^3 kog k)
mat exp(const mat &a, int k) {
    int n = (int)(a.size());

    mat ans(n, vector<int>(n, 0));
    for(int i = 0; i <= n - 1; i++)
        ans[i][i] = 1;

    mat base = a;
    while(k > 0) {
        if (k & 1) ans = mul(ans, base);
        base = mul(base, base);
        k >>= 1;
    }

    return ans;
}