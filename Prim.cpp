#include <cmath>
#include <fstream>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


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
	vertice(int a, int b) {
		v = a;
		key = b;
	}
	vertice() {
		v = 0;
		key = 0;
	}
};

void maintain(vector<vertice>& h, int root) {
	int left = 2 * root;
	int right = 2 * root + 1;
	vertice t;
	if (left>h.size()-1)return;
	else if (left == h.size()-1) {
		if (h[left].key<h[root].key) {
			swap(h[root],h[left]);
		}
		else return;
	}
	else {
		if (h[root].key<=h[left].key && h[root].key<=h[right].key)return;
		else if (h[right].key>h[left].key) {
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

vertice extractmin(vector<vertice>& h) {
	if (h.size() == 1)return v();
	swap(h[1],h[h.size()-1]);
	vertice t = h[h.size() - 1];
	heap.pop_back();
	maintain(h, 1);
	return t;
}

void changekey(vector<vertice>& h, int change, int newkey) {
	h[change].key = newkey;
	vertice t;
	while (change>1 && h[change].key<h[change / 2].key) {
		swap(h[change],h[change/2]);
		change /= 2;
	}
	return;
}

int main() {
	ifstream cin("input.txt");
	int n;
	cin >> n;
	int m;
	cin >> m;
	int inf = 100001;
	vector< vector<edge> > graph(n + 1);
	vector<vertice> heap;
	heap.push_back(vertice(0, 0));
	for (int i = 0; i<m; i++) {
		int a;
		int b;
		int c;
		cin >> a >> b >> c;
		graph[a].push_back(edge(b, c));
		graph[b].push_back(edge(a, c));
	}
	int s;
	cin >> s;
	heap.push_back(vertice(s, 0));
	vector<int> intree(n+1,0);
	for (int i = 1; i <= n; i++) {
		if (i != s) {
			heap.push_back(vertice(i, inf));
		}
	}
	long long int sum = 0;
	while (heap.size() != 1) {
		vertice newv = extractmin(heap);
		cout << newv.v<<" "<<newv.key<< endl;
		sum += newv.key;
		intree[newv.v] = true;
		for (int i = 0; i<graph[newv.v].size(); i++) {
			if (!intree[graph[newv.v][i].v]) {
				for (int j = 1; j<heap.size(); j++) {
					if (heap[j].v == graph[newv.v][i].v && heap[j].key>graph[newv.v][i].w) {
						changekey(heap.begin(), j, graph[newv.v][i].w);
						break;
					}
				}
			}
		}
	}
	cout << sum;
	return 0;
}