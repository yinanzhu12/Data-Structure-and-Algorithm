#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
#define fi first
#define se second
#define matrix(a) vector< vector<a> >
#define sz(a) int((a).size()) 
#define lop(i,a,b) for (int i=a; i<=b; i++)
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define all(s) (s).begin(),(s).end()
#define pb push_back


void dfs(matrix(int)& alist, vi& ts, int root, vi& visited) {
	visited[root] = 1;
	for (auto child : alist[root]) {
		if (!visited[child]) dfs(alist, ts, child, visited);
	}
	ts.pb(root);
	return;
}

/*find the strongly connected component of a directed graph*/
int main() {
	matrix(int) alist, ralist;/*alist: the adjacency list of graph. ralist: the adjacency list of the graph with every edge reversed*/
	vi visited(sz(alist), 0), ts;
	lop(i, 1, sz(alist) - 1) {
		if (!visited[i])dfs(alist, ts, i, visited);
	}
	/*ts will be the topological order of nodes*/
	reverse(all(ts));
	visited.assign(sz(alist), 0);
	matrix(int) strcomp;
	for (auto i : ts) {
		if (!visited[i]) {
			vi component;
			dfs(ralist, component, i, visited);
			strcomp.pb(component);
		}
	}
	return 0;
}