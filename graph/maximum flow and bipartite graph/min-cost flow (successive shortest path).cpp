#include <bits/stdc++.h>

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
#define fi first
#define se second
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
#define lb(i,v) int(lower_bound(all(v),i)-v.begin())
#define ub(i,v) int(upper_bound(all(v),i)-v.begin())

const int infcost = 1e9;/*greater than the total cost*/
const int infcap = 1e9;/*greater than sum of all supply and demand*/

void mtol(matrix(int)& cap, matrix(int)& cost, matrix(int)& alist) {
	int n = sz(cap);
	alist.resize(n);
	vlop(i, cap) {
		vlop(j, cap[i]) {
			if (cap[i][j]) {
				alist[i].pb(j);
				alist[j].pb(i);
			}
		}
	}
	return;
}
bool bellmanford(matrix(int)& alist, matrix(int)& cap, matrix(int)& cost, int source, vi& d) {
	int n = sz(alist);
	lop(i, 1, n) {
		lop(j, 0, n - 1) {
			vlop(k, alist[j]) {
				if (cap[j][alist[j][k]]) {
					if (d[j] + cost[j][alist[j][k]] < d[alist[j][k]]) d[alist[j][k]] = d[j] + cost[j][alist[j][k]];
				}
			}
		}
	}
	lop(j, 0, n-1) {
		vlop(k, alist[j]) {
			if (cap[j][alist[j][k]]) {
				if (d[j] + alist[j][k].se < d[alist[j][k].fi])return true;
			}
		}
	}
	return false;
}

void reduce(matrix(int)& alist, matrix(int)& cost, matrix(int)& cap, vi& d) {
	vlop(i, cost) {
		vlop(k, alist[i]) {
			if (cap[i][alist[i][k]])cost[i][alist[i][k]] = cost[i][alist[i][k]] + d[i] - d[alist[i][k]];
		}
	}
	return;
}

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

void djs(matrix(int)& alist, matrix(int)& cap, matrix(int)& cost, vi& distance, vi& pre, int source) {
	int n = sz(cap), node;
	vi visited(n, 0), stree, key(n, infcost);
	key[source] = 0;
	initialize(1, stree, key, 0, n - 1);
	lop(i, 1, n) {
		node = stree[1];
		if (key[node] == infcost)break;
		distance[node] = key[node];
		updatetree(1, stree, key, node, infcost, 0, n - 1);
		visited[node] = 1;
		int j;
		vlop(k, alist[node]) {
			j = alist[node][k];
			if (!visited[j] && cap[node][j]) {
				if (key[j] > distance[node] + cost[node][j]) {
					updatetree(1, stree, key, j, distance[node] + cost[node][j], 0, n - 1);
					pre[j] = node;
				}
			}
		}
	}
	return;
}

void augmentpath(matrix(int)& cap, matrix(int)& cost, vi& pre, int s, int t) {
	int node = t;
	int mincap = cap[pre[node]][node];
	while (pre[node] != s) {
		node = pre[node];
		mincap = min(mincap, cap[pre[node]][node]);
	}
	node = t;
	cap[pre[node]][node] -= mincap;
	cap[node][pre[node]] += mincap;
	cost[node][pre[node]] = -cost[pre[node]][node];
	while (pre[node] != s) {
		node = pre[node];
		cap[pre[node]][node] -= mincap;
		cap[node][pre[node]] += mincap;
		cost[node][pre[node]] = -cost[pre[node]][node];
	}
	return;
}

/*solve the min-cost flow of an DIRECTED graph with node 0,...n-1 with successive shortest path algorithm*/
int main() {
	/*supply of i*/
	vi supply(n);

	/*cap[i][j]: the capcity from i to j, also the adjacency matrix of transformed network, default=0
	originalcost[i][j]: the original cost from i to j,default=0
	cap[source][i]=supply[i] if supply[i]>0, 0 if supply[i]<=0; cost[source][i]=0
	cap[i][sink]=-supply[i] if supply[i]<0; 0 if supply[i]>=0; cost[i][sink]=0*/
	matrix(int) cap(n + 2, vi(n + 2,0)), originalcost(n + 2, vi(n + 2,0));
	int source = n, sink = n + 1;
	/*alist becomes an undirected version of network*/
	matrix(int) alist;
	mtol(cap, originalcost, alist);

	/*d[i]: the shortest distance from source to i; pre[i]: the predecessor of i on the shortest path from source to i*/
	vi d(n, infcost), pre(n);
	d[source] = 0;
	/*if negloop=true, the graph do not have min-cost flow*/
	bool negloop=bellmanford(alist, cap, cost, source, d);
	
	/*cost: the reduced cost; cost[i][j]=originalcost[i][j]+d[i]-d[j]*/
	matrix(int) cost=originalcost;
	reduce(alist, cost, cap, d);
	/*after while() ends, cap will become the residue network of min-cost flow*/
	while (true) {
		vlop(i, d)d[i] = -1;
		djs(alist, cap, cost, d, pre, source);
		if (d[t] == -1)break;
		reduce(alist, cost, cap, d);
		augmentpath(cap, cost, pre, source, sink);
	}
	return 0;
}
