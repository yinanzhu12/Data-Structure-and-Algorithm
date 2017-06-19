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
#include <complex>

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
const long double pi = acos(-1.0);

vector< complex<db> > roots(25);

void precompute() {
	int m;
	vlop(i, roots) {
		m = 1 << i;
		roots[i] = complex<db>(cos(2 * pi / m), sin(2 * pi / m));
	}
	return;
}

/*fast fourier transform a polynomial with length=some power of two*/
vector< complex<db> > fft(vector< complex<db> >& a, bool reverse = false) {
	int n = sz(a), l = 0;
	int nt = n;
	while (nt) {
		l++;
		nt /= 2;
	}
	l--;
	vector< complex<db> > y = vector< complex<db> >(n);
	vlop(i, y)y[i] = a[bitrev(i, l)];
	complex<db> root, omega, u, t;
	lop(i, 0, l) {
		int m = (1 << i);
		if (!reverse)root = roots[i];
		else root = conj(roots[i]);
		for (int j = 0; j < n; j += m) {
			omega = 1;
			lop(k, 0, m / 2 - 1) {
				t = omega*y[j + k + m / 2];
				u = y[j + k];
				y[j + k] = u + t;
				y[j + k + m / 2] = u - t;
				omega *= root;
			}
		}
	}
	if (reverse) {
		vlop(i, y)y[i] /= n;
	}
	return y;
}