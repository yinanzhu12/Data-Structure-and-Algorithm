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

const int inf;/*greater than all of a*/

/*find the longest non-decreasing sequence of array a*/
int main() {
	vi a;
	vi inc(sz(a),inf),ind(sz(a)),pre(sz(a),-1);
	int b,p=0;
	vlop(i, a) {
		b = lb(a[i], inc);
		inc[b] = a[i];
		ind[b] = i;
		p = max(p, b);
		if (b)pre[i] = ind[b - 1];
	}
	vi lns;
	while (pre[p] != -1) {
		lns.pb(p);
		p = pre[p];
	}
	lns.pb(p);
	reverse(all(lns));/*lns contains the INDEX of the sequence*/
	return 0;
}