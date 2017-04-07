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

/*must be greater than any possible path*/
const int inf=1000000;

class edge {
public:
	int v;
	int w;
	edge(int a, int b) {
		v = a;
		w = b;
	}
	edge() {
		v = 0;
		w = 0;
	}
};

bool bellmanford(matrix(int)& alist, int source, vi& d, vi& pred) {
	lop(i, 1, n) {
		lop(j, 1, n) {
				vlop(k, alist[j]) {
					if (d[j] + alist[j][k].w < d[alist[j][k].v) {
						d[alist[j][k].v] = d[j] + alist[j][k].w;
						pred[alist[j][k].v] = j;
					}
				}
			}
		}
	lop(j, 1, n) {
		vlop(k, alist[j]) {
			if (d[j] + alist[j][k].w < d[alist[j][k].v)return false;
		}
	}
	return true;
}

/*use Bellman-Ford algorithm to check if a DIRECTED graph (with node 1,...,n) have negative loop, 
if not, return the shortest distance of from a source to all nodes*/
int main() {
	matrix(edge) alist(n+1);
	/*initialize*/
	int source;
	vi d(n + 1),pred(n+1);
	vlop1(i, d) {
		d[i] = inf;
		pred[i] = -1;
	}
	d[source] = 0;
	/*if nonegativeloo=true, d[i]=shortest distance from source to i*/
	bool nonegativeloop=bellmanford(alist, source, d, pred);
	return 0;
}
