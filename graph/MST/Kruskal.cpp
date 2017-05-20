#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

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


class edge {
public:
	int w;
	int v1;
	int v2;
	edge(int a, int b, int c) {
		v1 = a;
		v2 = b;
		w = c;
	}
};

bool compareedge(edge e1, edge e2) { 
	if (e1.w == e2.w)return(e1.vsum<e2.vsum);
	return (e1.w < e2.w);
}

class myset {
public:
	int name;
	int parent;
	int rank;
	myset() {
		name = -1;
		parent = -1;
		rank = 1;
	}
	myset(int n) {
		name = n;
		parent = n;
		rank = 1;
	}
	bool isroot() {
		return this->parent == this->name;
	}
};

int findroot(int i, vector<myset>& v) {
	int t = i;
	while (!v[t].isroot()) {
		if (t != i)v[t].rank -= v[i].rank;
		t = v[t].parent;
	}
	v[i].parent = t;
	return t;
}


void unite(int a, int b, vector<myset>& v) {
	int ar = findroot(a, v);
	int br = findroot(b, v);
	if (ar == br)return;
	if (v[ar].rank<v[br].rank) {
		v[ar].parent = br;
		v[br].rank = v[br].rank + v[ar].rank;
	}
	else {
		v[br].parent = ar;
		v[ar].rank = v[br].rank + v[ar].rank;
	}
	return;
}
/*find minimum spanning tree of an undirected graph with n nodes (1,...,n) and m edges*/
int main() {
	vector<edge> edgelist(m+1);
	vector<myset> nodes(n+1);
	sort(all(edgelist),compareedge);
	vlop(i,edgelist){
		if (findroot(edgelist[i].v1,nodes) != findroot(edgelist[i].v2,nodes)) unite(edgelist[i].v1, edgelist[i].v2, nodes);
	}
	return 0;
}
