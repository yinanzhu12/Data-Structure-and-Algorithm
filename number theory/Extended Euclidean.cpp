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
typedef vector<long> vl;
typedef long long ll;
typedef pair<long long, long long> l4;
typedef vector<long long> vll;
#define matrix(a) vector< vector<a> >
#define sz(a) int((a).size()) 
#define ite(v) v::iterator
#define lop(i,a,b) for (int i=a; i<=b; i++)
#define vlop(i,v) lop(i,0,sz(v)-1)
#define vlop1(i,v) lop(i,1,sz(v)-1)
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define vrlop(i,v) rlop(i,0,sz(v)-1)
#define vrlop1(i,v) rlop(i,1,sz(v)-1)
#define printv(i,v) vlop(i,v)cout<<v[i]<<" "
#define all(s) (s).begin(),(s).end()
#define isthere(c,x) ((c).find(x) != (c).end()) 
#define cisthere(c,x) (find(all(c),x) != (c).end())
#define pb push_back
#define enter cout<<endl

/*return {s,t}, such that a*s+b*t=gcd(a,b)*/
l4 euclidean(ll a, ll b) {
	vll r = { a,b }, s = { 1,0 }, t = { 0,1 };
	int i;
	ll q;
	while (true) {
		i =sz(r) - 1;
		r.pb(r[i - 1] % r[i]);
		q = r[i - 1] / r[i];
		s.pb(s[i - 1] - s[i] * q);
		t.pb(t[i - 1] - t[i] * q);
		if (!r.back())break;
	}
	i=sz(r)-2;
	return l4(s[i],t[i]);
}

/*return a^-1 mod b (if gcd(a,b)=1)*/
ll inverse(ll a, ll b) {
	vll r = { a,b }, s = { 1,0 };
	int i;
	ll q;
	while (true) {
		i = sz(r) - 1;
		r.pb(r[i - 1] % r[i]);
		q = r[i - 1] / r[i];
		s.pb(s[i - 1] - s[i] * q);
		if (!r.back())break;
	}
	i = sz(r) - 2;
	if (s[i]<0)s[i] += b;
	if (s[i] >= b)s[i] -= b;
	return s[i];
}

/*gcd(a,b)*/
ll gcd(ll a, ll b) {
	if(!a)return b;
	if(!b)return a;
	vll r = { a,b };
	int i;
	while (true) {
		i = sz(r) - 1;
		r.pb(r[i - 1] % r[i]);
		if (!r.back())break;
	}
	i = sz(r) - 2;
	return r[i];
}

