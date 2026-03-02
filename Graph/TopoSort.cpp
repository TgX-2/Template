vector<int> topo;

queue<int> q;
for(int i = 1; i <= k; i++)
    if (deg[i] == 0) q.push(i);

while(!q.empty()) {
    int u = q.front(); q.pop();
    topo.pb(u);

    for(const int &v : g[u]) {
        deg[v]--;
        if (deg[v] == 0) q.push(v);
    }
}

reverse(topo.begin(), topo.end());
for(const int &val : topo) cout << val ___ ;