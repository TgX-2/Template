class DSURollback {
private:
    struct Query {
        int typ, u, v, time;
    };

    int cnt, curTime;
    vector<int> uf, ans;
    vector<Query> queries;
    vector<array<int, 3>> history;
    vector<map<int, int>> presentEdge;


    int find(int u) {
        while(uf[u] >= 0)
            u = uf[u];
        return u;
    }

    void join(int u, int v) {
        int a = find(u);
        int b = find(v);
        if (a == b) return;
        if (uf[a] > uf[b]) swap(a, b);
        history.push_back({a, b, uf[b]});
        uf[a] += uf[b];
        uf[b] = a;
        cnt--;
    }

    void rollback() {
        int u = history.back()[0];
        int v = history.back()[1];
        int w = history.back()[2];
        history.pop_back();
        uf[v] = w;
        uf[u] -= uf[v];
        cnt++;
    }

    void DnC(int l, int r) {
        if (l >= r) {
            if (l == r and queries[r].typ == 0)
                ans.pb(cnt);
            return;
        }

        int mid = (l + r) >> 1;
        int curSize = len(history);

        FOR(i, mid + 1, r) 
            if (queries[i].time < l)
                join(queries[i].u, queries[i].v);
        DnC(l, mid);
        while(len(history) > curSize) rollback();

        FOR(i, l, mid)
            if (queries[i].time > r)
                join(queries[i].u, queries[i].v);
        DnC(mid + 1, r);
        while(len(history) > curSize) rollback();
    }

    void add_edge(const int &u, const int &v) {
        presentEdge[u][v] = curTime++;
        queries.push_back({1, u, v, INT_MAX});
    }

    void remove_edge(const int &u, const int &v) {
        int insTime = presentEdge[u][v];
        queries.push_back({-1, u, v, insTime});
        queries[insTime].time = curTime++;
        presentEdge[u].erase(v);
    }

    void get_query() {
        queries.push_back({0, -1, -1, curTime++});
    }

public:
    DSURollback(int V) : curTime(0), cnt(V), uf(V, -1), presentEdge(V) {}

    void add(const int &u, const int &v) {
        add_edge(u, v);
    }

    void del(const int &u, const int &v) {
        remove_edge(u, v);
    }

    void get() {
        get_query();
    }

    vector<int> sol() {
        DnC(0, curTime - 1);
        return ans;
    }
};
