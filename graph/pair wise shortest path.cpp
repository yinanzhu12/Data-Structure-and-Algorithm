#include <vector>
using namespace std;

int inf = 10000000;/*greater than upper bound of path length*/
typedef vector< vector<int> > matrix;

void multiply(matrix& a, matrix& b) {
	int n = a.size();
	matrix l(n, vector<int>(n, inf));
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			for (int k = 1; k < n; k++) {
				l[i][j] = min(l[i][j], a[i][k] + b[k][j]);
			}
		}
	}
	a = l;
	return;
}

void floydwarshall(matrix& a) {
	int n = a.size();
	for (int i = 1; i <= n; i++) {
		matrix b=a;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				a[j][k] = min(a[j][k], b[j][i] + b[i][k]);
			}
		}
	}
	return;
}

int main() {
	/*graph with n vertices and m edges*/
	int n;
	int m;
	cin >> n >> m;
	matrix graph(n + 1, vector<int>(n + 1, inf));
	for (int j = 1; j <= n; j++)graph[j][j] = 0;
	for (int j = 0; j < m; j++) {
		int a;
		int b;
		int g;
		cin >> a >> b >> g;
		graph[a][b] = min(graph[a][b], g);
		graph[b][a] = graph[a][b];
	}
	matrix shortestpath = graph;
	int p = 1;
	/*find shortest path by multiplication*/
	while (p < n - 1) {
		multiply(shortestpath, shortestpath);
		p *= 2;
	}
	/*find shortest path by Floyd-Warshall algorithm*/
	shortestpath = graph;
	floydwarshall(shortestpath);
	return 0;
}