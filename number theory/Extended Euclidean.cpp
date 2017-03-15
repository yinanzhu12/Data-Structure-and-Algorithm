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
typedef pair<long long, long long> llll;
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

ll euclidean(ll a, ll b) {
	/*To compute gcd(a, b), return r[i].
	To compute 1/a mod b provided gcd(a,b)=1, return s[i]
	To compute solution to a*s+b*t=gcd(a,b), return s[i] and t[i]*/
	vll r = { a,b }, s = { 1,0 }, t = { 0,1 };
	while (true) {
		int i =sz(r) - 1;
		r.pb(r[i - 1] % r[i]);
		ll q = r[i - 1] / r[i];
		s.pb(s[i - 1] - s[i] * q);
		t.pb(t[i - 1] - t[i] * q);
		if (!r.back())break;
	}
	int i=sz(r)-2;
	if (s[i]<0)s[i] += b;
	if (s[i] >= b)s[i] -= b;
	return s[i];
}
