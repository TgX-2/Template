class LCA {
private:
    vector<int> euler, dep, fir;
    vector<vector<int>> st;
    int n;
    vector<int> h;

    void dfs(int u, int pre, int d, const vector<vector<int>> &g) {
        debug(u, pre);
        fir[u] = len(euler);
        euler.pb(u);
        dep.pb(d);
        h[u] = h[pre] + 1;
        
        for(const int &v : g[u]) if (v != pre) {
            dfs(v, u, d + 1, g);
            euler.pb(u);
            dep.pb(d);
        }
    }

    #define mmin(x, y) (dep[x] < dep[y] ? x : y)

    void buildSparseTable() {
        int m = len(dep);
        int maxK = log2(m) + 7;
        st.assign(m + 7, vector<int>(maxK));
        FOR(i, 0, m - 1) st[i][0] = i;

        for(int j = 1; (1 << j) <= m; j++) {
            for(int i = 0; i + (1 << j) <= m; i++) {
                st[i][j] = mmin(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int getSparseTable(int l, int r) {
        int k = r - l + 1;
        int logK = log2(k);

        return mmin(st[l][logK], st[r - (1 << logK) + 1][logK]);
    }

public:
    LCA(const vector<vector<int>> &g, int root = 1) {
        n = len(g);
        fir.assign(n + 7, -1);
        h.assign(n + 7, 0);
        dfs(root, -1, 0, g);
        buildSparseTable();
    }

    int getDis(int u, int v) {
        int k = getLCA(u, v);
        return h[u] + h[v] - 2 * h[k];
    }

    int getLCA(int u, int v) {
        int l = fir[u];
        int r = fir[v];
        if (l > r) swap(l, r);
        return euler[getSparseTable(l, r)];
    }
};
