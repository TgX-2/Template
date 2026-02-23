struct fenwick {
    int n;
    vector<int> bit;

    fenwick(int _n) : n(_n) {
        bit.resize(n + 7, 0);
    }

    int get(int pos) {
        int ans = 0;
        for(; pos >= 1; pos -= pos & (-pos))
            ans += bit[pos];
        return ans;
    }

    void update(int pos, int val) {
        for(; pos <= n; pos += pos & (-pos))
            bit[pos] += val;
    }
};