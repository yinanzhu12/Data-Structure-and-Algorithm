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

/*find the longest palidromic substring of s centered at every positions with Manacher algorithm*/
int main() {
	string s;
	int n = sz(s);
	/*a: augmented array of s with letter transformed to numbers and walls "-1" between letters,
	lp: the span of longest palindrome centered at i in a. length=2*lp[i]+1*/
	vi a(2*n+1),lp(2*n+1,0);
	vlop(i, a) {
		if (i % 2)a[i] = s[(i-1)/2] - 'a';
		else a[i] = -1;
	}
	int center=1,leftb=1,sufcenter;
	while (true) {
		while (leftb >= 0 && 2 * center - leftb <= 2 * n) {
			if (a[leftb] != a[2 * center - leftb])break;
			leftb--;
		}
		leftb++;
		lp[center] = center - leftb;
		sufcenter = center - 1;
		while (sufcenter >= leftb) {
			lp[center * 2 - sufcenter] = min(lp[sufcenter],sufcenter-leftb);
			if (sufcenter - lp[sufcenter] <= leftb)break;
			sufcenter--;
		}
		center = center * 2 - sufcenter;
		leftb = center - lp[center];
		if (center > 2 * n)break;
	}
	return 0;
}