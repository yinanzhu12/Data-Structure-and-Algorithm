#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

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

void maintain(vector<vertice*>& h, int root) {
	int left = 2 * root;
	int right = 2 * root + 1;
	if (left>h.size() - 1)return;
	else if (left == h.size() - 1) {
		if ((h[left]->key)<(h[root]->key)) {
			swap(h[root], h[left]);
		}
		else return;
	}
	else {
		if ((h[root]->key) <= (h[left]->key) && (h[root]->key) <= (h[right]->key))return;
		else if ((h[right]->key)>(h[left]->key)) {
			swap(h[root], h[left]);
			maintain(h, left);
		}
		else {
			swap(h[root], h[right]);
			maintain(h, right);
		}
	}
	return;
}

vertice* extractmin(vector<vertice*>& h) {
	if (h.size() == 1)return nullptr;
	swap(h[1], h[h.size() - 1]);
	vertice* t = h[h.size() - 1];
	h.pop_back();
	maintain(h, 1);
	return t;
}

void changekey(vector<vertice*>& h, int change, int newkey) {
	h[change]->key = newkey;
	while (change>1 && h[change]->key<h[change / 2]->key) {
		swap(h[change], h[change / 2]);
		change /= 2;
	}
	return;
}

void relax(vertice& v1, vertice& v2, edge& e, vector<vertice*>& heap, vector<int>& visited) {
	if (v2.key>v1.key + e.w) {
		if (visited[v2.v] == 1)v2.key = v1.key + e.w;
		else {
			for (int i = 1; i<heap.size(); i++) {
				if (heap[i]->v == v2.v) {
					changekey(heap, i, v1.key + e.w);
					break;
				}
			}
		}
	}
	return;
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
		vector<vertice*> heap(n + 1);
		for (int j = 1; j <= n; j++) {
			vlist[j].v = j;
			heap[j] = &vlist[j];
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
		vector<int> visited(n + 1, 0);
		changekey(heap, s, 0);
		while (heap.size()>1) {
			vertice* nextv = extractmin(heap);
			int vlabel = nextv->v;
			/*for(int j=1;j<heap.size();j++)cout<<heap[j]->v<<" "<<heap[j]->key<<" ";
			cout<<endl;*/
			visited[vlabel] = 1;
			for (int j = 0; j<graph[vlabel].size(); j++)relax(vlist[vlabel], vlist[graph[vlabel][j].v], graph[vlabel][j], heap, visited);
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
