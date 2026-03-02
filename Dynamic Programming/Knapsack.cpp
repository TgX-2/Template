/*
    DP Knapsack cơ bản là có 2 loại
    1: W <= 1e9
    2: v_i <= 1e9
    Tùy các bài mà cách code khác nhau
*/

// Loại 1: W <= 1e9 - maxn * maxv đủ bé
const int N = maxn * maxv;
for(int i = 0; i <= N; i++) dp[i] = 1e18;
dp[0] = 0;

for(int i = 1; i <= n; i++) for(int j = N; j >= 0; j--)
    if (dp[j] + w[i] <= W) 
        dp[j + v[i]] = min(dp[j + v[i]], dp[j] + w[i]);

for(int i = N; i >= 0; i--) {
    if (dp[i] != 1e18) return cout << i, void();
}

// Loại 2: v_i <= 1e9 - maxv * maxw đủ bé
int f[maxn][maxw];
int dp(int id, int curw) {
    if (curw > W) return -1e18;
    if (id > n) return 0;

    int &ans = f[id][curw];
    if (ans != -1) return ans;

    ans = max(dp(id + 1, curw), dp(id + 1, curw + w[id]) + v[id]);
    return ans;
}