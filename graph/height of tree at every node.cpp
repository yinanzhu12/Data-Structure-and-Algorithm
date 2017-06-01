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

void dfs1(matrix(int)& alist, int root, vi& visited,matrix(int)& height, vi& neighbour) {
	visited[root] = 1;
	int child;
	vlop(i, alist[root]) {
		child = alist[root][i];
		if (!visited[child]) {
			dfs1(alist, child, visited, height, neighbour);
			if (height[child][0] + 1 > height[root][0]) {
				height[root][1] = height[root][0];
				height[root][0] = height[child][0] + 1;
				neighbour[root] = child;
			}
			else if (height[child][0] + 1 > height[root][1]) height[root][1] = height[child][0] + 1;
		}
	}
	return;
}

void dfs2(matrix(int)& alist, int root, vi& visited, matrix(int)& height, vi& neighbour) {
	visited[root] = 1;
	int child;
	vlop(i, alist[root]) {
		child = alist[root][i];
		if (!visited[child]) {
			if (neighbour[root] != child) {
				if (height[root][0] + 1 > height[child][0]) {
					height[child][1] = height[child][0];
					height[child][0] = height[root][0] + 1;
					neighbour[child] = root;
				}
				else if (height[root][0] + 1 > height[child][1])height[child][1] = height[root][0] + 1;
			}
			else {
				if (height[root][1] + 1 >height[child][0]) {
					height[child][1] = height[child][0];
					height[child][0] = height[root][1] + 1;
					neighbour[child] = root;
				}
				else if(height[root][1] + 1 > height[child][1])height[child][1] = height[root][1] + 1;
			}
			dfs2(alist, child, visited, height, neighbour);
		}
	}
	return;
}

/*find height of the tree rooted at every node*/
int main() {
	int n;
	cin >> n;
	matrix(int) alist(n + 1);
	vi visited(n + 1, 0),neighbour(n+1,0);
	matrix(int) height(n + 1, vi(2, -1);
	dfs1(alist, 1,visited,height,neighbour);
	vlop(i, visited)visited[i] = 0;
	dfs2(alist, 1, visited, height, neighbour);
	return 0;
}
