struct SegmentTree {
    vector<int> seg;
    int n;

    void build(int id, int l, int r, int data[], int f(int, int)) {
        if (l == r) return seg[id] = data[l], void();
        int mid = (l + r) >> 1;
        build(id << 1, l, mid, data, f);
        build(id << 1 | 1, mid + 1, r, data, f);
        seg[id] = f(seg[id << 1], seg[id << 1 | 1]);
    }

    void update(int id, int l, int r, int pos, int val, int f(int, int)) {
        if (pos < l or r < pos) return;
        if (l == r) return seg[id] = val, void();
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, pos, val, f);
        update(id << 1 | 1, mid + 1, r, pos, val, f);
        seg[id] = f(seg[id << 1], seg[id << 1 | 1]);
    }

    int get(int id, int l, int r, int u, int v, int f(int, int)) {
        if (v < l or r < v) return 0;
        if (u <= l and r <= v) return seg[id];
        int mid = (l + r) >> 1;
        return f(get(id << 1, l, mid, u, v, f), get(id << 1 | 1, mid + 1, r, u, v, f));
    }

    void update(int pos, int val, int f(int, int)) {
        update(1, 1, n, pos, val, f);
    }

    int get(int l, int r, int f(int, int)) {
        return get(1, 1, n, l, r, f); 
    }

    SegmentTree(int n, int data[], int f(int, int)) : n(n), seg(n << 2 + 7) {
        build(1, 1, n, data, f);
    }; 
};
