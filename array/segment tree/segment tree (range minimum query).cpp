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

/*stree[i] denote the INDEX of MINIMUM member from level[l] to level[u]*/
template <typename T>
void initialize(int start, vi& stree, vector<T>& level, int l, int u) {
	if (sz(stree) - 1 < start)stree.resize(start + 1);
	if (l == u)stree[start] = l;
	else {
		initialize(2 * start, stree, level, l, (u + l) / 2);
		initialize(2 * start + 1, stree, level, (u + l) / 2 + 1, u);
		if (level[stree[start * 2]] < level[stree[start * 2 + 1]])stree[start] = stree[start * 2];
		else stree[start] = stree[start * 2 + 1];
	}
	return;
}
template <typename T> 
void updatetree(int start, vi& stree, vector<T>& level, int index, T value, int l, int u) {
	if (l == u) {
		level[index] = value;
		return;
	}
	if (index <= (l + u) / 2)updatetree(2 * start, stree, level, index, value, l, (l + u) / 2);
	else updatetree(2 * start + 1, stree, level, index, value, (l + u) / 2 + 1, u);
	if (level[stree[start * 2]] < level[stree[start * 2 + 1]])stree[start] = stree[start * 2];
	else stree[start] = stree[start * 2 + 1];
	return;
}

template <typename T>
void updatetree(int start, vi& stree, vector<T>& level, int index, T value, int l, int u) {
	if (l == u) {
		level[index] = value;
		return;
	}
	if (index <= (l + u) / 2)updatetree(2 * start, stree, level, index, value, l, (l + u) / 2);
	else updatetree(2 * start + 1, stree, level, index, value, (l + u) / 2 + 1, u);
	/*change < to > for maximum querry*/
	if (level[stree[start * 2]] < level[stree[start * 2 + 1]])stree[start] = stree[start * 2];
	else stree[start] = stree[start * 2 + 1];
	return;
}

int main() {
	vi stree; /*segment tree,start from 1*/
	vi level; /*the array being searched, start from 0*/
	initialize<int>(1, stree, level, 0, sz(level) - 1);
	int i, j; 
	rmq<int>(1, stree, level, i, j, 0, sz(level) - 1);/*find minimum in segment [i,j]*/
	int index,value;
	update<int>(1,stree,level,index,value,0,sz(level)-1);/*update level[index]=value*/
}
