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

int bitrev(int n, int l) {
	int r = 0;
	lop(i, 0, l - 1) {
		if (n&(1 << i))r += (1 << (l - 1 - i));
	}
	return r;
}

vector< complex<db> > transform(vll& a, int l, int r) {
	int m = 1;
	while (m < r - l + 1) m <<= 1;
	vector< complex<db> > y;
	y.resize(m, complex<db>(0, 0));
	lop(i, l, r) y[i - l] = complex<db>(a[i], 0);
	return y;
}

vll recover(vector< complex<db> >& a, int n) {
	vll y(n);
	vlop(i, y)y[i] = ll(a[i].real());
	return y;
}

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
	complex<db> omegam, omega, u, t;
	lop(i, 0, l) {
		int m = (1 << i);
		for (int j = 0; j < n; j += m) {
			lop(k, 0, m / 2 - 1) {
				 if(reverse)omega = complex<db>(cos(2 * pi / m*k), -sin(2 * pi / m*k));
				 else omega = complex<db>(cos(2 * pi / m*k), sin(2 * pi / m*k));
				t = omega*y[j + k + m / 2];
				u = y[j + k];
				y[j + k] = u + t;
				y[j + k + m / 2] = u - t;
			}
		}
	}
	if (reverse) {
		vlop(i, y)y[i] /= n;
	}
	return y;
}

vll multiply(vll& p1, vll& p2, int l1, int r1, int l2, int r2) {
	vector< complex<db> > cp1 = transform(p1, l1, r1), cp2 = transform(p2, l2, r2);
	int n = max(sz(cp1), sz(cp2));
	n *= 2;
	cp1.resize(n,complex<db>(0,0));
	cp2.resize(n,complex<db>(0,0));
	vector< complex<db> > tcp1 = fft(cp1), tcp2 = fft(cp2), prod;
	vlop(i, tcp1) tcp2[i] *= tcp1[i];
	prod = fft(tcp2, true);
	return recover(prod, r2 - l2 + r1 - l1 + 1);
}

int main() {
	ifstream infile;
	ofstream outfile;
	infile.open("input.txt");
	cin.rdbuf(infile.rdbuf());
	outfile.open("output.txt");
	cout.rdbuf(outfile.rdbuf());
	vll p1(3), p2(3);
	vlop(i, p1)cin >> p1[i];
	vlop(i, p2)cin >> p2[i];
	vll p3 = multiply(p1, p2, 0, 2, 0, 2);
	printv(i, p3);
	enter;
	return 0;
}