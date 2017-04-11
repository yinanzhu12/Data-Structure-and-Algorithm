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

int inf = 10000000;/*greater than upper bound of path length*/

void multiply(matrix(int)& a, matrix(int)& b) {
	int n = sz(a)-1;
	matrix(int) l(n+1, vi(n+1, inf));
	lop(i,1,n) {
		lop(j,1,n) {
			lop(k,1,n) l[i][j] = min(l[i][j], a[i][k] + b[k][j]);
		}
	}
	a = l;
	return;
}

void floydwarshall(matrix(int)& a) {
	int n = sz(a)-1;
	lop(i,1,n){
		matrix b=a;
		lop(j,1,n) {
			lop(k,1,n) a[j][k] = min(a[j][k], b[j][i] + b[i][k]);
		}
	}
	return;
}

int main() {
	/*graph with n vertices and m edges*/
	int n;
	int m;
	cin >> n >> m;
	matrix(int) graph(n + 1, vi(n + 1, inf));
	lop(i,1,n)graph[j][j] = 0;
	lop(i,1,m) {
		int a;
		int b;
		int g;
		cin >> a >> b >> g;
		graph[a][b] = min(graph[a][b], g);
		graph[b][a] = graph[a][b];
	}
	matrix shortestpath = graph;
	int p = 1;
	/*find shortest path by multiplication*/
	while (p < n - 1) {
		multiply(shortestpath, shortestpath);
		p *= 2;
	}
	/*find shortest path by Floyd-Warshall algorithm*/
	shortestpath = graph;
	floydwarshall(shortestpath);
	return 0;
}
