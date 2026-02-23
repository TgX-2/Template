vector<int> euler, dep;
int h[maxn], fir[maxn];
void dfs(int u, int pre, int d) {
    fir[u] = len(euler);
    euler.pb(u);
    dep.pb(d);

    for(const int &v : g[u]) if (v != pre) {
        dfs(v, u, d + 1);
        euler.pb(u);
        dep.pb(d);
    }
}

int st[30][maxn << 1];
#define mmin(i, j) (dep[i] < dep[j] ? i : j)

void build() {
    int m = len(euler);
    FOR(i, 0, m - 1) st[0][i] = i;

    for(int j = 1; (1 << j) <= m; j++)
        for(int i = 0; i + (1 << j) + 1 <= m; i++)
            st[j][i] = mmin(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}

int getst(int l, int r) {
    int k = __lg(r - l + 1);
    return mmin(st[k][l], st[k][r - (1 << k) + 1]);
}

int getlca(int u, int v) {
    int l = fir[u];
    int r = fir[v];
    if (l > r) swap(l, r);
    return euler[getst(l, r)];
}


/*
Trong code main
dfs(1, 0, 0);
buildst();
Lấy LCA của đỉnh u -> v, sử dụng:
getlca(u, v);
*/
