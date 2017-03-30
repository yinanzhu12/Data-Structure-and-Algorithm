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
#define enter cout<<'\n'

void initialize(int start, vi& stree, vi& level, int l, int u) {
	if (sz(stree) - 1 < start)stree.resize(start + 1);
	if (l == u)stree[start] = level[l]; /*insert the desired function on array*/
	else {
		initialize(2 * start, stree, level, l, (u + l) / 2);
		initialize(2 * start + 1, stree, level, (u + l) / 2 + 1, u);
		stree[start] = stree[start * 2 + 1] + stree[start * 2];
	}
	return;
}

/*push the status at current segment one level down
NOTE: 1) the segments in the lower level might already have nontirvial status
2) the current segment, and all levels above it, was already updated in lazyupdate*/
void pushdown(int start, vi& stree, vi& upd, int l, int u) {
	upd[start] = 0;
	if (start * 2>sz(upd) - 1)return;
	upd[start * 2] = !upd[start * 2];             /*update the current status of lower level segments*/
	upd[start * 2 + 1] = !upd[start * 2 + 1];
	stree[start * 2] = (u + l) / 2 - l + 1 - stree[start * 2];       /*update the result on lower level segments*/
	stree[start * 2 + 1] = u - (u + l) / 2 - stree[start * 2 + 1];
	return;
}

void lazyupdate(int start, vi& stree, vi& upd, int i, int j, int l, int u) {
	if (j<l || i>u)return;
	if (l >= i&&u <= j) {
		upd[start] = !upd[start];
		stree[start] = u - l + 1 - stree[start];     /*update the result on lowerlevel segment*/
		return;
	}
	if (upd[start])pushdown(start, stree, upd, l, u);
	lazyupdate(2 * start, stree, upd, i, j, l, (u + l) / 2);
	lazyupdate(2 * start + 1, stree, upd, i, j, (u + l) / 2 + 1, u);
	stree[start] = stree[start * 2] + stree[start * 2 + 1];
	return;
}

int querry(int start, vi& stree, vi& upd, int i, int j, int l, int u) {
	if (i > j)swap(i, j);
	if (j<l || i>u)return 0;
	if (l >= i&&u <= j) return stree[start];
	if (upd[start])pushdown(start, stree, upd, l, u);
	int t1 = rmq(2 * start, stree, upd, i, j, l, (u + l) / 2), t2 = rmq(2 * start + 1, stree, upd, i, j, (u + l) / 2 + 1, u);
	return t1 + t2;
}

int main() {
	vi stree; /*segment tree*/
	vi level(n); /*array being querried*/
	vi upd; /*record the status of update*/
	initialize(1, stree, level, 0, n - 1);
	upd.resize(sz(stree));
	lazyupdate(1, stree, upd, i, j, 0, n-1); /*do update on segment [i,j], applies for i==j*/
	querry(1, stree, upd, i, j, 0, n-1);
}