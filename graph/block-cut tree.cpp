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



void findcut(matrix(int)& alist, matrix(int)& treelist, int root, vi& d, vi& lowpoint, vi& visited, vi& cut, int superroot) {
	visited[root] = superroot;
	lowpoint[root] = d[root];
	vlop(i, alist[root]) {
		if (!visited[alist[root][i]]) {
			treelist[root].pb(alist[root][i]);
			d[alist[root][i]] = d[root] + 1;
			dfs(alist, treelist, root, d, lowpoint, visited, cut, superroot);
		}
		else lowpoint[root] = min(lowpoint[root], d[alist[root][i]]);
	}
	vlop(i, treelist[root])lowpoint[root] = min(lowpoint[root], lowpoint[treelist[root][i]]);
	vlop(i, treelist[root]) {
		if (lowpoint[alist[root][i]] >= d[root]) {
			cut[root] = 1;
			break;
		}
	}
	return;
}