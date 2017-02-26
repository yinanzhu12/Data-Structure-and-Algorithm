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

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
#define matrix(a) vector< vector<a> >
#define lop(i,a,b) for (int i=a; i<=b; i++)
#define vlop(i,v) lop(i,0,sz(v)-1)
#define rlop(i,a,b) for (int i=b; i>=a; i--) 
#define all(s) (s).begin(),(s).end()
#define isthere(c,x) ((c).find(x) != (c).end()) 
#define cisthere(c,x) (find(all(c),x) != (c).end())
#define pb push_back
#define fill(s,v) memset(s,v,sizeof(s))
#define sz(a) int((a).size()) 
#define printv(v,i) lop(i,0,sz(v)-1)cout<<v[i]<<" ";

class edge {
public:
	int v;
	int w;
	edge(int a, int b) {
		v = a;
		w = b;
	}
	edge() {
		v = 0;
		w = 0;
	}
};

void dfs(matrix(edge)& alist, vi& tour, int root, vi& entry, vi& level, vi& dtoroot, int currentlevel, vi& visited) {
	visited[root] = 1;
	tour.pb(root);
	level.pb(currentlevel);
	entry[root] = sz(tour) - 1;
	vlop(i,alist[root]) {
		if (!visited[alist[root][i].v]) {
			dtoroot[alist[root][i].v] = dtoroot[root] + alist[root][i].w;
			dfs(alist, tour, alist[root][i].v, entry, level, dtoroot, currentlevel + 1, visited);
			tour.pb(root);
			level.pb(currentlevel);
		}
	}
	return;
}

int main() {
	int n;
	cin >> n;
	matrix(edge) alist(n + 1);
	lop(i, 1, n - 1) {
		int a;
		int b;
		int c;
		cin >> a >> b >> c;
		alist[a].pb(edge(b, c));
		alist[b].pb(edge(b, c));
	}
	vi tour; /*Euler tour*/
	vi dtoroot(n + 1, 0); /*distance to root from node i, for weighted diagram*/
	vi entry(n + 1); /*first time encounter node i in the euler tour*/
	vi level; /*the level of the ith stop of Euler tour*/
	vi visited(n + 1, 0);
	dfs(alist, tour, 1, enter, level, dtoroot, 0, visited);
	return 0;
}
