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
#define isthere(c,x) ((c).find(x) != (c).end())
#define pb push_back
#define enter cout<<'\n'

int augmentpath(matrix(int)& resmatrix, matrix(int)& reslist, int source, int sink) {
	vi parent(sz(resmatrix), -1), visited(sz(resmatrix), 0);
	queue<int> q;
	q.push(source);
	visited[source] = 1;
	bool foundsink = false;
	while (!q.empty()) {
		int r = q.front();
		q.pop();
		vlop(i, reslist[r]) {
			int child = reslist[r][i];
			if (!visited[child] && resmatrix[r][child]) {
				q.push(child);
				visited[child] = 1;
				parent[child] = r;
				foundsink = (child == sink);
			}
		}
		if (foundsink)break;
	}
	if (!foundsink)return 0;
	int node = sink;
	while (parent[node] != -1) {
		resmatrix[parent[node]][node]--;
		resmatrix[node][parent[node]]++;
		node = parent[node];
	}
	return 1;
}

int maxflow(matrix(int)& resmatrix, matrix(int)& reslist, int source, int sink) {
	int mf = 0;
	while (true) {
		int t = augmentpath(resmatrix, reslist, source, sink);/*the maximum weight on the augment path on the current residue network*/
		if (!t)break;
		mf += t;
	}
	return mf;
}
void dfs(matrix(int)& alist, int root, vi& side, vi& visited) {
	visited[root] = 1;
	vlop(i, alist[root]) {
		if (!visited[alist[root][i]]) {
			side[alist[root][i]] = !side[root];
			dfs(alist, alist[root][i], side, visited);
		}
	}
	return;
}
/*compute the maximum matching and minimum edge cover a bipartite graph*/
int main() {
	matrix(int) amatrix(n + 1, vi(n + 1)), alist(n + 1, vi(n + 1)); /*adjacency matrix and list of UNDIRECTED bipartite graph, with node 1,...n.*/
	vi side(n + 1, -1), visited(n + 1, 0);
	lop(i, 1, n) {
		if (!visited[i]) {
			side[i] = 0;
			dfs(alist, i, side, visited);
		}
	}/*side[i]=0 for i on left, 1 for right*/
	matrix(int) resmatrix(n + 3, vi(n + 3, 0)); /*The adjacency matrix of DIRECTED version of graph with all edges from left to right
												plus n+1 as left supersource, n+2 as right supersource*/
	matrix(int) udlist = alist;
	udlist.resize(n + 3); /*an undirected version of the graph with supersource*/
	lop(i, 1, n) {
		if (!side[i]) {
			vlop1(j, amatrix[i])if (amatrix[i][j]) resmatrix[i][j] = 1;
			resmatrix[n + 1][i] = 1;
			udlist[n + 1].pb(i);
			udlist[i].pb(n + 1);
		}
		else {
			resmatrix[i][n + 2] = 1;
			udlist[n + 2].pb(i);
			udlist[i].pb(n + 2);
		}
	}
	int mm = maxflow(resmatrix, udlist, n + 1, n + 2);/*maxmatching is the capacity of the maximum matching,
													  Koenig's theorem states that it is also the capcity of minimum vertex cover. residue will be the residue network flow*/
	matrix(int) reslist(n + 1); /*adjacency list of DIRECTED version of graph without supersource*/
	lop(i, 1, n) {
		lop(j, 1, n) {
			if (resmatrix[i][j])reslist[i].pb(j);
		}
	}
	vi covered(n + 1, 0);
	lop(i, 1, n) {
		if (side[i]) {
			if (sz(reslist[i]))covered[i] = 1;
			vlop(j, reslist[i])covered[residuelist[i][j]] = 1;
		}
	}
	/*get the capacity of minimum edge cover*/
	int mec = mm;
	vlop1(i, 1,n-1) {
		if (!covered[i]) {
			if (!side[i]) {
				lop(j, i + 1, n) {
					if (residue[i][j]) {
						residue[i][j] = 0;
						residue[j][i] = 1;
						covered[i] = 1;
						covered[j] = 1;
						mec++;
						break;
					}
				}
			}
			else {
				lop(j, i+1, n) {
					if (residue[j][i]) {
						residue[j][i] = 0;
						residue[i][j] = 1;
						covered[i] = 1;
						covered[j] = 1;
						mec++;
						break;
					}
				}
			}
		}
	}/*the residue will be the residue network after adding edges for mec*/
	return 0;
}