int inf = 1000000000;

class edge {
public:
	int w;
	int v;
	edge(int a, int b) {
		v = a;
		w = b;
	}
};

class vertice {
public:
	int v;
	int key;
	vertice(int a) {
		v = a;
		key = inf;
	}
};

vertice* extractmin(vector<vertice*>& h) {
	if (h.size() <= 1)return nullptr;
	vertice* t = h[1];
	int min = 1;
	for (int i = 2; i<h.size(); i++) {
		if (h[i]->key<t->key) {
			t = h[i];
			min = i;
		}
	}
	swap(h[min], h[h.size() - 1]);
	h.pop_back();
	return t;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i<t; i++) {
		int n;
		int m;
		cin >> n >> m;
		vector< vector<edge> > graph(n + 1);
		vector<vertice> vlist(n + 1, vertice(-1));
		vector<vertice*> unvisited(n + 1);
		for (int j = 1; j <= n; j++) {
			vlist[j].v = j;
			unvisited[j] = &vlist[j];
		}
		for (int j = 0; j<m; j++) {
			int x;
			int y;
			int r;
			cin >> x >> y >> r;
			graph[x].push_back(edge(y, r));
			graph[y].push_back(edge(x, r));
		}
		int s;
		cin >> s;
		vlist[s].key = 0;
		vector<int> visited(n + 1, 0);
		while (unvisited.size()>1) {
			vertice* nextv = extractmin(unvisited);
			int vlabel = nextv->v;
			/*for(int j=1;j<heap.size();j++)cout<<heap[j]->v<<" "<<heap[j]->key<<" ";
			cout<<endl;*/
			visited[vlabel] = 1;
			for (int j = 0; j<graph[vlabel].size(); j++)vlist[graph[vlabel][j].v].key = min(vlist[vlabel].key + graph[vlabel][j].w, vlist[graph[vlabel][j].v].key);
			/*for(int j=1;j<heap.size();j++)cout<<heap[j]->v<<" "<<heap[j]->key<<" ";
			cout<<endl;*/
		}
		for (int j = 1; j <= n; j++) {
			if (j != s) {
				if (vlist[j].key == inf)cout << -1 << " ";
				else cout << vlist[j].key << " ";
			}
		}
		cout << endl;
	}
	return 0;
}