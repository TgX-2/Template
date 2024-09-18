struct LCA {
    vector<int> euler;
    int h[maxn], d[maxn];

    int val[maxn], cnt = 0;
    void dfs(int u, int pre = 0) {
        d[u] = len(euler);
        euler.pb(u);
        h[u] = ++cnt;
        for(const int &v: g[u]) if (v != pre) {
            dfs(v, u);
            euler.pb(u);
        }
    }

    #define mmin(x, y) ((h[x] < h[y]) ? x : y)
    int st[20][maxn << 1];
    void build() {
        int m = len(euler);
        FOR(i, 0, m - 1)
            st[0][i] = euler[i];

        for(int j = 1; (1 << j) <= m; j++)
            for(int i = 1; i + (1 << j) - 1 < m; i++)
                st[j][i] = mmin(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
    }

    int get(int l, int r) {
        int k = __lg(r - l + 1);
        return mmin(st[k][l], st[k][r - (1 << k) + 1]);
    }

    int lca(int u, int v) {
        int l = d[u], r = d[v];
        if (l > r) swap(l, r);
        return get(l, r);
    }

    LCA(int n) {
        dfs(1);
        build();
    }
};
