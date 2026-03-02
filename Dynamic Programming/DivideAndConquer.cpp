/*
    Gọi hàm cost là f(x, y)
    DP DNC chỉ đúng khi và chi khi:
        f(a, c) + f(b, d) <= f(a, d) + f(b, c)
    với a <= b <= c <= d
*/

int dp[2][maxn];
int now;

inline int cost(int l, int r) {}

void dnc(int l, int r, int optl, int optr) {
    if (l > r) return;
    int mid = (l + r) >> 1;
    pair<int, int> best = {-1e18, -1};

    for(int i = optl; i <= min(mid - 1, optr); i++) {
        int cur = dp[now ^ 1][i] + cost(i + 1, mid);
        if (cur > best.fi) best = {cur, i};
    }

    dp[now][mid] = best.fi;
    int opt = best.se;
    if (opt == -1) return;

    dnc(l, mid - 1, optl, opt);
    dnc(mid + 1, r, opt, optr);
}

// Code trong main
for(int i = 0; i <= n; i++) dp[0][i] = (i == 0 ? 0 : -1e18);
for(int id = 1; id <= k; id++) {
    now = id % 2;
    dnc(1, n, 0, n - 1);
}

cout << dp[k % 2][n];
