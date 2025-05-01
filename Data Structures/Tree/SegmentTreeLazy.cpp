class SegmentTreeLazy {
private:
    vector<int> seg, lazy;
    int n;

    bool isSum = 0;
    int returnNum = 0;
    function<int(int, int)> f;

    void down(int id, int l, int r) {
        if (lazy[id] == 0) return;
        int mid = (l + r) >> 1;
        int lenL = mid - l + 1;
        int lenR = r - mid;

        if (isSum) {
            seg[id << 1] += lazy[id] * lenL;
            seg[id << 1 | 1] += lazy[id] * lenR;
        } else {
            seg[id << 1] += lazy[id];
            seg[id << 1 | 1] += lazy[id];
        }

        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
        lazy[id] = 0;
    }


    void build(int id, int l, int r, const int a[]) {
        if (l == r) return seg[id] = a[l], void();
        int mid = (l + r) >> 1;
        build(id << 1, l, mid, a);
        build(id << 1 | 1, mid + 1, r, a);
        seg[id] = f(seg[id << 1], seg[id << 1 | 1]);
    }

    void update(int id, int l, int r, int u, int v, int val) {
        if (v < l or r < u) return;
        if (u <= l and r <= v) {
            seg[id] += isSum ? val * (r - l + 1) : val;
            lazy[id] += val;
            return;
        }

        down(id, l, r);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        seg[id] = f(seg[id << 1], seg[id << 1 | 1]);
    }

    int get(int id, int l, int r, int u, int v) {
        if (v < l or r < u) return returnNum;
        if (u <= l and r <= v) return seg[id];
        down(id, l, r);
        int mid = (l + r) >> 1;
        return f(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }

public:
    SegmentTreeLazy(int _n, const int a[], string typ = "sum", int retNum = 0) {
        n = _n;
        returnNum = retNum;
        isSum = (typ == "sum");
        seg.resize((n << 2) + 7);
        lazy.resize((n << 2) + 7);

        if (isSum) f = [](int a, int b) { return a + b; };
        else if (typ == "max") f = [](int a, int b) { return max(a, b); };
        else if (typ == "min") f = [](int a, int b) { return min(a, b); };

        build(1, 1, n, a);
    }

    void update(int l, int r, int val) {
        update(1, 1, n, l, r, val);
    }

    int get(int l, int r) {
        return get(1, 1, n, l, r);
    }
};

/*==============================+

[Constructor]
SegmentTreeLazy seg(n, a, typ);

- n    : number of elements
- a    : input array (1-based index)
- typ  : string to determine function
         + "sum" => range sum
         + "max" => range maximum
         + "min" => range minimum
         
+------------------------------+

[Update Range]
seg.update(l, r, val);
- Adds `val` to all elements in range [l, r]

+------------------------------+

[Query Range]
seg.get(l, r);

- Returns the result in range [l, r]
  according to the operation type:
    + sum / max / min

===============================*/
