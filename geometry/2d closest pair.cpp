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

db distance(dd p, dd q) {
	return sqrt(pow(p.fi - q.fi, 2) + pow(p.se - q.se, 2));
}

db cp(vector<dd>& points) {
	db d = distance(points[1], points[0]), left = points[0].fi, right = points.back().fi;
	lop(i, 2, sz(points) - 1)d = min(d, distance(points[i], points[0]));
	set<dd> window;
	int back = 0;
	vlop1(i, points) {
		if (points[i].fi - points[i - 1].fi <= d)window.insert(dd(points[i - 1].se, points[i - 1].fi));
		while (back<i) {
			if (points[i].fi - points[back].fi>d)window.erase(dd(points[back].se, points[back].fi));
			else break;
			back++;
		}
		set<dd>::iterator l = window.lower_bound(dd(points[i].se - d, left - 1)), r = window.upper_bound(dd(points[i].se + d, right + 1));
		ii temp = dd(points[i].se, points[i].fi);
		for (set<dd>::iterator it = l; it != r; it++)d = min(d, distance(temp, *it));
	}
	return d;
}

/*compute the minimum distance between any different points (point[i].fi,point[i].se)*/
int main() {
	vector<dd> points;
	sort(all(points));
	dd d = cp(points);
}