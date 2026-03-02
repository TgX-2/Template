int dis[maxn];

void bfs01(int sta) {
	for(int i = 1; i <= n; i++) dis[i] = 1e18;
	dis[sta] = 0;

	deque<int> dq;
	dq.push_front(sta);

	while(!q.empty()) {
		int u = dq.front(); dq.pop_front();

		for(const pair<int, int> &val : g[u]) {
			int v = val.first, w = val.second;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if (w == 0) dq.push_front(v);
				else dq.push_back(v);		
			}
		}
	}
}