class SparseTable {
    int arr[loga][maxn];

    public:
    void build(const int data[], int n, int f(int, int)) { //O(NlogN)
        memcpy(arr[0], data, maxn * sizeof(int));
        for(int j = 1; (1 << j) <= n; j++)
            for(int i = 1; i + (1 << j) - 1 <= n; i++)
                arr[j][i] = f(arr[j - 1][i], arr[j - 1][i + (1 << (j - 1))]);
    }

    int get(int l, int r, int f(int, int)) { // O(1)
        int k = __lg(r - l + 1);
        return f(arr[k][l], arr[k][r - (1 << k) + 1]);
    }

    int get(int l, int r, int f(int, int)) { // O(logN)
        int ans = 0;
        for(int i = loga; i >= 0; i--) {
            if ((1 << i) <= r - l + 1) {
                ans = f(ans, arr[i][l]);
                l += (1 << i);
            }
        }
        return ans;
    }
};

int fmax(int x, int y) {return max(x, y); }
int fmin(int x, int y) {return min(x, y);}
int fgcd(int x, int y) {return __gcd(x, y);}
int fsum(int x, int y) {return x + y;}
