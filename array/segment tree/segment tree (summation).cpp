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

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
#define matrix(a) vector< vector<a> >
#define lop(i,a,b) for (int i=a; i<=b; i++)
#define rlop(i,a,b) for (int i=b; i>=a; i--) 
#define all(s) (s).begin(),(s).end()
#define isthere(c,x) ((c).find(x) != (c).end()) 
#define cisthere(c,x) (find(all(c),x) != (c).end())
#define pb push_back
#define sz(a) int((a).size()) 
#define printv(v,i) lop(i,0,sz(v)-1)cout<<v[i]<<" ";

void initialize(int start, vi& stree, vi& level, int l, int u) {
	if (sz(stree) - 1 < start)stree.resize(start + 1);
	if (l == u)stree[start] = level[l];
	else {
		initialize(2 * start, stree, level, l, (u + l) / 2);
		initialize(2 * start + 1, stree, level, (u + l) / 2 + 1, u);
		stree[start] = stree[start * 2]+stree[start * 2 + 1];
	}
	return;
}

int rmq(int start, vi& stree, int i, int j, int l, int u) {
	if (i > j)swap(i, j);
	if (j<l || i>u)return 0;
	if (l >= i&&u <= j)return stree[start];
	int t1 = rmq(2 * start, stree, level, i, j, l, (u + l) / 2);
	int t2 = rmq(2 * start + 1, stree, level, i, j, (u + l) / 2 + 1, u);
	return t2+t1;
}

void updatetree(int start, vi& stree, vi& level, int index, int value, int l, int u) {
	if (l == u) {
		level[index] = value;
		stree[start] = value;
		return;
	}
	if (index <= (l + u) / 2)updatetree(2 * start, stree, level, index, value, l, (l + u) / 2);
	else updatetree(2 * start + 1, stree, level, index, value, (l + u) / 2 + 1, u);
	stree[start] = stree[start * 2]+ stree[start * 2 + 1];
	return;
}

int main() {
	vi stree; /*segment tree,start from 1*/
	vi a; /*start from 0*/
	initialize(1, stree, a, 0, sz(a) - 1);
	int i, j;
	rmq(1, stree, i, j, 0, sz(a) - 1);/*return a[i]+...+a[j]*/
	int index, value;
	update(1, stree, a, index, value, 0, sz(level) - 1);/*update a[index]=value*/
}
