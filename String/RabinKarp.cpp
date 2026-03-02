const int mod[3] = {(119 * (1 << 23) + 1), 1000000007, 1000000009};
const int base = 100003;

int harsh[3][maxn];
int poww[3][maxn];
void RabinKarp(const string &s) {
    poww[0][0] = poww[1][0] = poww[2][0] = 1;
    for(int i = 1; i <= n; i++) for(int j = 0; j <= 2; j++) 
            poww[j][i] = (poww[j][i - 1] * base) % mod[j];

    for(int i = 1; i <= n; i++) for(int j = 0; j <= 2; j++) {
        harsh[j][i] = (harsh[j][i - 1] * base + (s[i] - 'a') + 1) % mod[j];
    }
}

array<int, 3> get(int l, int r) {
    array<int, 3> ans;
    for(int j = 0; j <= 2; j++) 
        ans[j] = (harsh[j][r] - harsh[j][l - 1] * poww[j][r - l + 1] + mod[j] * mod[j]) % mod[j];
    return ans;
}