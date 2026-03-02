int cnt = 0, scc = 0;
int num[maxn], low[maxn], comp[maxn];
bool in_stack[maxn];
stack<int> st;

void dfs(int u) {
    num[u] = low[u] = ++cnt;
    st.push(u);
    in_stack[u] = 1;

    for (const int &v : g[u]) {
        if (!num[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], num[v]);
        }
    }

    if (low[u] == num[u]) {
        scc++;
        while (true) {
            int v = st.top(); st.pop();
            in_stack[v] = false;
            comp[v] = scc;
            if (v == u) break;
        }
    }
}

/*
Trong ham main:

FOR(i, 1, n) if (num[i] == 0) dfs(i, 0);
*/