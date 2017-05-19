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

int euclidean(int a, int b) {
	vi r = { a,b };
	while (true) {
		int i = sz(r) - 1;
		r.pb(r[i - 1] % r[i]);
		int q = r[i - 1] / r[i];
		if (!r.back())break;
	}
	return r[sz(r) - 2];
}

void pytriple(int i, matrix(ll)& triple) {
	int m, n;
	if (i % 2) {
		for (int k = 1; k*k < i; k++) {
			if (!(i%k)) {
				m = k + i / k;
				n = i / k - k;
				if (!(m % 2)) {
					m /= 2;
					n /= 2;
					if (euclidean(m, n) == 1 ) {
						if (!(m % 2) || !(n % 2)) triple.pb({ 1LL * 2 * m*n, i, 1LL * m*m + 1LL * n * n });
					}
				}
			}
		}
		return;
	}
	int j = i/2;
	for (int k = 1; k*k < j; k++) {
		if (!(j%k)) {
			m= k;
			n = j / k;
			if (euclidean(m, n) == 1) {
				if (!(m % 2) || !(n % 2)) triple.pb({ 1LL*n*n-1LL*m*m ,i,1LL *n*n + 1LL*m*m });
			}
		}
	}
	return;
}

int main() {
	matrix(ll) triple;
	/*return any pythagorean triples containing i, put i in the middle of triple*/
	pytriple(i, triple);
	return 0;
}