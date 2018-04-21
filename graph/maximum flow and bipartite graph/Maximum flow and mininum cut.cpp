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
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define all(s) (s).begin(),(s).end()
#define pb push_back
#define enter cout<<'\n'

const int inf; /*must be greater than the maximum capcity of any edge*/

int augmentpath(matrix(int)& amatrix,matrix(int)& udlist, int source, int sink) {
	vi parent(sz(amatrix), -1), visited(sz(amatrix), 0);
	queue<int> q;
	q.push(source);
	visited[source] = 1;
	bool foundsink = false;
	while (!q.empty()) {
		int r = q.front();
		q.pop();
		for(auto child: udlist[r]) {
			if (!visited[child] && amatrix[r][child]) {
				q.push(child);
				visited[child] = 1;
				parent[child] = r;
				foundsink = (child == sink);
			}
			if (foundsink)break;
		}
		if (foundsink)break;
	}
	if (!foundsink)return 0;
	int node = sink, aug = inf;
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

int maxflow(matrix(int)& amatrix,matrix(int)& udlist, int source, int sink) {
	int mf = 0;
	while (true) {
		int t = augmentpath(amatrix, udlist, source, sink);/*the maximum weight on the augment path on the current residue network*/
		if (!t)break;
		mf += t;
	}
	return mf;
}

/*compute the maximum flow of a directed weighted graph with Ford-Fulkerson algorithm*/
int main() {
	matrix(int) amatrix(n + 1, vi(n + 1)); /*adjacency list of the graph, index start from 1*/
	matrix(int) resmatrix = amatrix;
	matrix(int) udlist; /*an UNDERIECTED adjacecy list version of residue*/
	int source, sink;
	int mf=maxflow(resmatrix, udlist,source, sink); /*return the maximum flow (also the capcity of the mininum cut),
    residue will become the adjacency matrix residue network*/
}
