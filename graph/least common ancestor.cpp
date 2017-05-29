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
typedef long long ll;
typedef pair<long long, long long> l4;
typedef vector<long long> vll;
typedef double db;
typedef vector<double> vdb;
typedef pair<double, double> dd;
typedef set<int> si;
typedef set<long long> sll;
#define matrix(a) vector< vector<a> >
#define sz(a) int((a).size()) 
#define lop(i,a,b) for (int i=a; i<=b; i++)
#define vlop(i,v) lop(i,0,sz(v)-1)
#define vlop1(i,v) lop(i,1,sz(v)-1)
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define vrlop(i,v) rlop(i,0,sz(v)-1)
#define vrlop1(i,v) rlop(i,1,sz(v)-1)
#define printv(i,v) vlop(i,v)cout<<v[i]<<" "
#define printv1(i,v) vlop1(i,v)cout<<v[i]<<" "
#define all(s) (s).begin(),(s).end()
#define pb push_back
#define enter cout<<'\n'

void initialize(int start, vi& stree, vi& level, int l, int u) {
	if (sz(stree) - 1 < start)stree.resize(start + 1);
	if (l == u)stree[start] = l;
	else {
		initialize(2 * start, stree, level, l, (u + l) / 2);
		initialize(2 * start + 1, stree, level, (u + l) / 2 + 1, u);
		if (level[stree[start * 2]] < level[stree[start * 2 + 1]])stree[start] = stree[start * 2];
		else stree[start] = stree[start * 2 + 1];
	}
	return;
}

int rmq(int start, vi& stree, vi& level, int i, int j, int l, int u) {
	if (j<l || i>u)return -1;
	if (l >= i&&u <= j)return stree[start];
	int t1 = rmq(2 * start, stree, level, i, j, l, (u + l) / 2);
	int t2 = rmq(2 * start + 1, stree, level, i, j, (u + l) / 2 + 1, u);
	if (t1 == -1)return t2;
	if (t2 == -1)return t1;
	if (level[t1] < level[t2])return t1;
	return t2;
}
void dfs(matrix(int)& alist, vi& tour, int root, vi& entry, vi& level, vi& visited,int currentlevel) {
	visited[root] = 1;
	tour.pb(root);
	level.pb(currentlevel);
	entry[root] = sz(tour) - 1;
	vlop(i, alist[root]) {
		if (!visited[alist[root][i]]) {
			dfs(alist, tour, alist[root][i], entry,level, visited,currentlevel+1);
			tour.pb(root);
			level.pb(currentlevel);
		}
	}
	return;
}

/*get the LCA of any two nodes in a tree with node 1,...n*/
int main() {
	int n;
	matrix(int) alist(n + 1);
	vi tour; /*Eulerian tour, start from 0*/
	vi level; /*levels on the eulerian tour, start from 0*/
	vi entry(n + 1); /*entry[i]=first time Euler tour reaches node i*/
	vi visited(n + 1, 0);
	dfs(alist, tour, 1, entry, level, visited,0);
	vi stree;
	initialize(1, stree, level, 0, sz(level)-1);
	int u, v;
	tour[rmq(1, stree, level, min(entry[u],entry[v]), max(entry[u],entry[v]), 0, sz(level) - 1)];/*the node number of LCA of u,v*/
	return 0;
}
