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
typedef vector<long> vl;
typedef long long ll;
typedef pair<long long, long long> llll;
typedef vector<long long> vll;
#define matrix(a) vector< vector<a> >
#define sz(a) int((a).size()) 
#define lop(i,a,b) for (int i=a; i<=b; i++)
#define vlop(i,v) lop(i,0,sz(v)-1)
#define vlop1(i,v) lop(i,1,sz(v)-1)
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define vrlop(i,v) rlop(i,0,sz(v)-1)
#define vrlop1(i,v) rlop(i,1,sz(v)-1)
#define printv(i,v) vlop(i,v)cout<<v[i]<<" "
#define all(s) (s).begin(),(s).end()
#define isthere(c,x) ((c).find(x) != (c).end()) 
#define cisthere(c,x) (find(all(c),x) != (c).end())
#define pb push_back
#define enter cout<<'\n'

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

void dfs(matrix(edge)& alist, vi& tour, int root, vi& entry, vi& leave, vi& dtoroot, vi& visited) {
	visited[root] = 1;
	tour.pb(root);
	entry[root] = sz(tour) - 1;
	vlop(i,alist[root]) {
		if (!visited[alist[root][i].v]) {
			dtoroot[alist[root][i].v] = dtoroot[root] + alist[root][i].w;
			dfs(alist, tour, alist[root][i].v, entry, leave, dtoroot, currentlevel + 1, visited);
			tour.pb(root);
			level.pb(currentlevel);
		}
	}
	leave[root] = sz(tour) - 1;
	return;
}

int main() {
	int n;
	cin >> n;
	matrix(edge) alist(n + 1);
	lop(i, 1, n - 1) {
		int a,b,c;
		cin >> a >> b >> c;
		alist[a].pb(edge(b, c));
		alist[b].pb(edge(a, c));
	}
	vi tour; /*Euler tour*/
	vi dtoroot(n + 1, 0); /*distance to root from node i*/
	vi entry(n + 1); /*first time Euler tour reaches node i*/
	vi leave(n + 1); /*first time dfs finishes all search in i's descendent tree in Euler tour*/
	vi visited(n + 1, 0);
	dfs(alist, tour, 1, entry, leave, dtoroot, visited);
	return 0;
}
