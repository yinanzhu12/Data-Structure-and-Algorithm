void bfs(vector< vector<int> >& graph, vector<int>& parent, vector<int>& distance) {
	vector<int> visit(parent.size(), 0);
	queue<int> Q;
	Q.push(1);
	visit[1] = 1;
	while (!Q.empty()) {
		int root = Q.front();
		Q.pop();
		for (int i = 0; i<graph[root].size(); i++) {
			int child = graph[root][i];
			if (visit[child] == 0) {
				Q.push(child);
				visit[child] = 1;
				parent[child] = root;
				distance[child] = distance[root] + 1;
			}
		}
	}
	return;
}

int main() {
	int n;
	cin >> n;
	vector< vector<int> > graph(n + 1);
	for (int i = 0; i<n - 1; i++) {
		int v1;
		int v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	vector<int> parent(n + 1, -1);
	vector<int> distance(n + 1, 0);
	bfs(graph, parent, distance);
	return 0;
}