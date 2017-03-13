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

void bfs(matrix(int)& alist, vi& parent, vi& distance,int root) {
	vi visited(parent.size(), 0);
	queue<int> q;
	q.push(root);
	visited[root] = 1;
	while (!q.empty()) {
		int r = q.front();
		q.pop();
		vlop(i,alist[r]) {
			int child = alist[root][i];
			if (!visited[child]) {
				q.push(child);
				visited[child] = 1;
				parent[child] = root;
				distance[child] = distance[root] + 1;
			}
		}
	}
	return;
}

int main() {
	int n;
	cin >> n;
	matrix(int) alist(n + 1);
	for (int i = 0; i<n - 1; i++) {
		int v1,v2;
		cin >> v1 >> v2;
		alist[v1].push_back(v2);
		alist[v2].push_back(v1);
	}
	vi parent(n + 1, -1);
	vi distance(n + 1, 0);
	int root; /*the starting node of bfs*/
	bfs(alist, parent, distance,root);
	return 0;
}