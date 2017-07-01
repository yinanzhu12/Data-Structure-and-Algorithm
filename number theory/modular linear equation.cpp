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


/*solve equation ax=b mod n where x is unknown*/
void solve(ll a, ll b, ll n, vll& x) {
	vll r = { a,n }, s = { 1,0 }, t = { 0,1 };
	while (true) {
		int i = sz(r) - 1;
		r.pb(r[i - 1] % r[i]);
		ll q = r[i - 1] / r[i];
		s.pb(s[i - 1] - s[i] * q);
		t.pb(t[i - 1] - t[i] * q);
		if (!r.back())break;
	}
	int i = sz(r) - 2;
	ll gcd = r[i];
	if (b%gcd)return;
	ll xp = (s[i]+n) * b / gcd,d=n/gcd;
	lop(i, 1, gcd) {
		if (xp > n)xp %= n;
		x.pb(xp);
		xp += d;
	}
	return;
}