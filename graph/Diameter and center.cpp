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

void dfs1(matrix(int)& alist, int root, vi& dtoroot, vi& visited) {
	visited[root] = 1;
	for(auto child:alist[root]){
		if (!visited[child]) {
			dtoroot[child] = dtoroot[root] + 1;
			dfs1(alist, child, dtoroot, visited);
		}
	}
	return;
}
void dfs2(matrix(int)& alist, int root, vi& dtoroot, vi& parent, vi& visited) {
	visited[root] = 1;
	for(auto child: alist[root]) {
		if (!visited[child]) {
			parent[child] = root;
			dtoroot[child] = dtoroot[root] + 1;
			dfs2(alist, child, dtoroot, parent, visited);
		}
	}
	return;
}
ii dia(matrix(int)& alist) {
	int n = sz(alist) - 1;
	vi dtoroot(n + 1, 0), visited(n + 1, 0);
	dfs1(alist, 1, dtoroot, visited);
	int far = 1;
	/*choose one end of diameter*/
	lop(i,1,n) {
		if (dtoroot[i]>dtoroot[far])far = i;
	}
	vlop(i, visited)visited[i] = 0;
	vi parent(n + 1, 0);
	/*no need to reset every nodes' distance before the second dfs*/
	dtoroot[far] = 0;
	dfs2(alist, far, dtoroot, parent, visited);
	/*select the other end of diameter*/
	lop(i, 1,n) {
		if (dtoroot[i]>dtoroot[far])far = i;
	}
	int dia = dtoroot[far], center = far;
	lop(i, 1, dia / 2)center = parent[center];
	return ii(dia, center);
}

/*return the diameter and center of a tree with node 1,...,n*/
int main() {
	matrix(int) alist(n + 1);
	ii dc = dia(alist);/*diameter=dc.first,center=dc.center (not unique when diameter is odd)*/
}
