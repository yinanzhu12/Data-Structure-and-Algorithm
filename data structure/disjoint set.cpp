#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std;

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