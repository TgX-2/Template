struct val {
    int v, f, c;
};

struct Dinic {
    int n, m, s, t;
    int work[maxn], d[maxn];
    vector<val> edge;
    vector <int> g[maxn];

    Dinic(int n, int m, int s, int t) : n(n), m(m), s(s), t(t) {}
    
    void add_edge (int u, int v, int c1, int c2){
        edge.pb({v, 0, c1});
        g[u].pb(edge.size() - 1);
        edge.pb({u, 0, c2});
        g[v].pb(edge.size() - 1);
    }
    
    bool bfs(){
        memo(d, 0); d[s] = 1;
        queue<int> q; q.push(s);

        while (!q.empty()){
            int top = q.front(); q.pop();
            for (int x : g[top]){
                int v = edge[x].v;
                if (d[v] == 0 and edge[x].c > edge[x].f){
                    d[v] = d[top] + 1;
                    q.push(v);
                }
            }
        }
        return d[t];
    }
    
    int dfs(int u, int flow){
        if (u == t) return flow;
        for (int &z = work[u]; z < g[u].size(); z++){
            int i = g[u][z];
            int v = edge[i].v;
            if (d[v] == d[u] + 1 and edge[i].c > edge[i].f){
                int tmp = dfs(v, min(flow, edge[i].c - edge[i].f));
                if (tmp) {
                    edge[i].f += tmp;
                    edge[i^1].f -= tmp;
                    return tmp;
                }
            }
        }
        return 0;
    }

    int max_flow(){
        int ans = 0;
        while (bfs()){
            FOR(i, 1, n)
                work[i] = 0;
            while (int tmp = dfs(s, intmax))
                ans += tmp; 
        }
        return ans;
    }
};
