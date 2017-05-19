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

bool bellmanford(matrix(ii)& alist, int source, vi& d, vi& pred) {
	int n = sz(alist)-1;
	lop(i, 1, n) {
		lop(j, 1, n) {
				vlop(k, alist[j]) {
					if (d[j] + alist[j][k].se < d[alist[j][k].fi]) {
						d[alist[j][k].fi] = d[j] + alist[j][k].se;
						pred[alist[j][k].fi] = j;
					}
				}
			}
		}
	lop(j, 1, n) {
		vlop(k, alist[j]) {
			if (d[j] + alist[j][k].se < d[alist[j][k].fi])return false;
		}
	}
	return true;
}

/*use Bellman-Ford algorithm to check if a DIRECTED graph (with node 1,...,n) have negative loop, 
if not, return the shortest distance of from a source to all nodes*/
int main() {
	matrix(ii) alist(n+1);
	int source;
	vi d(n + 1,inf),pred(n+1,-1);
	d[source] = 0;
	/*if nonegativeloo=true, d[i]=shortest distance from source to i*/
	bool nonegativeloop=bellmanford(alist, source, d, pred);
	return 0;
}
