struct DisjointSetUnion {
    vpii val;
    DisjointSetUnion(int n) : val(n + 7) {
        FOR(i, 1, n)
            val[i] = {i, 1};
    };

    int find(int u) {
        return (u == val[u].fi ? u : val[u].fi = find(val[u].fi));
    }

    bool connected(int x, int y) {
        return (find(x) == find(y));
    }

    void merge(int u, int v) {
        int a = find(u);
        int b = find(v);
        if (a != b) {
            if (val[a].se < val[b].se) swap(a, b);
            val[b].fi = a;
            val[a].se += val[b].se;
        }
    }
};
