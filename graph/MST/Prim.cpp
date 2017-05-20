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
#define all(s) (s).begin(),(s).end()
#define isthere(c,x) ((c).find(x) != (c).end())
#define pb push_back
#define enter cout<<'\n'

/*must be greater than any edge's weight*/
const int inf = 100001;

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
void updatetree(int start, vi& stree, vi& level, int index, int value, int l, int u) {
	if (l == u) {
		level[index] = value;
		return;
	}
	if (index <= (l + u) / 2)updatetree(2 * start, stree, level, index, value, l, (l + u) / 2);
	else updatetree(2 * start + 1, stree, level, index, value, (l + u) / 2 + 1, u);
	if (level[stree[start * 2]] < level[stree[start * 2 + 1]])stree[start] = stree[start * 2];
	else stree[start] = stree[start * 2 + 1];
	return;
}

void prim(matrix(ii)& alist,matrix(ii)& tree,int root) {
	int n = sz(alist) - 1;
	vi intree(n + 1, 0), key(n + 1, inf), stree,link(n+1);
	key[root] = 0;
	initialize(1, stree, key, 0, n);
	lop(i, 1, n) {
		int node = stree[1];
		updatetree(1, stree, key, node, inf, 0, n);
		intree[node] = 1;
		tree[node].pb(edge(link[node], key[node]));
		tree[link[node]].pb(edge(node,key[node]));
		vlop(j, alist[node]) {
			if (!intree[alist[node][j].fi] && key[alist[node][j].fi] > alist[node][j].se) {
				updatetree(1, stree, key, alist[node][j].fi, alist[node][j].se, 0, n);
				link[alist[node][j].fi] = node;
			}
		}
	}
	return;
}

/*use Prim algorithm to find the MST rooted in "root" of a weighted undirected connected graph 
with nodes 1,...,n and m edges, store the tree in another adjacency list*/
int main() {
	int n,m;
	cin >> n>>m;
	matrix(ii) alist(n + 1),tree(n+1);
	prim(alist, tree,1);
	return 0;
}