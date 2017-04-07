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

int augmentpath(matrix(int)& amatrix, int source, int sink) {
	vi parent(sz(amatrix), -1), visited(sz(amatrix), 0);
	queue<int> q;
	q.push(source);
	visited[source] = 1;
	bool foundsink = false;
	while (!q.empty()) {
		int r = q.front();
		q.pop();
		vlop(i, amatrix[r]) {
			if (amatrix[r][i] && !visited[i]) {
				q.push(i);
				visited[i] = 1;
				parent[i] = r;
				foundsink = (i == sink);
			}
		}
		if (foundsink)break;
	}
	if (!foundsink)return 0;
	int node = sink;
	while (parent[node] != -1) {
		amatrix[parent[node]][node] --;
		amatrix[node][parent[node]] ++;
		node = parent[node];
	}
	return aug;
}

int maxflow(matrix(int)& amatrix, int source, int sink) {
	int mf = 0;
	while (true) {
		int t = augmentpath(amatrix, source, sink);/*the maximum weight on the augment path on the current residue network*/
		if (!t)break;
		mf += t;
	}
	return mf;
}
void dfs(matrix(int)& amatrix, int root, vi& side, vi& visited) {
	visited[root] = 1;
	vlop1(i, amatrix[root]) {
		if (amatrix[root][i] && !visited[i]) {
			visited[i] = 1;
			side[i] = !side[root];
			dfs(amatrix, i, side, visited);
		}
	}
	return;
}
void mtol(matrix(int)& amatrix, matrix(int)& alist) {
	vlop1(i, alist) {
		vlop1(j, amatrix[i]) {
			if (amatrix[i][j])alist[i].pb(j);
		}
	}
	return;
}
/*compute the maximum matching and minimum edge cover graph with Ford-Fulkerson algorithm*/
int main() {
	matrix(int) amatrix(n + 1, vi(n + 1)); /*adjacency list of UNDIRECTED bipartite graph, with node 1,...n.*/
	vi side(n + 1, -1), visited(n + 1, 0);
	side[1] = 0;
	dfs(dfs, 1, side, visited);/*side[i]=0 for i on left, 1 for right*/
	matrix(int) residue(n+3,vi(n+3,0)); /*residue is the adjacency list of DIRECTED graph with all edges from left to right
										plus n+1 as left supersource, n+2 as right supersource*/
	lop(i, 1, n) {
		if (!side[i]) {
			vlop1(j, amatrix[i])if (amatrix[i][j]) residue[i][j] = 1;
			residue[n + 1][i] = 1;
		}
		else residue[i][n + 2] = 1;
	}
	int mm=maxflow(residue, n + 1, n +  2);/*maxmatching is the capacity of the maximum matching, 
	Koenig's theorem states that it is also the capcity of minimum vertex cover. residue will be the residue network flow*/
	matrix(int) residuelist(n + 1);
	mtol(residue, residuelist);
	vi covered(n + 1, 0);
	lop(i, 1, n) {
		if (side[i]) {
			if (sz(residuelist[i]))covered[i] = 1;
			vlop(j, residuelist[i])covered[residuelist[i][j]] = 1;
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