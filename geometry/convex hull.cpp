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
#define isthere(c,x) ((c).find(x) != (c).end())
#define pb push_back
#define enter cout<<'\n'

dd intersect(l4 line1, l4 line2) {
	db x = 1.0*(line1.second - line2.second) / (line2.first - line1.first);
	db y = x*line1.first + 1.0*line1.second;
	return dd(x, y);
}

void addline(vector<l4>& hull, vector<db>& corner, l4 line1) {
	if (hull.empty()) {
		hull.pb(line1);
		return;
	}
	while (!corner.empty()) {
		l4 line2 = hull.back();
		if (line1.first == line2.first) {
			corner.pop_back();
			hull.pop_back();
		}
		else {
			db inter2 = corner.back(), inter1 = intersect(line1, line2).first;
			if (inter1 > inter2) {
				corner.pb(inter1);
				hull.pb(line1);
				break;
			}
			else {
				hull.pop_back();
				corner.pop_back();
			}
		}
	}
	if (corner.empty()) {
		l4 line2 = hull.back();
		inter.pb(intersect(line1, line2).first);
		line.pb(line1);
	}
	return;
}

int main() {
	vector<l4> allline; /*store all lines in the form l4(slope,intercept)*/
	vector<l4> hull; /*to store the sequence of relavant lines, in DESCENDING order for MINIMUM, ASCENDING order for MAXIMUM*/
	vector<db> corner; /*to store the x component of intersections of relavant lines from left to right*/
	sort(all(allline)); 
	reverse(all(allline));/*to find the MINIMUM of input, sort (slope,intercept) in DESCENDING order; if MAXIMUM, reverse*/
	vlop(i, allline) addline(hull, corner, allline[i]);
	int p = int(upper_bound(all(corner),x)-corner.begin()); /*find the section where x should be evaluated*/
	ll v = hull[p].first*x + hull[p].second;
	return 0;
}