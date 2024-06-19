struct SegmentTreeLazy {
    struct Node {
        int val, lazy;
    };
    vector<Node> seg;
    int n;
    void down(int id) {
        int x = seg[id].lazy;
        seg[id << 1].val += x;
        seg[id << 1].lazy += x;
        seg[id << 1 | 1].val += x;
        seg[id << 1 | 1].lazy += x;
        seg[id].lazy = 0;
    }

    void build(int id, int l, int r, int data[], int f(int, int)) {
        if (l == r) return seg[id].val = data[l], void();
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

    SegmentTreeLazy(int n, int data[], int f(int, int)) : seg(n << 2 + 7), n(n) {
        build(1, 1, n, data, f);
    };
};
