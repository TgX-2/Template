int child[maxn], par[maxn];
void dfs(int u, int pre) {
    child[u] = 1;
    par[u] = pre;

    for(const int &v : g[u]) if (v != pre) {
        dfs(v, u);
        child[u] += child[v];
    }
}

int hld[maxn], hldd[maxn], dep[maxn], sta[maxn], pos[maxn], cnt = 1;
void buildHld(int u, int pre, bool inChain) {
    hldd[u] = hldd[pre];
    dep[u] = dep[pre] + 1;
    hld[cnt] = u;
    pos[u] = cnt;
    sta[u] = cnt++;
    if (inChain) sta[u] = sta[pre];
    else hldd[u]++;

    int bigChild = -1;
    for(const int &v : g[u]) if (v != pre) 
        if (bigChild == -1 or child[bigChild] < child[v]) 
            bigChild = v;

    if (bigChild != -1) buildHld(bigChild, u, 1);
    for(const int &v : g[u]) if (v != pre and v != bigChild)
        buildHld(v, u, 0);
}

inline int hldpos(const int &u) { return pos[hld[sta[u]]]; }
inline int hldpar(const int &u) { return par[hld[sta[u]]]; }
inline int f(const int &x, const int &y) { return max(x, y); }

int lca(int u, int v) {
    if (hldd[u] < hldd[v]) swap(u, v);
    while(hldd[u] > hldd[v]) u = hldpar(u);

    while(sta[u] != sta[v]) {
        u = hldpar(u);
        v = hldpar(v);
    }

    if (dep[u] > dep[v]) swap(u, v);
    return u;
}

/*
Code Lazy Segment Tree theo f(x, y)
update(id, l, r, u, v, val)
get(1, 1, n, u, v)
*/

void updatePath(int u, int v, int val) {
    int k = lca(u, v);
    while(sta[u] != sta[k]) {
        update(1, 1, n, hldpos(u), pos[u], val);
        u = hldpar(u);
    }

    while(sta[v] != sta[k]) {
        update(1, 1, n, hldpos(v), pos[v], val);
        v = hldpar(v);
    }

    if (dep[u] > dep[v]) swap(u, v);
    update(1, 1, n, pos[u], pos[v], val);
}

int getPath(int u, int v) {
    int ans = 0; // tuy chinh theo yeu cau de
    int k = lca(u, v);

    while(sta[u] != sta[k]) {
        ans = f(ans, get(1, 1, n, hldpos(u), pos[u]));
        u = hldpar(u);
    }

    while(sta[v] != sta[k]) {
        ans = f(ans, get(1, 1, n, hldpos(v), pos[v]));
        v = hldpar(v);
    }

    if (dep[u] > dep[v]) swap(u, v);
    ans = f(ans, get(1, 1, n, pos[u], pos[v]));
    return ans;
}
