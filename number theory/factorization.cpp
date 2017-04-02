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
#define pb push_back
#define enter cout<<'\n'

/*compute the Euler totient function of n*/
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

/*get all distinct prime factors of n and store them in pf, store their multiplicity in mult, and return the number of positive divisors, including 1 and itself*/
int primefactor(int n, vi& pf,vi& mult) {
	int result = 1;
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			pf.pb(i);
			mult.pb(0);
			while (n % i == 0) {
				n /= i;
				mult.back()++;
			}
			result *= (mult.back() + 1);
		}
	}
	if (n > 1) {
		pf.pb(n);
		mult.pb(1);
		result *= 2;
	}
	return result;
}

/*get all positive divisors of n other than 1 and itself*/
void factor(int n, vi& f) {
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			f.pb(i);
			if (n / i != i)f.pb(n / i);
		}
	}
	return;
}
