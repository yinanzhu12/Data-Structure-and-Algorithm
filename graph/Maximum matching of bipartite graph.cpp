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
	int node = sink, aug = 2;
	while (parent[node] != -1) {
		aug = min(amatrix[parent[node]][node], aug);
		node = parent[node];
	}
	node = sink;
	while (parent[node] != -1) {
		amatrix[parent[node]][node] -= aug;
		amatrix[node][parent[node]] += aug;
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

/*compute the maximum matching and minimum edge cover graph with Ford-Fulkerson algorithm*/
int main() {
	matrix(int) amatrix(n + m + 3, vi(n + m + 3)); /*adjacency list of graph where all edges are from left to right with capcity one.
	Node 1,...n on left side, n+1,...m on right side. n+m+1 is supersource, n+m+2 is supersink*/
	lop(i, 1, n)amatrix[n + m + 1][i] = 1;
	lop(i, n + 1, m + n)amatrix[i][n + m + 2] = 1;
	matrix(int) residue = amatrix;
	int maxmatching=maxflow(residue, n + 1 + m, n + m + 2);/*maxmatching is the capacity of the maximum matching, 
	Koenig's theorem states that it is also the capcity of minimum vertex cover. residue will be the residue network flow*/
	vi covered(n + m + 1, 0);
	lop(i, n+1, n+m) {
		lop(j, 1, n) {
			if (residue[i][j]) {
				covered[i] = 1;
				covered[j] = 1;
			}
		}
	}
	/*get the capacity of minimum edge cover*/
	int miniedgecover = maxmatching;
	vlop1(i, covered) {
		if (!covered[i]) {
			if (i <= n) {
				lop(j, n + 1, n + m) {
					if (residue[i][j]) {
						residue[i][j] = 0;
						residue[j][i] = 1;
						covered[i] = 1;
						covered[j] = 1;
						miniedgecover++;
						break;
					}
				}
			}
			else {
				lop(j, 1, n) {
					if (residue[j][i]) {
						residue[j][i] = 0;
						residue[i][j] = 1;
						covered[i] = 1;
						miniedgecover++;
						break;
					}
				}
			}
		}
	}
	return 0;
}
