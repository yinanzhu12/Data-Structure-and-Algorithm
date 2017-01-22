#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int inf = 1000000000;

class edge {
public:
	int weight;
	int vertice;
	edge(int a, int b) {
		vertice = a;
		weight = b;
	}
};

class vertice {
public:
	int name;
	int key;
	vertice(int a) {
		name = a;
		key = inf;
	}
	vertice() {
		name = 0;
		key = inf;
	}
	bool operator < (const vertice& v) const {
		if (key != v.key) return key<v.key;
		return name<v.name;
	}
};

int main() {
		int n;
		int m;
		cin >> n >> m;
		vector< vector<edge> > graph(n + 1);
		vector<vertice> vlist(1);
		set<vertice> q;
		for (int j = 1; j <= n; j++) {
			vlist.push_back(vertice(j));
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
		q.insert(vlist[s]);
		vector<int> intree(n + 1, 0);
		while (!q.empty()) {
			vertice v1 = *q.begin();
			q.erase(q.begin());
			intree[v1.name] = 1;
			for (int j = 0; j<graph[v1.name].size(); j++) {
				vertice v2 = vlist[graph[v1.name][j].vertice];
				if (intree[v2.name] == 0) {
					if (graph[v1.name][j].weight + v1.key<v2.key) {
						if (v2.key != inf) {
							q.erase(q.find(v2));
						}
						vlist[v2.name].key = graph[v1.name][j].weight + v1.key;
						q.insert(vlist[v2.name]);
					}
				}
			}
		}
	return 0;
}
