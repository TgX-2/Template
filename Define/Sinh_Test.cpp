#include<bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 1e6 + 7;
string s; 
int n, q;

array<int, 3> seg[maxn << 2];

array<int, 3> merge(const array<int, 3> &a, const array<int, 3> &b) {
    int t = min(a[0], b[1]);
    array<int, 3> ans = {0, 0, 0};

    ans[2] = a[2] + b[2] + t;
    ans[0] = a[0] + b[0] - t;
    ans[1] = a[1] + b[1] - t;
}

void build(int id, int l, int r) {
    if (l == r) return seg[id] = {s[id] == '(', s[id] == ')', 0}, void();
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (v < l or r < u) return 0;
    if (u <= l and r <= v) return seg[id][0];
    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("temp.inp", "r")) {
        freopen("temp.inp", "r", stdin);
        freopen("temp.out", "w", stdout);
    }

    cin >> s;
    n = (int)(s.size()); s = " " + s;
    // build(1, 1, n);

    // cin >> q;
    // while(q--) {
    //     int l, r; cin >> l >> r;
    //     cout << get(1, 1, n, l, r) << "\n";
    // }

    cerr << "Time : " << clock() * 1.0 / CLOCKS_PER_SEC << " ms." << endl;
    return 0;
}