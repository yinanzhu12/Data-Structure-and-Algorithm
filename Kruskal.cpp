#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class edge {
public:
	int w;
	int v1;
	int v2;
	int vsum;
	edge(int a, int b, int c) {
		v1 = a;
		v2 = b;
		w = c;
		vsum = a + b;
	}
};

bool compareedge(edge e1, edge e2) { 
	if (e1.w == e2.w)return(e1.vsum<e2.vsum);
	return (e1.w < e2.w);
}

int main() {
	int n;
	cin >> n;
	vector<int> rep(n+1);
	for (int i = 0; i<rep.size(); i++)rep[i] = i;
	int m;
	cin >> m;
	vector<edge> graph;
	for (int i = 0; i<m; i++) {
		int v1;
		int v2;
		int w;
		cin >> v1 >> v2 >> w;
		edge e(v1, v2, w);
		graph.push_back(e);
	}
	sort(graph.being(),graph.end(),compareedge);
	long long int totalweight = 0;
	for (int i = 0; i<m; i++) {
		if (rep[graph[i].v1] != rep[graph[i].v2]) {
			totalweight += graph[i].w;
			int oldrep = max(rep[graph[i].v1], rep[graph[i].v2]);
			int newrep = min(rep[graph[i].v1], rep[graph[i].v2]);
			for (int j = 1; j<n + 1; j++) {
				if (rep[j] == oldrep)rep[j] = newrep;
			}
		}

	}
	cout << totalweight;
}
