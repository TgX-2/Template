class FenwickTree {
private:
    int n;
    vector<int> bit;

    int query(int pos) {
        int ans = 0;
        for(; pos >= 1; pos -= (pos & -pos)) ans += bit[pos];
        return ans;
    }

    void change(int pos, int val) {
        for(; pos <= n; pos += (pos & -pos)) bit[pos] += val;
    }

public:
    FenwickTree(int _n) {
        n = _n;
        bit.assign(n + 7, 0);
    }

    void update(int pos, int val) { change(pos, val); }
    void update(int l, int r, int val) {
        change(l, val);
        change(r + 1, -val);
    }
    int get(int l) { return query(l); }
    int get(int l, int r) { return query(r) - query(l - 1); }
};
