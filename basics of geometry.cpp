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

/*compute the distance from (a.first,a.second) to the line passing through (b.first,b.second) and (c.first, c.second)*/
db height(dd a, dd b, dd c) {
	dd cb = dd(b.fi - c.fi, b.se - c.se), ca = dd(a.fi - c.fi, a.se - c.se);
	db caxcb = abs(ca.fi*cb.se - cb.fi*ca.se);
	db cbmod = sqrt(cb.fi*cb.fi + cb.se*cb.se);
	return caxcb / cbmod;
}

/*compute the intersection of two lines with equation y=line.fi*x+line.se, lines CANNOT be parrelleled*/
dd intersect(dd line1, dd line2) {
	db x = (line1.se- line2.se) / (line2.fi - line1.fi);
	db y = x*line1.fi + line1.se;
	return dd(x, y);
}