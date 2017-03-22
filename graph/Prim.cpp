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

class edge {
public:
	int w;
	int v;
	edge(int a, int b) {
		v = a;
		w = b;
	}
};

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

void prim(matrix(edge)& alist,matrix(edge)& tree) {
	int n = sz(alist) - 1;
	vi intree(n + 1, 0), key(n + 1, inf), stree,link(n+1);
	/*start search from node 1*/
	key[1] = 0;
	initialize(1, stree, key, 0, n);
	lop(i, 1, n) {
		int node = stree[1];
		updatetree(1, stree, key, node, inf, 0, n);
		intree[node] = 1;
		tree[node].pb(edge(link[node], key[node]));
		tree[link[node]].pb(edge(node,key[node]));
		vlop(j, alist[node]) {
			if (!intree[alist[node][j].v] && key[alist[node][j].v] > alist[node][j].w) {
				updatetree(1, stree, key, alist[node][j].v, alist[node][j].w, 0, n);
				link[alist[node][j].v] = node;
			}
		}
	}
	return;
}

/*use Prim algorithm to find the MST of a weighted undirected connected graph 
with n nodes (indexed from 1) and m edges, store the tree in another adjacency list*/
int main() {
	int n,m;
	cin >> n>>m;
	matrix(edge) alist(n + 1),tree(n+1);
	lop(i,1,m) {
		int a, b, c;
		cin >> a >> b >> c;
		alist[a].push_back(edge(b, c));
		alist[b].push_back(edge(a, c));
	}
	prim(alist, tree);
	return 0;
}