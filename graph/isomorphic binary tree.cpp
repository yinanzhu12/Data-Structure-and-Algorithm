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
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define all(s) (s).begin(),(s).end()
#define pb push_back
#define enter cout<<'\n'
#define lb(i,v) int(lower_bound(all(v),i)-v.begin())
#define ub(i,v) int(upper_bound(all(v),i)-v.begin())
void dfs(matrix(int)& alist, int r, matrix(int)& level, int currentlevel, vi& visited) {
	visited[r] = 1;
	level[currentlevel].pb(r);
	for (auto child : alist[r]) {
		if (!visited[child])dfs(alist, child, level, currentlevel + 1, visited);
	}
	return;
}
class can_name {
public:
	ii name;
	int node;
	can_name(ii name, int node) :name(name), node(node) {}
};
bool compare_name(can_name& n1, can_name& n2) {
	return n1.name<n2.name;
}

/*find if two rooted binary trees represented by adjacency list are isomorphic by Aho algorithm, if isomorphic, return 1*/
int aho_binary(matrix(int)& alist1, matrix(int)& alist2, int r1, int r2) {
	if (sz(alist1) != sz(alist2))return 0;
	int n = sz(alist1);
	matrix(int) level1(n), level2(n);
	vi visited(n + 1, 0);
	/*assign levels to both trees and store the nodes of level=i in leven1[i],level2[i]*/
	dfs(alist1, r1, level1, 0, visited);
	visited.assign(n + 1, 0);
	dfs(alist2, r2, level2, 0, visited);
	vi name1(n + 1), name2(n + 1);
	/*iterate over levels*/
	rlop(i, 0, n - 1) {
		if (sz(level1[i]) != sz(level2[i]))return 0;
		int m = sz(level1[i]);
		/*store all nodes's name of this level in levelname1, levelname2*/
		vector<can_name> levelname1, levelname2;
		/*iterate over each nodes in level*/
		lop(j, 0, m - 1) {
			int n1 = level1[i][j], n2 = level2[i][j];
			/*determine the long node name by concatenating its short name of its descendents, fill with 0 if descendent if missing*/
			ii node_name;
			if (!sz(alist1[n1]))node_name = ii(0, 0);
			else if (sz(alist1[n1]) == 1)node_name = ii(0, name1[alist1[n1][0]]);
			else node_name = ii(min(name1[alist1[n1][0]], name1[alist1[n1][1]]), max(name1[alist1[n1][0]], name1[alist1[n1][1]]));
			levelname1.pb(can_name(node_name, n1));
			if (!sz(alist2[n2]))node_name = ii(0, 0);
			else if (sz(alist2[n2]) == 1)node_name = ii(0, name2[alist2[n2][0]]);
			else node_name = ii(min(name2[alist2[n2][0]], name2[alist2[n2][1]]), max(name2[alist2[n2][0]], name2[alist2[n2][1]]));
			levelname2.pb(can_name(node_name, n2));
		}
		sort(all(levelname1), compare_name);
		sort(all(levelname2), compare_name);
		int label = 2;
		lop(j, 0, m - 1) {
			/*if levelname1 differs levelname2 after sorting, they are not isomorphic*/
			if (levelname1[j].name != levelname2[j].name)return 0;
			/*if the name of current node is different than the previous one, should assign a different name from previous one*/
			if (j) {
				if (levelname1[j].name != levelname1[j - 1].name)label++;
			}
			/*assign short node name to the node carrying the name*/
			name1[levelname1[j].node] = label;
			name2[levelname2[j].node] = label;
		}
	}
	return 1;
}