struct HeavyLightDecomposition {
    int child[maxn], par[maxn];
    int hld[maxn], hldd[maxn], dep[maxn], id[maxn], fin[maxn], sta[maxn];
    int inn[maxn], out[maxn];
    int cnt = 1, cntt = 0, n;
    
    void dfs(int u, int pre) {
        child[u] = 1;
        par[u] = pre;
        for(int v : g[u]) if (v != pre) {
            dfs(v, u);
            child[u] += child[v];
        }
    }

    void build_hld(int u, int pre, bool inchain) {
        hldd[u] = hldd[pre];
        if (!inchain) hldd[u]++;
        dep[u] = dep[pre] + 1;

        hld[cnt] = u;
        id[u] = cnt;        
        sta[u] = cnt++;
        if (inchain) sta[u] = sta[pre];

        inn[u] = ++cntt;

        int c = -1;
        for(int v : g[u]) if (v != pre) 
            if (c == -1 or child[v] > child[c])
                c = v;
        
        if (c != -1)
            build_hld(c, u, 1);
        for(int v : g[u]) if (v != pre and v != c)
            build_hld(v, u, 0);

        if (c == -1) fin[u] = cnt - 1;
        else fin[u] = fin[c];

        out[u] = cntt;
    }

    int hldpar(int u) {
        return par[hld[sta[u]]];
    }
    
    int hldpos(int u) {
        return id[hld[sta[u]]];
    }

    int lca(int u, int v) {
        if (hldd[v] > hldd[u]) swap(u, v);
        while(hldd[u] > hldd[v])
            u = hldpar(u);
        while(sta[u] != sta[v]) {
            u = hldpar(u);
            v = hldpar(v);
        }

        if (dep[u] > dep[v])
            swap(u, v);
        return u;
    }

    vector<pair<int, int>> decompose(int u, int v) {
        vector<pair<int, int>> ans;
        while(sta[u] != sta[v]) {
            if (hldd[u] > hldd[v]) {
                ans.pb({sta[u], sta[v]});
                u = hldpar(u);
            } else {
                ans.pb({sta[v], sta[u]});
                v = hldpar(v);
            }
        }

        if (dep[u] > dep[v]) swap(u, v);
        ans.pb({id[u], id[v]});
        return ans;
    }

    void build() {
        dfs(1, 0);
        build_hld(1, 0, 0);
    }
} hld;

struct SegmentTreeLazy {
    struct Node {
        int val, lazy;
    };
    Node seg[maxn << 2];
    void down(int id) {
        int x = seg[id].lazy;
        seg[id << 1].val += x;
        seg[id << 1].lazy += x;
        seg[id << 1 | 1].val += x;
        seg[id << 1 | 1].lazy += x;
        seg[id].lazy = 0;
    }

    void build(int id, int l, int r, int data[], int f(int, int)) {
        if (l == r) return seg[id].val = data[hld.hld[l]], void();
        int mid = (l + r) >> 1;
        build(id << 1, l, mid, data, f);
        build(id << 1 | 1, mid + 1, r, data, f);
        seg[id].val = f(seg[id << 1].val, seg[id << 1 | 1].val);
    }

    void update(int id, int l, int r, int u, int v, int val, int f(int, int)) {
        if (v < l or r < u) return;
        if (u <= l and r <= v) {
            seg[id].val += val;
            seg[id].lazy += val;
            return;
        }
        down(id);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val, f);
        update(id << 1 | 1, mid + 1, r, u, v, val, f);
        seg[id].val = f(seg[id << 1].val, seg[id << 1 | 1].val);
    }

    int get(int id, int l, int r, int u, int v, int f(int, int)) {
        if (v < l or r < u) return 0;
        if (u <= l and r <= v) return seg[id].val;
        down(id);
        int mid = (l + r) >> 1;
        return f(get(id << 1, l, mid, u, v, f), get(id << 1 | 1, mid + 1, r, u, v, f));
    }

    void update(int l, int r, int val, int f(int, int)) {
        update(1, 1, n, l, r, val, f);
    }

    int get(int l, int r, int f(int, int)) {
        return get(1, 1, n, l, r, f);
    }

} st;

int q_get(int u, int v, int f(int, int)) {
	int k = hld.lca(u, v);
	int ans = 0;
	while(hld.sta[u] != hld.sta[k]) {
		f(ans, st.get(hld.hldpos(u), hld.id[u], f));
		u = hld.hldpar(u);
	}
	while(hld.sta[v] != hld.sta[k]) {
		f(ans, st.get(hld.hldpos(v), hld.id[v], f));
		v = hld.hldpar(v);
	}
	if (hld.dep[u] < hld.dep[v])
		f(ans, st.get(hld.id[u], hld.id[v], f));
	else  
		f(ans, st.get(hld.id[v], hld.id[u], f));
	return ans;
}

void q_update(int u, int v, int val, int f(int, int)) {
    while(hld.sta[u] != hld.sta[v]) {
        if (hld.hldd[u] > hld.hldd[v]) swap(u, v);
        st.update(hld.hldpos(v), hld.id[v], val, f);
        v = hld.hldpar(v);
    }
    if (hld.dep[u] > hld.dep[v]) swap(u, v);
    st.update(hld.id[u], hld.id[v], val, f);
}

/*
q_update(u, v, val, f)                     : Moi dinh tu u -> v += val
q_get(u, v, f)                             : Tra ve dap an tu u -> v
st.update(hld.inn[u], hld.out[u], val, f)  : Moi dinh thuoc cay con goc u += val
st.get(hld.inn[u], hld.out[u], f)          : Tra ve dap an cay con goc u
*/
