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

int main() {
	int m;
	vi p(m + 1),c(m + 1, -1);/*p[1],p[2],...p[m]: the permutation. c[i]: the conjugacy class number of number p[i]*/
	matrix(int) cc; /*list of conjugacy class*/
	int classnumber = 0;
	/*compute the conjugacy class*/
	vlop1(i, p) {
		if (c[i] == -1) {
			int next = p[i];
			cc.resize(classnumber + 1);
			c[i] = classnumber;
			cc[classnumber].pb(i);
			while (next != i) {
				c[next] = classnumber;
				cc[classnumber].pb(next);
				next = p[next];
			}
			classnumber++;
		}
	}
	return;
}