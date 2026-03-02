int cnt = 0, cau = 0, khop = 0;
int num[maxn], low[maxn];

void dfs(int u, int pre) {
	num[u] = low[u] = ++cnt;
	int node = (pre != 0);

	for(const int &v : g[u]) if (v != pre) {
		if (num[v]) mini(low[u], num[v]);
		else {
			dfs(v, u);
			mini(low[u], low[v]);
			if (low[v] == num[v]) cau++;
			if (low[v] >= num[u]) node++;
		}
	}

	if (node >= 2) khop++;
}


/*
Trong ham main:

FOR(i, 1, n) if (num[i] == 0) dfs(i, 0);
*/