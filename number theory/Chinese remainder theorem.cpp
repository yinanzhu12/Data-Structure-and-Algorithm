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
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define all(s) (s).begin(),(s).end()
#define pb push_back
#define enter cout<<endl
ll inverse(ll a, ll b) {
	vll r = { a,b }, s = { 1,0 };
	while (true) {
		int i = sz(r) - 1;
		r.pb(r[i - 1] % r[i]);
		ll q = r[i - 1] / r[i];
		s.pb(s[i - 1] - s[i] * q);
		if (!r.back())break;
	}
	int i = sz(r) - 2;
	if (s[i]<0)s[i] += b;
	if (s[i] >= b)s[i] -= b;
	return s[i];
}
/*return ans such that ans= a[i] mod n[i] for any i. n[i] have to be pairwise relative prime*/
ll crt(vll& a, vll& n) {
	ll ans=0,m,N=1;
	for(auto i: n)N *= i;
	lop(i,0, sz(a)-1) {
		m = N / n[i];
		ans = ans + a[i] * m * inverse(m, n[i]);
	}
	return ans;
}
