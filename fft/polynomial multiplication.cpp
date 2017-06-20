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
int bitrev(int n, int l) {
	int r = 0;
	lop(i, 0, l - 1) {
		if (n&(1 << i))r += (1 << (l - 1 - i));
	}
	return r;
}

void fft(vector< complex<db> >& a, bool reverse = false) {
	int n = sz(a), l = 0, r;
	int nt = n;
	while (nt) {
		l++;
		nt /= 2;
	}
	l--;
	vi visited(n, 0);
	vlop(i, a) {
		if (!visited[i]) {
			r = bitrev(i, l);
			swap(a[r], a[i]);
			visited[i] = 1;
			visited[r] = 1;
		}
	}
	complex<db> root, omega, u, t;
	lop(i, 0, l) {
		int m = (1 << i);
		if (!reverse)root = roots[i];
		else root = conj(roots[i]);
		for (int j = 0; j < n; j += m) {
			omega = 1;
			lop(k, 0, m / 2 - 1) {
				t = omega*a[j + k + m / 2];
				u = a[j + k];
				a[j + k] = u + t;
				a[j + k + m / 2] = u - t;
				omega *= root;
			}
		}
	}
	if (reverse) {
		vlop(i, a)a[i] /= n;
	}
	return;
}

vll multiply(vll& p1, vll& p2, int l1, int r1, int l2, int r2) {
	int n = max(r1 - l1 + 1, r2 - l2 + 1) * 2;
	vector< complex<db> > cp1(n, 0), cp2(n, 0);
	lop(i, l1, r1)cp1[i - l1] = p1[i];
	lop(i, l2, r2)cp2[i - l2] = p2[i];
	fft(cp1);
	fft(cp2);
	vlop(i, cp1) cp2[i] *= cp1[i];
	fft(cp2, true);
	vll y;
	lop(i, 0,r1-l1+r2-l2)y.pb(llround(cp2[i].real()));
	return y;
}

int main() {
	precompute();
	vll p1, p2;
	/*r1-l1+1 and r2-l2+1=power of two*/
	multiply(p1, p2, l1, r1, l2, r2);
	return 0;
}
