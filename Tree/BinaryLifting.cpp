int par[logg][maxn];
int lift[logg][maxn];
int dep[maxn];

void dfs(int u, int pre) {
    par[0][u] = pre;
    lift[0][u] = a[u];

    for(const int &v : g[u]) if (v != pre) {
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

inline int f(const int &x, const int &y) { return __gcd(x, y); }

int get(int u, int v) {
    int ans = 0;

    if (dep[u] < dep[v]) swap(u, v);
    FORD(k, logg - 1, 0) {
        if (dep[u] - (1 << k) >= dep[v]) {
            ans = f(ans, lift[k][u]);
            u = par[k][u];
        }
    }

    if (u == v) {
        ans = f(ans, a[u]);
        return ans;
    }

    FORD(k, logg - 1, 0) {
        if (par[k][u] != 0 and par[k][u] != par[k][v]) {
            ans = f(ans, lift[k][u]);
            ans = f(ans, lift[k][v]);
            u = par[k][u];
            v = par[k][v];
        }
    }

    ans = f(ans, a[u]);
    ans = f(ans, a[v]);
    ans = f(ans, a[par[0][u]]);

    return ans;
}


/*
Code trong main:
  dfs(1, 0);
  FOR(k, 1, logg - 1) {
      FOR(u, 1, n) {
          par[k][u] = par[k - 1][par[k - 1][u]];
          lift[k][u] = f(lift[k - 1][u], lift[k - 1][par[k - 1][u]]);
      }
  }
Lấy kết quả từ u -> v:
  get(u, v)
*/
