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


class querry {
public:
	int l;
	int r;
	int index;
	querry(int left, int right,int ind) {
		l = left;
		r = right;
		index = ind;
	}
};
bool comparequerry(querry q1, querry q2) {
	return q1.r < q2.r;
}

void move(int& wl, int& wr, int nl, int nr,vi& v) {
	while (wr<nr) {
		/*...*/
		wr++;
	}
	while (wr>nr) {
		/*...*/
		wr--;
	}
	while (wl<nl) {
		/*...*/
		wl++;
	}
	while (wl>nl) {
		/*...*/
		wl--;
	}
	return;
}
/*solve m querries on array v (of size n) with Mo's algorithm*/
int main() {
	vi v(n);
	vector<querry> q(m);
	int sqn = sqrt(n);
	matrix(querry) block;
	if (sqn*sqn == n)block.resize(sqn);
	else block.resize(sqn + 1);
	lop(i, 0,m-1) block[q[i].l%sqn].pb(q[i]);
	lop(i, 0,sz(block)-1)sort(all(block[i]), comparequerry);
	int wl = 0, wr = 0,nl,nr;
	lop(i, 0,sz(block)-1) {
		lop(j,0, sz(block[i])-1) {
			nl = block[i][j].l, nr = block[i][j].r;
			move(wl, wr, nl, nr, v);
			/*...*/
		}
	}
	return 0;
}
