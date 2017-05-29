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

int phi(int n) {
	int result = n;
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			result -= result / i;
			while (n % i == 0) n /= i;
		}
	}
	if (n > 1) result -= result / n;
	return result;
}

void primefactor(int n, vi& pf) {
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			pf.pb(i);
			while (n % i == 0) n /= i;
		}
	}
	if (n > 1) pf.pb(n);
	return;
}

ll expo(ll n, ll e,ll M) {
	if (!e)return 1;
	if (e == 1)return n%M;
	ll t = exp(n, e / 2);
	if (e % 2)return t*t%M*e%M;
	return t*t%M;
}
/*find the smallest primitive root of p*/
int primroot(int p) {
	vi pf;
	int ph = phi(p);/*if p is prime, ph=p-1*/
	primefactor(ph, pf);
	bool pr = true;
	lop(i, 2, p - 1) {
		pr = true;
		vlop(j, pf) {
			if (expo(1LL * i, 1LL *ph/ pf[j], 1LL * p) == 1) {
				pr = false;
				break;
			}
		}
		if (pr)return i;
	}
	return -1;
}