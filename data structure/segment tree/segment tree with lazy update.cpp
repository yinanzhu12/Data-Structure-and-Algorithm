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
template<typename T>
void initialize(int start, vector<T>& stree, vi& level, int l, int u) {
	if (sz(stree) - 1 < start)stree.resize(start + 1);
	if (l == u)stree[start] = level[l];
	else {
		initialize<T>(2 * start, stree, level, l, (u + l) / 2);
		initialize<T>(2 * start + 1, stree, level, (u + l) / 2 + 1, u);
		stree[start] = max(stree[start * 2], stree[start * 2 + 1]);
	}
	return;
}

template<typename T>
void updatetree(int start, vector<T>& stree, int index, T value, int l, int u) {
	if (l == u) {
		stree[start] += value;
		return;
	}
	if (index <= (l + u) / 2)updatetree<T>(2 * start, stree, index, value, l, (l + u) / 2);
	else updatetree<T>(2 * start + 1, stree, index, value, (l + u) / 2 + 1, u);
	stree[start] = max(stree[start * 2], stree[start * 2 + 1]);
	return;
}

/*push the status at current segment one level down
NOTE: 1) the segments in the lower level might already have nontirvial status
2) the current segment, and all levels above it, was already updated in lazyupdate*/
template<typename T>
void push(int start, vector<T>& stree, vector<T>& update, int l, int u) {
	stree[start] += update[start];
	if (l<u) {
		update[2 * start + 1] += update[start];
		update[2 * start] += update[start];
	}
	update[start] = 0;
	return;
}
template<typename T>
int rmq(int start, vector<T>& stree, vector<T>& update, int i, int j, int l, int u) {
	if (i > j)swap(i, j);
	if (j<l || i>u)return -1;
	if (l >= i&&u <= j) {
		push<T>(start, stree, update, l, u);
		return stree[start];
	}
	if (update[start])push<T>(start, stree, update, l, u);
	int t1 = rmq<T>(2 * start, stree, update, i, j, l, (u + l) / 2);
	int t2 = rmq<T>(2 * start + 1, stree, update, i, j, (u + l) / 2 + 1, u);
	return max(t1, t2);
}
template<typename T>
void lazyupdate(int start, vector<T>& stree, vector<T>& update, T value, int i, int j, int l, int u) {
	if (j<l || i>u)return;
	if (l >= i&&u <= j) {
		update[start] += value;
		return;
	}
	if (update[start])push<T>(start, stree, update, l, u);
	lazyupdate<T>(2 * start, stree, update, value, i, j, l, (u + l) / 2);
	lazyupdate<T>(2 * start + 1, stree, update, value, i, j, (u + l) / 2 + 1, u);
	stree[start] = max(stree[start * 2] + update[start * 2], stree[start * 2 + 1] + update[start * 2 + 1]);
	return;
}

int main() {
	vi stree; /*segment tree*/
	vi level(n); /*array being querried*/
	vi upd; /*record the status of update*/
	initialize<int>(1, stree, level, 0, n - 1);
	upd.resize<int>(sz(stree),0);
	lazyupdate<int>(1, stree, upd,v, i, j, 0, n-1); /*increase value in segment [i,j] by v*/
	rmq<int>(1, stree, upd, i, j, 0, n-1);
}